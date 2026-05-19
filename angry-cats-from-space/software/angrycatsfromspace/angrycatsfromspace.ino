/*
  Project: angrycatsfromspace.ino
  Beschrijving: LED effecten voor de Angry Cats from Space serie (ATtiny85)
  Versie: 0.1

  Selecteer de variant door één #define actief te laten, de rest te commentariëren.
  Zet LEDTEST_MODE aan om alle charlie-posities 1-20 te doorlopen en te achterhalen
  welke positie bij welke LED hoort. Vul daarna ledMap[] in en zet LEDTEST_MODE uit.

  Author: René de Boer
  Date: 2026-05-19
*/

// ==================== Variant selectie ====================
// Zet één variant actief:

#define ACFS_1_UFO
// #define ACFS_2_RAKET
// #define ACFS_3_RUIMTEPAK
// #define ACFS_4_MAAN
// #define ACFS_5_SATURNUS

// ==================== LED test modus ====================
// Zet aan om alle charlie-posities 1-20 te doorlopen (1,5s aan, 0,4s uit).
// Gebruik dit om te bepalen welke D-nummers bij welke charlie-positie horen.
// Zet daarna uit en vul ledMap[] in.

// #define LEDTEST_MODE

// ==========================================================


// ------------------ Pin Setup ------------------
int P1 = 0;
int P2 = 1;
int P3 = 2;
int P4 = 3;
int P5 = 4;


// ------------------ Helpers ------------------
void high_Z_all() {
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(P4, INPUT);
  pinMode(P5, INPUT);
}


// ------------------ Charlieplexing ------------------
void charlieWrite(int x) {
  high_Z_all();
  switch(x) {
    case 0: break;
    case 1:  pinMode(P1, OUTPUT); digitalWrite(P1,HIGH); pinMode(P2, OUTPUT); break;
    case 2:  pinMode(P1, OUTPUT); digitalWrite(P1,HIGH); pinMode(P3, OUTPUT); break;
    case 3:  pinMode(P1, OUTPUT); digitalWrite(P1,HIGH); pinMode(P4, OUTPUT); break;
    case 4:  pinMode(P1, OUTPUT); digitalWrite(P1,HIGH); pinMode(P5, OUTPUT); break;
    case 5:  pinMode(P2, OUTPUT); digitalWrite(P2,HIGH); pinMode(P1, OUTPUT); break;
    case 6:  pinMode(P2, OUTPUT); digitalWrite(P2,HIGH); pinMode(P3, OUTPUT); break;
    case 7:  pinMode(P2, OUTPUT); digitalWrite(P2,HIGH); pinMode(P4, OUTPUT); break;
    case 8:  pinMode(P2, OUTPUT); digitalWrite(P2,HIGH); pinMode(P5, OUTPUT); break;
    case 9:  pinMode(P3, OUTPUT); digitalWrite(P3,HIGH); pinMode(P1, OUTPUT); break;
    case 10: pinMode(P3, OUTPUT); digitalWrite(P3,HIGH); pinMode(P2, OUTPUT); break;
    case 11: pinMode(P3, OUTPUT); digitalWrite(P3,HIGH); pinMode(P4, OUTPUT); break;
    case 12: pinMode(P3, OUTPUT); digitalWrite(P3,HIGH); pinMode(P5, OUTPUT); break;
    case 13: pinMode(P4, OUTPUT); digitalWrite(P4,HIGH); pinMode(P1, OUTPUT); break;
    case 14: pinMode(P4, OUTPUT); digitalWrite(P4,HIGH); pinMode(P2, OUTPUT); break;
    case 15: pinMode(P4, OUTPUT); digitalWrite(P4,HIGH); pinMode(P3, OUTPUT); break;
    case 16: pinMode(P4, OUTPUT); digitalWrite(P4,HIGH); pinMode(P5, OUTPUT); break;
    case 17: pinMode(P5, OUTPUT); digitalWrite(P5,HIGH); pinMode(P1, OUTPUT); break;
    case 18: pinMode(P5, OUTPUT); digitalWrite(P5,HIGH); pinMode(P2, OUTPUT); break;
    case 19: pinMode(P5, OUTPUT); digitalWrite(P5,HIGH); pinMode(P3, OUTPUT); break;
    case 20: pinMode(P5, OUTPUT); digitalWrite(P5,HIGH); pinMode(P4, OUTPUT); break;
  }
}


// ------------------ Multiplexing ------------------
void multiplexLEDs(int leds[], int count, int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    for (int i = 0; i < count; i++) {
      charlieWrite(ledMap[leds[i]]);
      delay(5);
    }
  }
}

void ledOnSingle(int led, int time_ms) {
  charlieWrite(ledMap[led]);
  delay(time_ms);
  charlieWrite(0);
}


// ==================== ACFS 1 — UFO ====================
#ifdef ACFS_1_UFO

const int LED_COUNT = 12;

// TODO: vul in na ledtest — D-nummer → charlie positie
int ledMap[21] = {
   0,  // dummy index 0
   0,  // D1
   0,  // D2
   0,  // D3
   0,  // D4
   0,  // D5
   0,  // D6
   0,  // D7
   0,  // D8
   0,  // D9
   0,  // D10 (niet gebruikt)
   0,  // D11 (niet gebruikt)
   0,  // D12
   0,  // D13
   0,  // D14
   0,  // D15 (niet gebruikt)
   0,  // D16 (niet gebruikt)
   0,  // D17 (niet gebruikt)
   0,  // D18 (niet gebruikt)
   0,  // D19 (niet gebruikt)
   0   // D20 (niet gebruikt)
};

// LED groepen op fysieke positie
int rand_leds[]   = {1, 2, 3, 4, 5, 6, 7, 8};   // rand van de UFO
int koepel_leds[] = {9, 12, 13, 14};              // koepel bovenop

void animatie() {
  // TODO: animatie invullen na beschrijving van René
}

#endif // ACFS_1_UFO


// ==================== ACFS 2 — Raket ====================
#ifdef ACFS_2_RAKET

const int LED_COUNT = 20;

// TODO: vul in na ledtest
int ledMap[21] = {
   0,  // dummy index 0
   0,  // D1
   0,  // D2
   0,  // D3
   0,  // D4
   0,  // D5
   0,  // D6
   0,  // D7
   0,  // D8
   0,  // D9
   0,  // D10
   0,  // D11
   0,  // D12
   0,  // D13
   0,  // D14
   0,  // D15
   0,  // D16
   0,  // D17
   0,  // D18
   0,  // D19
   0   // D20
};

// LED groepen op fysieke positie
// TODO: groepen invullen na analyse schema + artwork
int neus_leds[]   = {};  // TODO
int raam_leds[]   = {};  // TODO
int lichaam_leds[]= {};  // TODO
int vleugel_leds[]= {};  // TODO
int vuur_leds[]   = {};  // TODO

void animatie() {
  // TODO: animatie invullen na beschrijving van René
}

#endif // ACFS_2_RAKET


// ==================== ACFS 3 — Ruimtepak ====================
#ifdef ACFS_3_RUIMTEPAK

const int LED_COUNT = 8;

// TODO: vul in na ledtest
int ledMap[21] = {
   0,  // dummy index 0
   0,  // D1  (niet gebruikt)
   0,  // D2  (niet gebruikt)
   0,  // D3  (niet gebruikt)
   0,  // D4  (niet gebruikt)
   0,  // D5  (niet gebruikt)
   0,  // D6  (niet gebruikt)
   0,  // D7  (niet gebruikt)
   0,  // D8  (niet gebruikt)
   0,  // D9
   0,  // D10 (niet gebruikt)
   0,  // D11 (niet gebruikt)
   0,  // D12
   0,  // D13
   0,  // D14
   0,  // D15
   0,  // D16
   0,  // D17
   0,  // D18
   0,  // D19 (niet gebruikt)
   0   // D20 (niet gebruikt)
};

// LED groepen op fysieke positie
int helm_leds[]  = {9};              // helm (5mm LED)
int borst_leds[] = {12, 13, 14};    // borst
int arm_leds[]   = {15, 16};        // armen
int been_leds[]  = {17, 18};        // benen

void animatie() {
  // TODO: animatie invullen na beschrijving van René
}

#endif // ACFS_3_RUIMTEPAK


// ==================== ACFS 4 — Maan ====================
#ifdef ACFS_4_MAAN

const int LED_COUNT = 12;

// TODO: vul in na ledtest
int ledMap[21] = {
   0,  // dummy index 0
   0,  // D1
   0,  // D2
   0,  // D3
   0,  // D4
   0,  // D5
   0,  // D6
   0,  // D7
   0,  // D8
   0,  // D9
   0,  // D10 (niet gebruikt)
   0,  // D11 (niet gebruikt)
   0,  // D12
   0,  // D13
   0,  // D14
   0,  // D15 (niet gebruikt)
   0,  // D16 (niet gebruikt)
   0,  // D17 (niet gebruikt)
   0,  // D18 (niet gebruikt)
   0,  // D19 (niet gebruikt)
   0   // D20 (niet gebruikt)
};

// LED groepen op fysieke positie
int krater_leds[] = {1, 2, 3, 4, 5, 6, 7, 8};   // kraters op de maan
int accent_leds[] = {9, 12, 13, 14};              // accent LEDs

void animatie() {
  // TODO: animatie invullen na beschrijving van René
}

#endif // ACFS_4_MAAN


// ==================== ACFS 5 — Saturnus ====================
#ifdef ACFS_5_SATURNUS

const int LED_COUNT = 12;

// TODO: vul in na ledtest
int ledMap[21] = {
   0,  // dummy index 0
   0,  // D1
   0,  // D2
   0,  // D3
   0,  // D4
   0,  // D5
   0,  // D6
   0,  // D7
   0,  // D8
   0,  // D9
   0,  // D10 (niet gebruikt)
   0,  // D11 (niet gebruikt)
   0,  // D12
   0,  // D13
   0,  // D14
   0,  // D15 (niet gebruikt)
   0,  // D16 (niet gebruikt)
   0,  // D17 (niet gebruikt)
   0,  // D18 (niet gebruikt)
   0,  // D19 (niet gebruikt)
   0   // D20 (niet gebruikt)
};

// LED groepen op fysieke positie
int planeet_leds[] = {1, 2, 3, 4, 5, 6, 7, 8};  // planeet
int ring_leds[]    = {9, 12, 13, 14};             // ring om de planeet

void animatie() {
  // TODO: animatie invullen na beschrijving van René
}

#endif // ACFS_5_SATURNUS


// ==================== Setup & Loop ====================
void setup() {
  randomSeed(analogRead(0));
  high_Z_all();
}

void loop() {
#ifdef LEDTEST_MODE
  // Doorloop alle 20 charlie-posities één voor één.
  // Noteer welk D-nummer oplicht bij elke positie en vul ledMap[] in.
  for (int pos = 1; pos <= 20; pos++) {
    charlieWrite(pos);
    delay(1500);
    charlieWrite(0);
    delay(400);
  }
#else
  animatie();
#endif
}
