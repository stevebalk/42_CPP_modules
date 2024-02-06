#!/bin/bash

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo "Running make re..."
make re -B

echo "Running ./account..."
./account > output_uncut.log

echo "Cutting output_uncut.log..."
cut -c 18- output_uncut.log > output_cut.log

echo "Cutting 19920104_091532.log..."
cut -c 18- 19920104_091532.log > 19920104_091532_cut.log

echo "Comparing output_cut.log and 19920104_091532_cut.log..."
if diff -q 19920104_091532_cut.log output_cut.log > /dev/null; then
    echo -e "${GREEN}Files are identical.${NC}"
else
    echo -e "${RED}Files are different.${NC}"
fi