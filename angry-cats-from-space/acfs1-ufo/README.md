# ACFS1 — Kat in UFO

Een kat in een vliegende schotel met animerende LEDs, aangestuurd door een ATtiny85.

![acfs1-ufo artwork](fotos/acfs1-ufo_artwork.png)

![acfs1-ufo PCB](fotos/acfs1-ufo_pcb_leeg.jpg)


## Beschrijving

De PCB heeft de vorm van een UFO met een kat erin. De SMD LED's vormen de verlichting van de vliegende schotel; de bidirectionele LED's zorgen voor een kleurwisselend effect. De ATtiny85 stuurt alle 14 LED's via charlieplexing aan met een mood-gebaseerde animatie.

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | ATtiny85-20P | 1 |
| BT1 | CR2032 batterijhouder (SMTU2032-LF) | 1 |
| C1 | 100nF (0805 SMD) | 1 |
| D1–D8 | LED SMD | 8 |
| D9–D14 | Bidirectionele LED (through-hole) | 6 |
| R1–R5 | 100Ω–680Ω (MiniMELF MMA-0204) | 5 |
| SW1 | DIP-schakelaar 1-polig | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage en de [soldeertips](../../docs/solderen.md).

### Specifieke aandachtspunten

- De SMD LED's D1–D8 zitten aan de voorkant van de PCB. Let op de richtingsmarkering op de silkscreen.
- De bidirectionele LED's D9–D14 (dual-kleur) bepalen het kleureffect. Welke kleur brandt hangt af van de richting van de stroom; dit wisselt de software automatisch af.
- Monteer de bidirectionele LED's op gelijke hoogte voor een mooi resultaat.

## Schema

![angrycatsfromspace1 schema](schema/angrycatsfromspace1.svg)

De KiCad projectbestanden staan in de [KiCad projectenmap](../../) op het lokale systeem (`~/Documents/KiCad/projects/angrycatsfromspace1/`).

De Gerber bestanden voor PCB productie zijn beschikbaar in de `production/` map van het KiCad project.

## Software

Firmware in ontwikkeling — zie [seriepagina](../README.md) voor de huidige status en programmeernstructies.

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat, als het na zijn levenscyclus wordt weggeworpen, dit toestel schade kan toebrengen aan het milieu. Gooi dit toestel (en eventuele batterijen) niet bij het gewone huishoudelijke afval; het moet bij een gespecialiseerd bedrijf terechtkomen voor recyclage. U dient dit toestel naar uw verdeler of naar een lokaal recyclagepunt te brengen. Respecteer de plaatselijke milieuwetgeving. Heeft u vragen, contacteer dan de plaatselijke autoriteiten inzake afvalverwijdering.

Producten mogen altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
