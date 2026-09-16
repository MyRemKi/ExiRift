#!/usr/bin/env bash
# Compile toutes les sources .cpp du projet (recursif) en un seul executable.
set -e
cd "$(dirname "$0")"

SOURCES=$(find . -name "*.cpp")
OUTPUT="game.exe"

echo "Compilation des fichiers :"
echo "$SOURCES"

g++ -std=c++17 -I. -Wall -o "$OUTPUT" $SOURCES

echo "Build terminé : $OUTPUT"
