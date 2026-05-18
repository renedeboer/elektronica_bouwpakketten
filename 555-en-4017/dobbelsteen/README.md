# Elektronische Dobbelsteen

Een elektronische dobbelsteen met 7 LED's in dobbelsteenpatroon, aangestuurd door een LM555 en CD4017. Druk op de knop, laat los en de uitkomst verschijnt.

<!-- foto: afgewerkt prototype (een waarde getoond) -->
<!-- foto: naakte PCB bovenkant -->

## Beschrijving

De LM555 oscilleert met hoge frequentie zolang de drukknop ingedrukt is. De CD4017 telt de pulsen snel op. Zodra je de knop loslaat, stopt de oscillatie en blijft de teller staan op een willekeurige uitgang. Zes transistoren (BC557 PNP en BC/BRN2222A NPN) schakelen de zeven LED's aan in het juiste dobbelsteenpatroon voor de waarden 1 t/m 6.

De schuifschakelaar is de aan/uit schakelaar.

## Schema

![Elektronische Dobbelsteen schema](schema/dice.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/555-en-4017/dobbelsteen/bom/ibom.html)

## Stuklijst

| Aanduiding | Waarde | Aantal |
|------------|--------|--------|
| U1 | LM555N (DIP-8) | 1 |
| U2 | CD4017 decade counter (DIP-16) | 1 |
| Q1–Q6 | BC557 PNP / BRN2222A NPN transistoren | 6 |
| C1 | 10µF / 10V elektrolytisch | 1 |
| C2 | 100nF | 1 |
| R1–R5 | 10kΩ | 5 |
| R6 | 3,3MΩ | 1 |
| R7 | 4,7MΩ | 1 |
| R8 | 10MΩ | 1 |
| R9–R21 | 1kΩ | 13 |
| D1–D7 | LED (kleur naar keuze) | 7 |
| SW1 | Drukknop (normally open) | 1 |
| SW2 | Schuifschakelaar DPDT | 1 |
| BT1 | 9V batterijclip | 1 |

## Dobbelsteenpatroon

De 7 LED's zijn geplaatst in het klassieke patroon van een dobbelsteen:

```
[1]   [2]   [3]

[4]   [5]   [6]

[7]
```

De transistorenlogica zorgt dat bij elke uitgang van de 4017 (1 t/m 6) de juiste combinatie van LED's oplicht.

## Bouwinstructies

Zie de [seriepagina](../README.md) voor de algemene volgorde van montage.

### Specifieke aandachtspunten

- Let bij de transistoren goed op het type: de BC557 is een **PNP** type, de BRN2222A is een **NPN** type. Ze zijn allebei aanwezig in dit circuit en hebben een verschillende werking — verwisselen geeft een niet-werkende schakeling.
- De drukknop SW1 is **normally open** (geen contact in rust) — dit is het standaard type.
- **C1 (10µF)** is elektrolytisch — let op polariteit.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/dice/dice/`
