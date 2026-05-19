# Phono Voorversterker (RIAA)

Een actieve RIAA phono voorversterker voor het aansluiten van een platenspeler met MM (Moving Magnet) element op een versterker zonder phono-ingang.

| | |
|---|---|
| ![Lege PCB](fotos/phono_pcb_leeg.jpg) | ![Bestukte PCB](fotos/phono_pcb_bestukt.jpg) |
| *Lege PCB* | *Bestukt prototype — stereo, twee kanalen* |

## Beschrijving

Een platenspeler met een MM element heeft twee dingen nodig om correct te klinken:

1. **Versterking** — het signaal van een platenspelerelement is erg zwak (enkele millivolts)
2. **RIAA equalisatie** — bij het persen van een plaat worden de hoge frequenties versterkt en de lage frequenties gedempt opgeslagen. Bij het afspelen moet dit precies omgekeerd worden.

Deze voorversterker doet beide: versterking én RIAA equalisatie, via een **OPA606** FET-ingang op-amp. De schakeling is gebaseerd op een toepassingscircuit van **Walter G. Jung** uit de OPA606 datasheet.

Het bouwpakket is **stereo** (twee identieke kanalen op één PCB) en heeft een voedingsaansluiting voor de op-amps.

## Schema

![Phono Voorversterker schema](schema/passivephono.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/passieve-phono/bom/ibom.html)

## Stuklijst

<!-- stuklijst volgt na verificatie van het schema -->

## Aansluitingen

| Connector | Functie |
|-----------|---------|
| Ingang L/R | Van de platenspeler (RCA) |
| Uitgang L/R | Naar de versterker lijningang (RCA) |
| Voeding | Symmetrische voeding voor de op-amps |
| Massa/aarde | Aardedraad platenspeler aansluiten |

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Specifieke aandachtspunten

- Zorg voor goede afscherming van de aansluitkabels — een platenspelersignaal is erg zwak en gevoelig voor brom en storing.
- De aardedraad van de platenspeler (apart van de signaalkabel) aansluiten op de massapin.
- Beide kanalen zijn identiek — controleer bij problemen of de componentwaarden per kanaal overeenkomen.

## Bronvermelding

De schakeling is afkomstig uit de **OPA606 datasheet (Burr-Brown / Texas Instruments)**, waar hij wordt toegeschreven aan **Walter G. Jung**.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/passivephono/`
