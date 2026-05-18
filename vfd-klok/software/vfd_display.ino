#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int HC_A0 = 4;
const int HC_A1 = 3;
const int HC_A2 = 2;
const int SEG[7] = {5, 6, 7, 8, 9, 10, 11};
const int COLON  = 13;
const int MIC_PIN = A0;

// 7-segment patterns, 1=segment on
// bit6=A bit5=B bit4=C bit3=D bit2=E bit1=F bit0=G
const byte CHAR_TABLE[] = {
  0b1111110, // 0
  0b0110000, // 1
  0b1101101, // 2
  0b1111001, // 3
  0b0110011, // 4
  0b1011011, // 5
  0b1011111, // 6
  0b1110000, // 7
  0b1111111, // 8
  0b1111011, // 9 [index 9]
  0b0111101, // d [index 10]
  0b0011111, // b [index 11]
};
#define CHAR_d 10
#define CHAR_b 11

#define BLANK_ADDR 7
#define NUM_POS 5
const byte GRID_ADDR[NUM_POS] = {1, 2, 4, 5, 3};

#define TICKS_TOTAL 500
#define BRIGHTNESS  65
#define TICKS_ON    (TICKS_TOTAL * BRIGHTNESS / 100)
#define TICKS_BLANK (TICKS_TOTAL - TICKS_ON)

void selectGrid(byte addr) {
  digitalWrite(HC_A0, (addr >> 0) & 1);
  digitalWrite(HC_A1, (addr >> 1) & 1);
  digitalWrite(HC_A2, (addr >> 2) & 1);
}

volatile byte displayBuffer[4] = {0,0,0,0};
volatile bool colonOn  = false;
volatile byte muxPos   = 0;
volatile byte muxPhase = 0;

ISR(TIMER1_COMPA_vect) {
  if(muxPhase == 0) {
    OCR1A = TICKS_BLANK - 1;
    TCNT1 = 0;
    selectGrid(BLANK_ADDR);
    for(int i=0;i<7;i++) digitalWrite(SEG[i], HIGH);
    digitalWrite(COLON, HIGH);
    if(muxPos < 4) {
      byte pat = CHAR_TABLE[displayBuffer[muxPos]];
      for(int i=0;i<7;i++)
        digitalWrite(SEG[i], ((pat>>(6-i))&1) ? LOW : HIGH);
    } else {
      digitalWrite(COLON, colonOn ? LOW : HIGH);
    }
    muxPhase = 1;
  } else {
    OCR1A = TICKS_ON - 1;
    TCNT1 = 0;
    selectGrid(GRID_ADDR[muxPos]);
    muxPhase = 0;
    muxPos   = (muxPos + 1) % NUM_POS;
  }
}

void setupTimer() {
  TCCR1A = 0; TCCR1B = 0; TCNT1 = 0;
  OCR1A  = TICKS_BLANK - 1;
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1<<CS11)|(1<<CS10);
  TIMSK1 |= (1<<OCIE1A);
}

// ---- display modes ----
#define MODE_TIME 0
#define MODE_DB   1
byte displayMode = MODE_TIME;

// ---- RTC ----
bool rtcOk = false;
byte currentH = 0, currentM = 0;

void readRTC() {
  if(!rtcOk) return;
  DateTime t = rtc.now();
  currentH = t.hour();
  currentM = t.minute();
}

void showTime() {
  noInterrupts();
  displayBuffer[0] = currentH / 10;
  displayBuffer[1] = currentH % 10;
  displayBuffer[2] = currentM / 10;
  displayBuffer[3] = currentM % 10;
  colonOn = true;
  interrupts();
}

// ---- dB measurement ----
// Sample mic for 50ms, find peak-to-peak, map to 0-99 dB scale
byte measureDB() {
  unsigned long start = millis();
  int vmax = 0, vmin = 1023;
  while(millis() - start < 50) {
    int v = analogRead(MIC_PIN);
    if(v > vmax) vmax = v;
    if(v < vmin) vmin = v;
  }
  int peakToPeak = vmax - vmin;
  // Map: silence ~0-10, loud ~600-1023
  // Convert to 0-99 range with log scaling for natural dB feel
  if(peakToPeak < 4) return 0;
  // log scaling: dB = 20*log10(amplitude)
  // normalize to 0-99
  float db = 20.0 * log10((float)peakToPeak / 1023.0 * 100.0 + 1.0);
  db = constrain(db, 0, 99);
  return (byte)db;
}

void showDB(byte db) {
  noInterrupts();
  displayBuffer[0] = db / 10;   // tens digit
  displayBuffer[1] = db % 10;   // units digit
  displayBuffer[2] = CHAR_d;    // 'd'
  displayBuffer[3] = CHAR_b;    // 'b'
  colonOn = false;               // colon off in dB mode
  interrupts();
}

// ---- serial time set ----
void checkSerial() {
  if(Serial.available() >= 4) {
    char buf[5];
    for(int i=0;i<4;i++) buf[i]=Serial.read();
    buf[4]=0;
    while(Serial.available()) Serial.read();
    int h=(buf[0]-'0')*10+(buf[1]-'0');
    int m=(buf[2]-'0')*10+(buf[3]-'0');
    if(h>=0&&h<24&&m>=0&&m<60) {
      if(rtcOk) rtc.adjust(DateTime(2024,1,1,h,m,0));
      currentH=h; currentM=m;
      Serial.print("Time set to ");
      Serial.print(h); Serial.print(":");
      if(m<10) Serial.print("0");
      Serial.println(m);
    } else {
      Serial.println("Invalid - send HHMM e.g. 1345");
    }
  }
}

void setup() {
  for(int i=0;i<7;i++) { pinMode(SEG[i], OUTPUT); digitalWrite(SEG[i], HIGH); }
  pinMode(HC_A0, OUTPUT);
  pinMode(HC_A1, OUTPUT);
  pinMode(HC_A2, OUTPUT);
  selectGrid(BLANK_ADDR);
  pinMode(COLON, OUTPUT); digitalWrite(COLON, HIGH);
  pinMode(MIC_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("VFD Clock+dB - send HHMM to set time");

  Wire.begin();
  Wire.setClock(400000);
  rtcOk = rtc.begin();
  if(!rtcOk) Serial.println("RTC not found");
  if(rtcOk && !rtc.isrunning())
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  readRTC();
  showTime();
  setupTimer();
  sei();
}

// ---- timing ----
unsigned long modeStart   = 0;
unsigned long lastRTC     = 0;
unsigned long lastDB      = 0;
#define TIME_DURATION 30000UL  // 30 seconds
#define DB_DURATION   30000UL  // 30 seconds

void loop() {
  unsigned long now = millis();
  checkSerial();

  // RTC read every second
  if(now - lastRTC >= 1000) {
    lastRTC = now;
    readRTC();
  }

  // Mode switch every 30 seconds
  if(now - modeStart >= (displayMode == MODE_TIME ? TIME_DURATION : DB_DURATION)) {
    modeStart = now;
    displayMode = (displayMode == MODE_TIME) ? MODE_DB : MODE_TIME;
    Serial.println(displayMode == MODE_TIME ? ">> TIME" : ">> dB");
  }

  if(displayMode == MODE_TIME) {
    // Update colon blink every 500ms
    static unsigned long lastBlink = 0;
    if(now - lastBlink >= 500) {
      lastBlink = now;
      noInterrupts();
      colonOn = !colonOn;
      interrupts();
    }
    showTime();

  } else {
    // Sample dB every 100ms in dB mode
    if(now - lastDB >= 100) {
      lastDB = now;
      byte db = measureDB();
      showDB(db);
      Serial.print("dB: "); Serial.println(db);
    }
  }
}