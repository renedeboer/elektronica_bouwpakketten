# ACFS4 — Kat op de Maan

Een kat die op de maan zit, met animerende LEDs aangestuurd door een ATtiny85.

![acfs4-maan artwork](fotos/acfs4-maan_artwork.png)

![acfs4-maan PCB](fotos/acfs4-maan_pcb_leeg.jpg)


## Beschrijving

De PCB stelt een kat voor die op de maan zit met de aarde op de achtergrond. De combinatie van SMD en bidirectionele through-hole LED's zorgt voor een sfeervolle verlichting.

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | ATtiny85-20P | 1 |
| BT1 | CR2032 batterijhouder (SMTU2032-LF) | 1 |
| C1 | 100nF (0805 SMD) | 1 |
| D1–D8 | LED SMD | 8 |
| D10–D14 | Bidirectionele LED 3mm (through-hole) | 5 |
| D9 | Bidirectionele LED 5mm (through-hole) | 1 |
| R1–R5 | 100Ω–680Ω (MiniMELF MMA-0204) | 5 |
| SW1 | DIP-schakelaar 1-polig | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage en de [soldeertips](../../docs/solderen.md).

## Schema

![angrycatsfromspace4 schema](schema/angrycatsfromspace4.svg)

KiCad projectbestanden: `~/Documents/KiCad/projects/angrycatsfromspace4/`

## Software

Firmware in ontwikkeling — zie [seriepagina](../README.md).

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat, als het na zijn levenscyclus wordt weggeworpen, dit toestel schade kan toebrengen aan het milieu. Gooi dit toestel (en eventuele batterijen) niet bij het gewone huishoudelijke afval; het moet bij een gespecialiseerd bedrijf terechtkomen voor recyclage. U dient dit toestel naar uw verdeler of naar een lokaal recyclagepunt te brengen. Respecteer de plaatselijke milieuwetgeving. Heeft u vragen, contacteer dan de plaatselijke autoriteiten inzake afvalverwijdering.

Producten mogen altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
