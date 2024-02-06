#!/bin/bash

make re -B
./account > output_uncut.log
cut -c 18- output_uncut.log > output_cut.log
cut -c 18- 19920104_091532.log > 19920104_091532_cut.log
diff 19920104_091532_cut.log output_cut.log