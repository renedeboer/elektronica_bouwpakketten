<img src="../images/logo.svg" align="right" width="72">

# 555-timer en 4017 Bouwpakketten

Vier klassieke LED-bouwpakketten op basis van de **NE555/LM555 timer IC** en de **CD4017 decade counter**. Puur analoge en digitale elektronica — geen microcontroller, geen software, geen programmering nodig.

## Hoe het werkt

De 555-timer is een van de meest gebruikte IC's aller tijden. In deze bouwpakketten wordt hij ingezet als oscillator: hij genereert een regelmatig blokgolfsignaal. De CD4017 decade counter telt de pulsen en schakelt daarmee tien uitgangen sequentieel aan — ideaal voor lopende lichtjes en andere LED-effecten.

### 555-timer basisprincipe

De 555 werkt hier in astabiele modus: hij schakelt zichzelf continu aan en uit. De frequentie — en dus de snelheid van het effect — wordt bepaald door twee weerstanden en een condensator.

### CD4017 decade counter

De 4017 heeft 10 uitgangen (Q0–Q9). Bij iedere puls van de 555 stapt hij één uitgang verder. Zo kun je met een paar LED's een lopend lichtpatroon maken.

## De vier bouwpakketten

| Kit | IC's | Effect |
|-----|------|--------|
| [LED Fading](fading/) | NE555, BC547 | LED die langzaam aan en uit ademhaalt |
| [Knight Rider](knightrider/) | NE555, CD4017 | 5 LEDs die heen en weer lopen |
| [Politielicht](politielicht/) | NE555, CD4017, 2× BC547 | Rood/blauw zwaailicht |
| [Elektronische Dobbelsteen](dobbelsteen/) | LM555, CD4017, transistoren | Dobbelsteen met balschakelaar |

## Voeding

Alle vier bouwpakketten werken op een **9V blokbatterij**.

## Bouwinstructies

Zie [soldeertips en techniek](../docs/solderen.md) voor algemene soldeerinformatie.

### Algemene volgorde van montage

1. Weerstanden
2. Condensatoren (let op polariteit van de elektrolytische condensatoren)
3. Diodes (indien aanwezig — let op richting)
4. IC-socket(s)
5. Transistoren — let op de platte/ronde kant voor de juiste richting
6. Schakelaar(s) en knop(pen)
7. LED's — **als laatste**, zodat je de hoogte kunt aanpassen
8. Batterijclip of batterijhouder
9. IC('s) in de socket(s) plaatsen (inkeping op de chip = inkeping op socket)
