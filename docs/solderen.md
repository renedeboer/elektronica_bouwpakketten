<img src="../images/logo.svg" align="right" width="72">

# Soldeertips en techniek

Een korte handleiding voor het solderen van de bouwpakketten.

## Benodigdheden

- Soldeerbout (25–40W, fijne punt)
- Soldeertin (Ø 0,5–0,8mm, loodvrij of lood-tin 60/40)
- Derde hand of PCB-houder
- Pincet voor SMD onderdelen
- Zijkniptang
- Desoldeerpomp of desoldeerwick (voor eventuele fouten)
- Optioneel: vergrotingslens of loep

## Volgorde van solderen

Monteer onderdelen altijd van laag naar hoog:

1. SMD onderdelen (indien aanwezig)
2. Weerstanden
3. Diodes en condensatoren (let op polariteit)
4. IC-voeten (DIP-sockets)
5. Transistoren
6. Schakelaars en knoppen
7. LED's — **soldeer LED's pas als laatste**, zodat je ze op de juiste hoogte kunt plaatsen
8. Batterijhouder of connector

## Goede soldeerpunten

Een goede soldeerverbinding is:
- Glanzend en glad (niet mat of korrelig)
- Kegelvormig rond de aansluiting
- Niet te veel tin — de pad en het draad moeten allebei zichtbaar zijn

Een slechte verbinding (koude soldering) is mat en korrelig. Verwarm opnieuw en voeg eventueel een klein beetje soldeertin toe.

## Tips

- Verwarm de pad EN het draad tegelijk, breng dan pas soldeertin aan
- Werk snel: 2–3 seconden per punt is voldoende
- Laat afkoelen zonder te bewegen
- Knip overtollige draden recht na het solderen, niet vlak voor
- Controleer na het solderen alle verbindingen visueel op bruggen (kortsluiting tussen naburige pads)

## LED polariteit

LEDs hebben een plus (anode) en een min (kathode):
- Het langste been is de **anode (+)**
- Het kortste been is de **kathode (−)**
- Op de PCB is de kathode aangegeven met een streep of een platte kant op de silkscreen

Bij bidirectionele LEDs zitten twee kleuren in één behuizing. De polariteit bepaalt welke kleur brandt.
