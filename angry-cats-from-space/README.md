<img src="../images/logo.svg" align="right" width="72">

# Angry Cats From Space

Een reeks van vijf decoratieve LED-bouwpakketten met katten in de ruimte als thema. Elk bouwpakket is een andere kat in een andere ruimtesituatie.

## Hoe het werkt

Alle vijf bouwpakketten zijn gebaseerd op dezelfde elektronica:

- **ATtiny85** microcontroller — het brein van de kit
- **Charlieplexing** — techniek om veel LEDs aan te sturen met slechts 5 pinnen
- **2× AA of AAA batterijen** — via batterijhouder op de PCB
- **DIP-schakelaar** — voor het aanpassen van het gedrag (in ontwikkeling)

De ATtiny85 stuurt de LEDs aan via een mood-systeem: het apparaatje gedraagt zich rustig, speels of eng, en wisselt daar willekeurig tussen. De LED-effecten zijn afgeleid van het [Vleermuis bouwpakket](https://github.com/renedeboer/ReneDeBoer_Vleermuis).

## Software

De ATtiny85 firmware per variant is nog in ontwikkeling. De basis-library voor charlieplexing en de mood-effecten is te vinden in het [Vleermuis project](https://github.com/renedeboer/ReneDeBoer_Vleermuis).

### ATtiny85 programmeren

De ATtiny85 wordt geprogrammeerd via ISP met een Arduino als programmer:

1. Sluit de Arduino aan als ISP (`File > Examples > ArduinoISP`)
2. Installeer ATtiny85 board support in de Arduino IDE (bijv. [MicroCore](https://github.com/MCUdude/MicroCore))
3. Selecteer: Board = `ATtiny85`, Clock = `1 MHz (internal)`, Programmer = `Arduino as ISP`
4. Upload de firmware

> De ATtiny85 in de kit zit in een DIP-socket en kan er eenvoudig uit worden gehaald voor programmering.

## De vijf bouwpakketten

| Kit | Thema | LEDs |
|-----|-------|------|
| [ACFS1 — Kat in UFO](acfs1-ufo/) | Kat in een vliegende schotel | 14 |
| [ACFS2 — Kat met Raket](acfs2-raket/) | Kat op een raket | 25 |
| [ACFS3 — Kat in Ruimtepak](acfs3-ruimtepak/) | Kat in ruimtepak | 14 |
| [ACFS4 — Kat op de Maan](acfs4-maan/) | Kat op de maan | 14 |
| [ACFS5 — Kat bij Saturnus](acfs5-saturnus/) | Kat bij de planeet Saturnus | 14 |

## Stuklijst (geldt voor alle 5 varianten)

| Aanduiding | Waarde / Type | Aantal | Opmerking |
|------------|--------------|--------|-----------|
| U1 | ATtiny85-20P | 1 | DIP-8, in socket gemonteerd |
| BT1 | CR2032 batterijhouder | 1 | SMD, Renata SMTU2032-LF |
| C1 | 100nF | 1 | SMD 0805 |
| D1–D8 | LED | 8 | SMD, kleur naar keuze |
| D9–D14 | Bidirectionele LED | 6 | Through-hole, dual kleur |
| R1–R5 | 100Ω–680Ω* | 5 | MiniMELF (MMA-0204) |
| SW1 | DIP-schakelaar 1-polig | 1 | JS202011SCQN |

> *De exacte weerstandswaarden zijn afhankelijk van de LED kleur en het gewenste effect. Zie de stuklijst per variant.

## Bouwinstructies

Zie [Soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Volgorde van montage

1. SMD condensator C1 (100nF, 0805)
2. SMD weerstanden R1–R5 (MiniMELF)
3. SMD LED's D1–D8 — **let op polariteit en richting op de silkscreen**
4. DIP-8 socket voor U1
5. Bidirectionele LED's D9–D14 — hoogte bepaalt het uiterlijk, pas aan naar smaak
6. DIP-schakelaar SW1
7. CR2032 batterijhouder BT1
8. ATtiny85 in de socket plaatsen (inkeping op chip = inkeping op socket)
9. Batterij plaatsen
