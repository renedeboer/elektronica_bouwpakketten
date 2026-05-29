<img src="../../images/logo.svg" align="right" width="72">

# Knight Rider

Zes LED's die heen en weer lopen, geïnspireerd door de iconische verlichting van KITT uit Knight Rider.

| | |
|---|---|
| ![Lege PCB](fotos/knightrider_pcb_leeg.jpg) | ![Bestukte PCB](fotos/knightrider_pcb_bestukt.jpg) |
| *Lege PCB* | *Bestukt prototype* |

## In werking

![Knight Rider animatie](fotos/knightrider.gif)

## Beschrijving

De NE555 genereert automatisch een reeks klokpulsen via R1, R2 en C1, die de CD4017 decade teller aansturen. De 4017 heeft 10 uitgangen (Q0–Q9) waarvan er telkens één hoog is, en schuift bij elke puls één stap verder — zo worden de 6 leds (D1–D6) één voor één aangestuurd via een 1kΩ weerstand.

De truc zit in de bedrading vanaf stap 5: Q5 en Q6 zijn niet op nieuwe leds aangesloten, maar gespiegeld terug op D6, D5, D4... zodat het lichtje automatisch terugloopt naar D1. Na Q9 reset de teller en begint alles opnieuw — een eeuwig heen-en-weer effect, zonder microcontrollers.

## Schema

![555 Knight Rider schema](schema/555knightrider.svg)

[Handleiding / inlay (PDF)](schema/kitt.pdf)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/555-en-4017/knightrider/bom/ibom.html)

## Stuklijst

| Aanduiding | Waarde | Aantal |
|------------|--------|--------|
| U1 | NE555P (met ic-voet DIP-8) | 1 |
| U2 | CD4017 decade counter (met ic-voet DIP-16) | 1 |
| C1 | 3,3µF / 10V elektrolytisch | 1 |
| R1 | 1kΩ | 1 |
| R2 | 68kΩ | 1 |
| R3–R12 | 1kΩ | 10 |
| D1–D6 | LED (rood helder) | 6 |
| BT1 | 9V batterijclip | 1 |

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage.

### Specifieke aandachtspunten

- **U2 (CD4017)** is een 16-pins IC — zorg dat pin 1 (markering op het IC) overeenkomt met de markering op de socket.
- Alle 6 LED's op gelijke hoogte solderen geeft het mooiste effect.
- De snelheid pas je aan via R1 of C1: groter = langzamer.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/555/555/555knightrider/`

---

## Milieu-informatie

**Belangrijke milieu-informatie betreffende dit product**

Dit symbool op het toestel of de verpakking geeft aan dat dit product aan het einde van zijn levensduur niet bij het gewone huishoudelijk afval mag worden weggegooid. Gooi dit product (inclusief eventuele batterijen) niet bij het huisvuil — breng het naar een erkend inzamelpunt of retourpunt voor recycling. Neem voor meer informatie contact op met uw gemeente of lokale milieuinstantie.

Producten mogen voor recycling altijd worden teruggebracht of opgestuurd via de webshop op [rene-de-boer.nl](https://rene-de-boer.nl).
