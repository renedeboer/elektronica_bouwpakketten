# VFD Klok

Een klok met een vacuüm fluorescentie display (VFD), aangestuurd door een Arduino Nano met RTC module en temperatuur-/drukmeting.

<!-- foto: afgewerkt prototype (display aan, klok zichtbaar) -->
<!-- foto: naakte PCB bovenkant -->
<!-- foto: PCB onderkant / soldeerwerk -->
<!-- foto: detail van het VFD display -->

## Beschrijving

Een VFD (Vacuum Fluorescent Display) is een oudere maar prachtige displaytechnologie — helder blauw-groen, met een retro uitstraling. Dit bouwpakket bouwt een volledige klok rondom zo'n display.

### Functies

- Tijdsweergave (uren, minuten) via DS1307 RTC module
- Temperatuur- en luchtdrukweergave via BMP280 sensor
- Relais voor het schakelen van een extern apparaat (bijv. lamp aan/uit op tijdstip)
- Dimbare display (PWM via Arduino)
- Microfooningang voor geluidsgevoeligheid (optioneel)
- Voeding rechtstreeks op 230V wisselspanning

### Hoe het werkt

Het VFD display heeft 5 posities (4 cijfers + dubbele punt). Elk positie wordt aangestuurd via een **74HC238** decoder en twee **ULN2801A** darlington arrays. De Arduino Nano multiplext de posities snel achter elkaar — zo snel dat het oog het niet ziet.

De **DS1307** RTC module houdt de tijd bij, ook als de stroom uitvalt (met een CR2032 backup batterij op de module). De **BMP280** meet temperatuur en luchtdruk via I2C.

De 230V wisselspanning wordt omgezet naar 5V door een **IRM-03-5** AC/DC module, en naar 15V voor het VFD door een **MEE1S0515SC** DC/DC converter.

## Schema

<!-- foto of export van het schema -->

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| A1 | Arduino Nano v3 | 1 |
| U1, U3 | ULN2801A darlington array (DIP-18) | 2 |
| U2 | 74HC238 3-naar-8 decoder (DIP-16) | 1 |
| PS1 | MEE1S0515SC DC/DC converter | 1 |
| PS2 | IRM-03-5 AC/DC converter | 1 |
| K1 | Fujitsu FTR-LYCA005x relais | 1 |
| Q1 | NPN transistor (TO-92) | 1 |
| D1 | Diode (DO-41) | 1 |
| D2 | LED 5mm horizontaal | 1 |
| F1 | Zekering + houder (TR5 Littelfuse) | 1 |
| J1 | 4-pins header voor BMP280 module | 1 |
| J2 | 5-pins JST-EH voor DS1307 module | 1 |
| J3 | 18-pins VFD display connector | 1 |
| J4 | 4-pins Molex KK-396 (230V / relaisuitgang) | 1 |
| J5 | 8-pins JST-EH analoog ingang | 1 |
| C1 | Condensator (C_Rect P5mm) | 1 |
| C2, C3 | Elektrolytische condensator axiaal | 2 |
| C4 | Schijfcondensator 9mm | 1 |
| R1–R4 | 50Ω | 4 |
| R5–R20 | 10kΩ | 16 |
| R21–R24 | 1kΩ | 4 |

## Software

De Arduino broncode staat in de [software map](software/):

- `vfd_display.ino` — hoofdprogramma

### Bibliotheken

- `Wire.h` — I2C communicatie (standaard)
- `RTClib.h` — Adafruit RTC library voor DS1307

### Uploaden

1. Installeer de Arduino IDE
2. Installeer de `RTClib` library via de Library Manager
3. Sluit de Arduino Nano aan via USB
4. Selecteer: Board = `Arduino Nano`, Processor = `ATmega328P`
5. Upload `vfd_display.ino`

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### WAARSCHUWING — 230V wisselspanning

Dit bouwpakket werkt op **230V wisselspanning**. Neem de volgende voorzorgsmaatregelen:

- **Werk nooit aan de 230V bedrading als de stekker in het stopcontact zit**
- Zorg dat alle 230V aansluitingen goed geïsoleerd zijn in een passende behuizing
- De zekering F1 beschermt het circuit — vervang uitsluitend met de opgegeven waarde
- Laat kinderen nooit onbegeleid met dit bouwpakket werken

### Volgorde van montage

1. SMD onderdelen (indien aanwezig)
2. Weerstanden R1–R24
3. Condensatoren C1–C4 (let op polariteit C2, C3)
4. Diode D1 (let op richting)
5. Transistor Q1 (let op vlakke kant)
6. IC-sockets voor U1, U2, U3
7. LED D2
8. Zekeringhouder F1
9. Relais K1
10. DC/DC converter PS1
11. AC/DC converter PS2
12. Connectors J1–J5
13. VFD display connector J3
14. IC's in de sockets plaatsen
15. Arduino Nano op headers
16. Modules (DS1307, BMP280) aansluiten

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/vfd/`
