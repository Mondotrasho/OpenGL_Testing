#!/usr/bin/env bash
set -euo pipefail

mkdir -p build/linux

g++ -std=c++17 -Wall -Wextra -pedantic \
  main.cpp \
  -lGL -lGLU -lglut \
  -o build/linux/app

echo "Linux build passed."
