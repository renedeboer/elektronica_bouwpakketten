# Passieve Phono Voorversterker

Een passief RIAA equalisatie filter voor het aansluiten van een platenspeler op een versterker zonder phono-ingang.

<!-- foto: afgewerkt prototype (voorkant) -->
<!-- foto: naakte PCB bovenkant -->
<!-- foto: PCB in gebruik, aangesloten op platenspeler en versterker -->

## Beschrijving

Een platenspeler met een MM (Moving Magnet) element heeft twee dingen nodig om correct te klinken:

1. **Versterking** — het signaal van een platenspelerelement is erg zwak
2. **RIAA equalisatie** — bij het persen van een plaat worden de hoge frequenties versterkt en de lage frequenties gedempt opgeslagen. Bij het afspelen moet dit precies omgekeerd worden.

Dit bouwpakket is een **passieve** versie: het voert alleen de RIAA equalisatie uit, zonder actieve versterking. Het is bedoeld voor gebruik met een lijningang waarbij een apart versterkerasje het niveau ophoogschakelt, of voor platenspelers met een ingebouwde voorversterker die alleen equalisatie nodig heeft.

**Geen voeding nodig** — volledig passief circuit.

## Schema

![Passieve Phono schema](schema/passivephono.svg)

[Interactieve stuklijst (iBOM)](https://htmlpreview.github.io/?https://github.com/renedeboer/elektronica_bouwpakketten/blob/main/passieve-phono/bom/ibom.html)

## Stuklijst

<!-- stuklijst volgt na verificatie van het schema -->

## Aansluitingen

| Connector | Functie |
|-----------|---------|
| Ingang L/R | Van de platenspeler (RCA of tulpstekker) |
| Uitgang L/R | Naar de versterker lijningang (RCA of tulpstekker) |
| Massa/aarde | Aardedraad platenspeler aansluiten |

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Specifieke aandachtspunten

- Dit is een geheel passief circuit — er zijn geen polariteitsgevoelige onderdelen (elektrolytische condensatoren of diodes) tenzij anders vermeld in het schema.
- Zorg voor goede afscherming van de aansluitkabels — een platenspelersignaal is erg zwak en gevoelig voor brom en storing.
- De aardedraad van de platenspeler (apart van de signaalkabel) aansluiten op de massapin van het bouwpakket.

## Bronvermelding

De schakeling is afkomstig uit de **OPA606 datasheet (Burr-Brown / Texas Instruments)**, waar hij wordt toegeschreven aan **Walter G. Jung**.

## KiCad bestanden

Projectbestanden: `~/Documents/KiCad/projects/passivephono/`
