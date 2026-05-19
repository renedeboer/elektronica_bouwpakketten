# ACFS2 — Kat met Raket

Een kat die op een raket vliegt, met 25 animerende LEDs aangestuurd door een ATtiny85.

![acfs2-raket artwork](fotos/acfs2-raket_artwork.png)

![acfs2-raket PCB](fotos/acfs2-raket_pcb_leeg.jpg)


## Beschrijving

De PCB heeft de vorm van een raket met een kat erop. Met maar liefst 20 SMD LED's en 5 bidirectionele LEDs is dit de kit met de meeste LED's in de serie. De ATtiny85 stuurt alle LEDs via charlieplexing met een mood-gebaseerde animatie.

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | ATtiny85-20P | 1 |
| BT1 | CR2032 batterijhouder (SMTU2032-LF) | 1 |
| C1 | 100nF (0805 SMD) | 1 |
| D1–D20 | LED SMD | 20 |
| D21–D25 | Bidirectionele LED (through-hole) | 5 |
| R1–R5 | 100Ω–680Ω (MiniMELF MMA-0204) | 5 |
| SW1 | DIP-schakelaar 1-polig | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage en de [soldeertips](../../docs/solderen.md).

### Specifieke aandachtspunten

- Met 20 SMD LED's is dit de meest bewerkelijke kit uit de serie. Neem de tijd en controleer na iedere paar LED's de richting.
- De SMD LED's zitten dicht op elkaar; controleer na het solderen op tinbruggen.

## Schema

![angrycatsfromspace2 schema](schema/angrycatsfromspace2.svg)

KiCad projectbestanden: `~/Documents/KiCad/projects/angrycatsfromspace2/`

## Software

Firmware in ontwikkeling — zie [seriepagina](../README.md).

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat, als het na zijn levenscyclus wordt weggeworpen, dit toestel schade kan toebrengen aan het milieu. Gooi dit toestel (en eventuele batterijen) niet bij het gewone huishoudelijke afval; het moet bij een gespecialiseerd bedrijf terechtkomen voor recyclage. U dient dit toestel naar uw verdeler of naar een lokaal recyclagepunt te brengen. Respecteer de plaatselijke milieuwetgeving. Heeft u vragen, contacteer dan de plaatselijke autoriteiten inzake afvalverwijdering.

Producten mogen altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
