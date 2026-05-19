# ZX Spectrum I2C Uitbreidingskaart

Een uitbreidingskaart voor de **ZX Spectrum 48K** die I2C communicatie mogelijk maakt via de edge connector. Inclusief ZX BASIC software bibliotheek voor het aansturen van displays en I2C apparaten.

<!-- foto: PCB voorkant -->
<!-- foto: PCB op ZX Spectrum aangesloten -->
<!-- foto: werkend met OLED of LCD display -->

## Beschrijving

De ZX Spectrum heeft van huis uit geen I2C bus. Deze uitbreidingskaart voegt I2C toe via de **PCF8584** I2C bus controller, die op het ZX Spectrum busadres wordt aangesloten. Zo zijn alle moderne I2C sensoren, displays en modules te gebruiken vanuit ZX BASIC.

### Functies

- I2C bus via **PCF8584** controller (eigen klokgenerator, onafhankelijk van de Z80)
- 8-bit I/O expander via **PCF8574P**
- Aansluiting voor **0,91" OLED display** (I2C)
- Aansluiting voor **HDSP-4850** 4-karakter alfanumeriek LED display
- Adresbepaling via **74LS138** decoder
- Busbuffering via **74LS240** en **4049**
- DIP-schakelaar voor I2C adresselectie
- Sluit aan op de **ZX Spectrum 48K edge connector**

### Hoe het werkt

De PCF8584 verschijnt als een geheugenadres in de ZX Spectrum adresruimte. Via `IN`/`OUT` instructies in machinecode — aangeroepen vanuit BASIC — kan de Z80 I2C berichten versturen en ontvangen. De PCF8584 regelt zelf de I2C timing en protocollen.

## Oscilloscoopmetingen

Tijdens ontwikkeling zijn de I2C signalen gemeten om correcte werking te verifiëren.

| | |
|---|---|
| ![Klokgenerator PCF8584](fotos/zxi2c_oscilloscoop_klok.jpg) | ![I2C startconditie](fotos/zxi2c_oscilloscoop_i2c_start.jpg) |
| *Klokgenerator PCF8584 (~50ns/div)* | *I2C startconditie en SCL pulsen (1ms/div)* |
| ![I2C datatransfer](fotos/zxi2c_oscilloscoop_i2c_data.jpg) | ![I2C signaal detail](fotos/zxi2c_oscilloscoop_i2c_signaal.jpg) |
| *I2C datatransfer met ACK (1ms/div)* | *I2C SDA en SCL detail (500µs/div)* |

## Schema

![ZX Spectrum I2C schema](schema/zxi2c.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/zx-spectrum-i2c/bom/ibom.html)

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | PCF8584 I2C bus controller (DIP) | 1 |
| U2 | PCF8574P I2C I/O expander (DIP) | 1 |
| U3 | 74LS138 3-naar-8 decoder (DIP) | 1 |
| U4 | 74LS240 octal buffer (DIP) | 1 |
| U5 | 4049 hex inverter (DIP) | 1 |
| Y1 | Kristal (voor PCF8584 klok) | 1 |
| J1 | ZX Spectrum 48K edge connector | 1 |
| J2 | OLED display connector (I2C) | 1 |
| J3 | HDSP-4850 display connector | 1 |
| J4, J5 | Uitbreidingsconnectoren | 2 |
| SW1 | DIP-schakelaar 2-polig (adresselectie) | 1 |
| D1, D2 | 1N914 signaaldiode | 2 |
| C1–C9 | Diverse condensatoren (100nF, 22pF, 15µF, 1nF) | 9 |
| R1–R19 | Diverse weerstanden (10kΩ, 900Ω, 1MΩ) | 19 |

## Software

De ZX BASIC software staat in de [software map](software/). Bronbestanden (`.txt`) worden gecompileerd naar tapefile (`.tap`) met [zmakebas](https://github.com/z00m128/zmakebas).

### Bestanden

| Bestand | Inhoud |
|---------|--------|
| `i2clib.txt` / `.tap` | I2C basisbibliotheek — PCF8584 initialisatie en byte-verzending |
| `i2clcd.txt` / `.tap` | LCD aansturing via PCF8574T → HD44780 (I2C backpack) |
| `i2cOled.txt` / `.tap` | OLED display aansturing (0,91") |
| `i2cscan.txt` / `.tap` | I2C bus scanner — zoekt alle aangesloten apparaten |
| `i2cdiag.txt` / `.tap` | Diagnose en testprogramma |
| `lcdtest.txt` / `.tap` | LCD testprogramma |
| `i2clcd_hello_world.txt` | Minimaal LCD Hello World voorbeeld |
| `i2clib_with_labels.txt` | Bibliotheek met benoemde BASIC-labels |

### Compileren en laden

De `.txt` bronbestanden zijn ZX BASIC in platte tekst, gecompileerd met `zmakebas`:

```bash
cd software
zmakebas -l -a @start -o i2clib.tap i2clib.txt
```

De `.tap` bestanden worden geladen op een echte ZX Spectrum of emulator (bijv. [Fuse](http://fuse-emulator.sourceforge.net/)):

```
LOAD ""
```

### Architectuur van i2clib

De bibliotheek combineert ZX BASIC met een ingebedde machinecode routine:

- **BASIC deel** — initialisatie, LCD-commando's, cursor positionering, stringweergave
- **Machinecode deel** (48 bytes op adres 64900) — polls de PCF8584 PIN-bit na elk byte, geen vertraging nodig
- **Sendbuffer** (op adres 64948) — `[aantal_bytes] [byte0..byteN]`

I2C apparaatadres is instelbaar via de DIP-schakelaar op de kaart.

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Specifieke aandachtspunten

- De **edge connector** voor de ZX Spectrum heeft een specifieke rasterafstand (3,96mm) — gebruik de juiste connector.
- De **PCF8584** heeft een externe klok nodig (kristal + 22pF condensatoren). Zorg dat het kristal goed gesoldeerd is voor betrouwbare I2C timing.
- De **74LS240** en **4049** bufferen de ZX bus signalen — gebruik uitsluitend LS-serie of HCT-serie voor compatibiliteit met de 5V ZX Spectrum bus.
- Controleer het I2C adres van je display en stel de DIP-schakelaar dienovereenkomstig in.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/zxi2c/`
