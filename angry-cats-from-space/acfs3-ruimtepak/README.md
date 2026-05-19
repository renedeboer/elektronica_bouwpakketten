<img src="../../images/logo.svg" align="right" width="72">

# ACFS3 — Kat in Ruimtepak

Een kat in een ruimtepak, met animerende LEDs aangestuurd door een ATtiny85.

![acfs3-ruimtepak artwork](fotos/acfs3-ruimtepak_artwork.png)

![acfs3-ruimtepak PCB](fotos/acfs3-ruimtepak_pcb_leeg.jpg)


## Beschrijving

De PCB heeft de vorm van een kat in een ruimtepak. De combinatie van 3mm en 5mm bidirectionele LED's geeft het ontwerp diepte en kleurvariatie.

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | ATtiny85-20P | 1 |
| BT1, BT2 | AA of AAA batterijhouder | 2 |
| C1 | 100nF | 1 |
| D12–D18 | Bidirectionele LED 3mm | 7 |
| D9 | Bidirectionele LED 5mm | 1 |
| R1–R5 | 100Ω–680Ω* | 5 |
| SW1 | DIP-schakelaar 1-polig | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage en de [soldeertips](../../docs/solderen.md).

### Specifieke aandachtspunten

- D9 is een 5mm bidirectionele LED en vormt het accent (bijv. hoofd of borststuk). Monteer deze als laatste zodat je de hoogte goed kunt bepalen.
- D12–D18 zijn 3mm bidirectionele LED's — soldeer ze op gelijke hoogte voor een uniform uiterlijk.

## Schema

![angrycatsfromspace3 schema](schema/angrycatsfromspace3.svg)

KiCad projectbestanden: `~/Documents/KiCad/projects/angrycatsfromspace3/`

## Software

Firmware in ontwikkeling — zie [seriepagina](../README.md).

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat, als het na zijn levenscyclus wordt weggeworpen, dit toestel schade kan toebrengen aan het milieu. Gooi dit toestel (en eventuele batterijen) niet bij het gewone huishoudelijke afval; het moet bij een gespecialiseerd bedrijf terechtkomen voor recyclage. U dient dit toestel naar uw verdeler of naar een lokaal recyclagepunt te brengen. Respecteer de plaatselijke milieuwetgeving. Heeft u vragen, contacteer dan de plaatselijke autoriteiten inzake afvalverwijdering.

Producten mogen altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
