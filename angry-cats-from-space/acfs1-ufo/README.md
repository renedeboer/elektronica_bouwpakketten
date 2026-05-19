<img src="../../images/logo.svg" align="right" width="72">

# ACFS1 — Kat in UFO

Een kat in een vliegende schotel met 12 animerende LEDs, aangestuurd door een ATtiny85.

| | |
|---|---|
| ![Artwork](fotos/acfs1-ufo_artwork.png) | ![Lege PCB](fotos/acfs1-ufo_pcb_leeg.jpg) |
| *Artwork* | *Lege PCB* |


## Beschrijving

De PCB heeft de vorm van een UFO met een kat erin. De LED's vormen de verlichting van de vliegende schotel; de bidirectionele LED's zorgen voor een kleurwisselend effect. De ATtiny85 stuurt alle 12 LED's via charlieplexing aan met een mood-gebaseerde animatie.

## Stuklijst

| Aanduiding | Waarde / Type | Aantal |
|------------|--------------|--------|
| U1 | ATtiny85-20P | 1 |
| BT1, BT2 | AA of AAA batterijhouder | 2 |
| C1 | 100nF | 1 |
| D1–D8 | LED 3mm | 8 |
| D9, D12–D14 | Bidirectionele LED 3mm | 4 |
| R1–R5 | 100Ω–680Ω* | 5 |
| SW1 | DIP-schakelaar 1-polig | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage en de [soldeertips](../../docs/solderen.md).

### Specifieke aandachtspunten

- De LED's D1–D8 zitten aan de voorkant van de PCB. Let op de polariteit (richtingsmarkering op de silkscreen).
- De bidirectionele LED's D9, D12–D14 (dual-kleur) bepalen het kleureffect. Welke kleur brandt hangt af van de stroomrichting; dit wisselt de software automatisch af.
- Monteer de bidirectionele LED's op gelijke hoogte voor een mooi resultaat.
- Let op de richtingsmarkering voor D1–D8 op de silkscreen.

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
