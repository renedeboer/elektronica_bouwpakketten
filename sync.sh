#!/bin/bash
# sync.sh — synchroniseer KiCad projecten naar de GitHub repository
#
# Gebruik: ./sync.sh [--push]
#   Zonder --push: exporteert bestanden en toont wat er gewijzigd is
#   Met --push:    exporteert, commit en pusht naar GitHub

set -e

KICAD_CLI="/Applications/KiCad/KiCad.app/Contents/MacOS/kicad-cli"
KICAD_DIR="$HOME/Documents/KiCad/projects"
REPO_DIR="$HOME/Documents/Bouwkits/elektronica_bouwpakketten"

PUSH=false
if [[ "$1" == "--push" ]]; then
  PUSH=true
fi

# ─── Hulpfuncties ────────────────────────────────────────────────────────────

export_schema() {
  local sch_file="$1"
  local output_dir="$2"
  if [[ -f "$sch_file" ]]; then
    echo "  Schema: $(basename "$sch_file")"
    "$KICAD_CLI" sch export svg \
      --black-and-white \
      --no-background-color \
      --output "$output_dir" \
      "$sch_file" 2>/dev/null
  else
    echo "  WAARSCHUWING: schema niet gevonden: $sch_file"
  fi
}

copy_ibom() {
  local source="$1"
  local dest_dir="$2"
  if [[ -f "$source" ]]; then
    echo "  iBOM: $(basename "$source")"
    cp "$source" "$dest_dir/ibom.html"
  fi
}

# ─── Projecten ───────────────────────────────────────────────────────────────

echo ""
echo "=== Angry Cats From Space 1 — Kat in UFO ==="
export_schema "$KICAD_DIR/angrycatsfromspace1/angrycatsfromspace1.kicad_sch" \
              "$REPO_DIR/angry-cats-from-space/acfs1-ufo/schema"

echo ""
echo "=== Angry Cats From Space 2 — Kat met Raket ==="
export_schema "$KICAD_DIR/angrycatsfromspace2/angrycatsfromspace2.kicad_sch" \
              "$REPO_DIR/angry-cats-from-space/acfs2-raket/schema"

echo ""
echo "=== Angry Cats From Space 3 — Kat in Ruimtepak ==="
export_schema "$KICAD_DIR/angrycatsfromspace3/angrycatsfromspace3.kicad_sch" \
              "$REPO_DIR/angry-cats-from-space/acfs3-ruimtepak/schema"

echo ""
echo "=== Angry Cats From Space 4 — Kat op de Maan ==="
export_schema "$KICAD_DIR/angrycatsfromspace4/angrycatsfromspace4.kicad_sch" \
              "$REPO_DIR/angry-cats-from-space/acfs4-maan/schema"

echo ""
echo "=== Angry Cats From Space 5 — Kat bij Saturnus ==="
export_schema "$KICAD_DIR/angrycatsfromspace5/angrycatsfromspace5.kicad_sch" \
              "$REPO_DIR/angry-cats-from-space/acfs5-saturnus/schema"

echo ""
echo "=== 555 LED Fading ==="
export_schema "$KICAD_DIR/555/555/555fading/555.kicad_sch" \
              "$REPO_DIR/555-en-4017/fading/schema"
copy_ibom     "$KICAD_DIR/555/555/555fading/bom/ibom.html" \
              "$REPO_DIR/555-en-4017/fading/bom"

echo ""
echo "=== 555 Knight Rider ==="
export_schema "$KICAD_DIR/555/555/555knightrider/555knightrider.kicad_sch" \
              "$REPO_DIR/555-en-4017/knightrider/schema"
copy_ibom     "$KICAD_DIR/555/555/555knightrider/bom/ibom.html" \
              "$REPO_DIR/555-en-4017/knightrider/bom"

echo ""
echo "=== 555 Politielicht ==="
export_schema "$KICAD_DIR/555/555/555police/555police.kicad_sch" \
              "$REPO_DIR/555-en-4017/politielicht/schema"
copy_ibom     "$KICAD_DIR/555/555/555police/bom/ibom.html" \
              "$REPO_DIR/555-en-4017/politielicht/bom"

echo ""
echo "=== Elektronische Dobbelsteen ==="
export_schema "$KICAD_DIR/dice/dice/dice.kicad_sch" \
              "$REPO_DIR/555-en-4017/dobbelsteen/schema"
copy_ibom     "$KICAD_DIR/dice/dice/bom/ibom.html" \
              "$REPO_DIR/555-en-4017/dobbelsteen/bom"

echo ""
echo "=== Passieve Phono ==="
export_schema "$KICAD_DIR/passivephono/passivephono.kicad_sch" \
              "$REPO_DIR/passieve-phono/schema"
copy_ibom     "$KICAD_DIR/passivephono/bom/ibom.html" \
              "$REPO_DIR/passieve-phono/bom"

echo ""
echo "=== Arduino I2C Shield ==="
export_schema "$KICAD_DIR/P82B715P/uno-shield.kicad_sch" \
              "$REPO_DIR/arduino-i2c-shield/schema"
export_schema "$KICAD_DIR/P82B715P/P82B715P.kicad_sch" \
              "$REPO_DIR/arduino-i2c-shield/schema"
copy_ibom     "$KICAD_DIR/P82B715P/bom/ibom.html" \
              "$REPO_DIR/arduino-i2c-shield/bom"

echo ""
echo "=== VFD Klok ==="
export_schema "$KICAD_DIR/vfd/vfd.kicad_sch" \
              "$REPO_DIR/vfd-klok/schema"
copy_ibom     "$KICAD_DIR/vfd/bom/ibom.html" \
              "$REPO_DIR/vfd-klok/bom"

# ─── Git status en optioneel commit + push ───────────────────────────────────

echo ""
echo "─────────────────────────────────────────"
cd "$REPO_DIR"
CHANGED=$(git status --porcelain)

if [[ -z "$CHANGED" ]]; then
  echo "Geen wijzigingen — alles is al up-to-date."
  exit 0
fi

echo "Gewijzigde bestanden:"
git status --short

if [[ "$PUSH" == true ]]; then
  echo ""
  # Automatisch commit bericht op basis van gewijzigde mappen
  PROJECTS=$(git status --short | awk '{print $2}' | cut -d/ -f1 | sort -u | tr '\n' ', ' | sed 's/,$//')
  DATE=$(date '+%Y-%m-%d')
  MSG="Sync KiCad exports: schema's en iBOM bijgewerkt ($DATE)

Bijgewerkte projecten: $PROJECTS

Co-Authored-By: Claude Sonnet 4.6 <noreply@anthropic.com>"
  git add -A
  git commit -m "$MSG"
  git push
  echo ""
  echo "Gepusht naar GitHub."
else
  echo ""
  echo "Gebruik './sync.sh --push' om te committen en te pushen."
fi
