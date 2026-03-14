#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC="${1:-$ROOT_DIR/main.cpp}"
INPUT="$ROOT_DIR/input.csv"
OUT="/tmp/cf_a.out"

CXX="/usr/bin/clang++"

$CXX -std=c++17 -O2 \
  -Wall \
  -Wextra \
  -Wpedantic \
  -Werror \
  -Wshadow \
  -Wformat=2 \
  -Wundef \
  -Wnull-dereference \
  -Wnon-virtual-dtor \
  -Woverloaded-virtual \
  -Wimplicit-fallthrough \
  -Wreturn-type \
  -Wno-sign-conversion \
  -Wno-float-conversion \
  -Wno-conversion \
  -Wno-old-style-cast \
  -Wno-sign-compare \
  -o "$OUT" "$SRC" \
  -DLOCAL

"$OUT" < "$INPUT"
