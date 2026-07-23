#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <id(4digits)> <slug>"
  echo "Example: $0 0121 best-time-to-buy-and-sell-stock"
  exit 1
fi

ID="$1"
SLUG_RAW="$2"
SLUG="${SLUG_RAW//-/_}"
HEADER="include/problems/p${ID}_${SLUG}.hpp"
SOURCE="problems/p${ID}_${SLUG}.cpp"

if [ -f "$HEADER" ] || [ -f "$SOURCE" ]; then
  echo "Target files already exist."
  exit 1
fi

cat > "$HEADER" <<EOF
#pragma once

void run_p${ID}_demo();
EOF

cat > "$SOURCE" <<EOF
#include "problems/p${ID}_${SLUG}.hpp"

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // TODO: Implement your solution method.
    int solve(const std::vector<int>& nums) {
        (void)nums;
        return 0;
    }
};

void run_p${ID}_demo() {
    // TODO: Add local demo cases if needed.
}
EOF

echo "Created: $HEADER"
echo "Created: $SOURCE"
echo "Now include the new header and call run_p${ID}_demo() in src/main.cpp"
