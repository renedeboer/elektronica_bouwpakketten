# Politielicht

Een afwisselend rood/blauw zwaailicht effect met 12 LED's, twee transistoren en een 4017 counter.

| | |
|---|---|
| ![Lege PCB](fotos/politielicht_pcb_leeg.jpg) | ![Bestukte PCB](fotos/politielicht_pcb_bestukt.jpg) |
| *Lege PCB* | *Bestukt prototype* |

## In werking

![Politielicht animatie](fotos/politielicht.gif)

## Beschrijving

De NE555 genereert pulsen voor de CD4017 decade counter. De 4017 verdeelt de LED's over twee groepen (rood en blauw) via twee BC547 transistoren. Het resultaat is een overtuigend politie-zwaailicht effect.

## Schema

![555 Politielicht schema](schema/555police.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/555-en-4017/politielicht/bom/ibom.html)

## Stuklijst

| Aanduiding | Waarde | Aantal |
|------------|--------|--------|
| U1 | NE555P (DIP-8) | 1 |
| U2 | CD4017 decade counter (DIP-16) | 1 |
| Q1, Q2 | BC547 NPN transistor | 2 |
| C1 | 100µF / 10V elektrolytisch | 1 |
| R1 | 22kΩ | 1 |
| R2 | 1kΩ | 1 |
| R3–R14 (LED weerstanden) | 470Ω | 12 |
| D1–D6 | LED rood | 6 |
| D7–D12 | LED blauw | 6 |
| D13 | 1N4148 vrijloopdiode | 1 |
| BT1 | 9V batterijclip | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage.

### Specifieke aandachtspunten

- **Gebruik rode LED's voor D1–D6 en blauwe LED's voor D7–D12** voor het juiste effect. De kleur is niet verplicht — elke combinatie kan.
- **D13 (1N4148)** is een kleine signaaldiode — let op de richting (streep op de diode = kathode, overeenkomend met de markering op de PCB).
- De transistoren Q1 en Q2 sturen elk een groep van 6 LED's aan.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/555/555/555police/`

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat, als het na zijn levenscyclus wordt weggeworpen, dit toestel schade kan toebrengen aan het milieu. Gooi dit toestel (en eventuele batterijen) niet bij het gewone huishoudelijke afval; het moet bij een gespecialiseerd bedrijf terechtkomen voor recyclage. U dient dit toestel naar uw verdeler of naar een lokaal recyclagepunt te brengen. Respecteer de plaatselijke milieuwetgeving. Heeft u vragen, contacteer dan de plaatselijke autoriteiten inzake afvalverwijdering.

Producten mogen altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
