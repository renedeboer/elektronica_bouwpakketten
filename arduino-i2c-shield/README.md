# Arduino I2C Shield met P82B715P

Een Arduino Uno shield met een P82B715P I2C bus extender voor het aansturen van I2C apparaten over langere kabelafstanden.

<!-- foto: afgewerkt prototype (beide PCBs) -->
<!-- foto: shield gemonteerd op Arduino Uno -->
<!-- foto: naakte PCBs bovenkant -->

## Beschrijving

Standaard I2C (400pF buslimiet) werkt goed over korte afstanden op een printplaat. Zodra de kabel langer wordt — naar een display, sensor of ander apparaat buiten de behuizing — neemt de capaciteit toe en wordt de communicatie onbetrouwbaar.

De **P82B715P** van NXP is een I2C bus buffer die de signaalniveaus omzet zodat langere kabels (tot enkele meters) mogelijk worden, zonder dat de I2C logica of het adres gewijzigd hoeft te worden.

Dit bouwpakket bestaat uit **twee PCBs**:

1. **Arduino Uno Shield** (`unoshield`) — steekt op de Arduino Uno, bevat de P82B715P chip en de connector naar de verlengde I2C bus
2. **Remote I2C board** (`P82B715P`) — aan het einde van de kabel, sluit aan op het I2C apparaat

## Schema

**Arduino Uno Shield:**
![Uno Shield schema](schema/uno-shield.svg)

**Remote I2C board (P82B715P):**
![P82B715P schema](schema/P82B715P.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/arduino-i2c-shield/bom/ibom.html)

## Stuklijst

### Arduino Uno Shield

<!-- stuklijst volgt na verificatie -->

### Remote I2C board (P82B715P)

<!-- stuklijst volgt na verificatie -->

## Aansluitingen

| Pin | Functie |
|-----|---------|
| SDA (near side) | I2C data — Arduino kant |
| SCL (near side) | I2C klok — Arduino kant |
| SDA (far side) | I2C data — verlengde kant |
| SCL (far side) | I2C klok — verlengde kant |

De P82B715P werkt bidirectioneel — de "near" en "far" kant kunnen worden omgekeerd zonder aanpassingen.

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Specifieke aandachtspunten

- De shield past standaard op een Arduino Uno R3. Controleer de pinlengte van de headers zodat ze goed in de Uno-connectoren passen (gebruik "stackable headers" voor het beste resultaat).
- De P82B715P heeft een Vcc van 3,3V of 5V; zorg dat dit overeenkomt met de spanning van de aangesloten I2C apparaten en de Arduino.

## KiCad bestanden

Projectbestanden:
- Shield: `~/Documents/KiCad/projects/unoshield/`
- Remote board: `~/Documents/KiCad/projects/P82B715P/`
