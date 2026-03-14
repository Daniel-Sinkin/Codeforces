#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# ── Initial run ─────────────────────────────────────────────────────
{ [ -t 1 ] && clear || true; }
"$ROOT_DIR/compile_and_run.sh"

# ── Watch for changes ───────────────────────────────────────────────
if command -v watchexec >/dev/null 2>&1; then
  exec watchexec \
    --watch "$ROOT_DIR" \
    --exts cpp,h,hpp,csv \
    --clear \
    -- "$ROOT_DIR/compile_and_run.sh"
fi

if command -v entr >/dev/null 2>&1; then
  while true; do
    echo "$ROOT_DIR/main.cpp" "$ROOT_DIR/input.csv" | entr -d -c "$ROOT_DIR/compile_and_run.sh"
  done
fi

if command -v fswatch >/dev/null 2>&1; then
  fswatch -o "$ROOT_DIR/main.cpp" "$ROOT_DIR/input.csv" | while read -r _; do
    { [ -t 1 ] && clear || true; }
    "$ROOT_DIR/compile_and_run.sh"
  done
  exit 0
fi

echo "No watcher found. Install one:  brew install watchexec" >&2
exit 1
