#!/usr/bin/env bash
set -euo pipefail

ID_INPUT="${1:-}"

if [ -z "$ID_INPUT" ]; then
  read -r -p "문제 번호 입력 (예: 1, 169, 0001): " ID_INPUT
fi

if ! [[ "$ID_INPUT" =~ ^[0-9]+$ ]]; then
  echo "숫자만 입력해 주세요."
  exit 1
fi

ID_PADDED=$(printf "%04d" "$ID_INPUT")

cmake -S . -B build
cmake --build build
./build/leet_runner "$ID_PADDED"
