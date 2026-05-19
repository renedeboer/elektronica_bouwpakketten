# ACFS3 — Kat in Ruimtepak

Een kat in een ruimtepak, met animerende LEDs aangestuurd door een ATtiny85.

![acfs3-ruimtepak artwork](fotos/acfs3-ruimtepak_artwork.png)

![acfs3-ruimtepak PCB](fotos/acfs3-ruimtepak_pcb_leeg.jpg)


## Beschrijving

De PCB heeft de vorm van een kat in een ruimtepak. De combinatie van SMD LED's en door-hole bidirectionele LED's (zowel 3mm als 5mm) geeft het ontwerp diepte en kleurvariatie.

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

### Specifieke aandachtspunten

- D9 is een 5mm bidirectionele LED en vormt het accent (bijv. hoofd of borststuk). Monteer deze als laatste zodat je de hoogte goed kunt bepalen.
- D10–D14 zijn 3mm bidirectionele LED's — soldeer ze op gelijke hoogte voor een uniform uiterlijk.

## Schema

![angrycatsfromspace3 schema](schema/angrycatsfromspace3.svg)

KiCad projectbestanden: `~/Documents/KiCad/projects/angrycatsfromspace3/`

## Software

Firmware in ontwikkeling — zie [seriepagina](../README.md).
