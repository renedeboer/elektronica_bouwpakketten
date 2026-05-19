<img src="images/logo.svg" align="right" width="120">

# Elektronica Bouwpakketten

Een verzameling zelfbouw elektronica bouwpakketten, van eenvoudige 555-timer schakelingen tot een VFD klok met Arduino. Alle bouwpakketten zijn ontworpen in KiCad.

Deze projecten zijn gemaakt om solderen en elektronica toegankelijk en leuk te maken — voor beginners die hun eerste LED-schakeling bouwen, en voor liefhebbers die iets eigens willen maken.

![Werkbank](images/werkbank.jpg)

## Bestellen

De printplaten en complete bouwpakketten zijn te bestellen via de webshop op **[rene-de-boer.nl](https://rene-de-boer.nl)**.

## Overzicht

### Angry Cats From Space — ATtiny85 LED bouwpakketten

Vijf verschillende PCB's met een kat in de ruimte als thema. Allen aangestuurd door een ATtiny85 microcontroller via charlieplexing, gevoed door twee AA of AAA batterijen.

| Kit | Thema | LEDs | |
|-----|-------|------|-|
| [ACFS1 — Kat in UFO](angry-cats-from-space/acfs1-ufo/) | Kat in een vliegende schotel | 14 | <img src="angry-cats-from-space/acfs1-ufo/fotos/acfs1-ufo_artwork.png" width="80"> |
| [ACFS2 — Kat in een Raket](angry-cats-from-space/acfs2-raket/) | Kat in een raket | 20 | <img src="angry-cats-from-space/acfs2-raket/fotos/acfs2-raket_artwork.png" width="80"> |
| [ACFS3 — Kat in Ruimtepak](angry-cats-from-space/acfs3-ruimtepak/) | Kat in ruimtepak | 8 | <img src="angry-cats-from-space/acfs3-ruimtepak/fotos/acfs3-ruimtepak_artwork.png" width="80"> |
| [ACFS4 — Kat op de Maan](angry-cats-from-space/acfs4-maan/) | Kat op de maan | 12 | <img src="angry-cats-from-space/acfs4-maan/fotos/acfs4-maan_artwork.png" width="80"> |
| [ACFS5 — Kat op Saturnus](angry-cats-from-space/acfs5-saturnus/) | Kat op de planeet Saturnus | 12 | <img src="angry-cats-from-space/acfs5-saturnus/fotos/acfs5-saturnus_artwork.png" width="80"> |

Meer info over de hele serie: [Angry Cats From Space](angry-cats-from-space/)

---

### 555-timer en 4017 — Analoge LED bouwpakketten

Vier bouwpakketten op basis van de klassieke NE555/LM555 timer IC en de CD4017 decade counter. Puur analoge/digitale elektronica, geen microcontroller of software.

| Kit | Effect | |
|-----|--------|-|
| [LED Fading](555-en-4017/fading/) | LED die langzaam aan en uit ademhaalt | <img src="555-en-4017/fading/fotos/fading.gif" width="120"> |
| [Knight Rider](555-en-4017/knightrider/) | 5 LEDs die heen en weer lopen | <img src="555-en-4017/knightrider/fotos/knightrider.gif" width="120"> |
| [Politielicht](555-en-4017/politielicht/) | Rood/blauw zwaailicht effect | <img src="555-en-4017/politielicht/fotos/politielicht.gif" width="120"> |
| [Elektronische Dobbelsteen](555-en-4017/dobbelsteen/) | Dobbelsteen met balschakelaar | <img src="555-en-4017/dobbelsteen/fotos/dobbelsteen.gif" width="80"> |

Meer info over de hele serie: [555-timer en 4017](555-en-4017/)

---

### Overige bouwpakketten

| Kit | Beschrijving | |
|-----|-------------|-|
| [Phono Voorversterker](passieve-phono/) | Stereo phono voorversterker met passief RIAA netwerk tussen twee OPA606 trappen (Walter G. Jung topologie) | <img src="passieve-phono/fotos/phono_pcb_bestukt.jpg" width="120"> |
| [Arduino I2C Shield](arduino-i2c-shield/) | Arduino Uno shield met P82B715P I2C bus extender | <img src="arduino-i2c-shield/fotos/i2c_systeem_compleet.jpg" width="120"> |
| [VFD Klok](vfd-klok/) | Vacuüm fluorescentie display klok met Arduino Nano en RTC | <img src="vfd-klok/fotos/vfd_display_aan.jpg" width="120"> |
| [ZX Spectrum I2C](zx-spectrum-i2c/) | I2C uitbreidingskaart voor de ZX Spectrum 48K met BASIC software bibliotheek | <img src="zx-spectrum-i2c/fotos/zxi2c_pcb_bestukt.jpg" width="120"> |

---

### Modules en bibliotheken

Eigen producten met een eigen GitHub repository. De broncode en updates staan daar; onderstaande pagina's geven een overzicht.

| Module | Beschrijving | |
|--------|-------------|-|
| [Vleermuis](vleermuis/) | ATtiny85 LED-bouwpakket, basis voor de Angry Cats From Space serie — [github.com/renedeboer/ReneDeBoer_Vleermuis](https://github.com/renedeboer/ReneDeBoer_Vleermuis) | <img src="vleermuis/fotos/vleermuis_pcb_bestukt.jpg" width="120"> |
| [RTC Module](rtc/) | DS1307 real-time clock module met Arduino library, werkt met elke I2C master — [github.com/renedeboer/ReneDeBoer_RTC](https://github.com/renedeboer/ReneDeBoer_RTC) | <img src="images/ds1307-a.jpg" width="120"> |

---

## Algemene informatie

- [Soldeertips en techniek](docs/solderen.md)
- [Benodigde gereedschappen en materialen](docs/benodigdheden.md)

## Licentie

**PCB layouts en artwork** © René de Boer — Alle rechten voorbehouden. Persoonlijk gebruik (zelf bouwen) is toegestaan; commercieel gebruik niet zonder toestemming.

**Schakelingen** — gebaseerd op publiek domein bronnen en fabrikantsdatasheets. De passieve phono schakeling is afkomstig uit de OPA606 datasheet, toegeschreven aan Walter G. Jung.

**Software** — gepubliceerd onder de [MIT Licentie](LICENSE).

Zie [LICENSE](LICENSE) voor de volledige tekst.
