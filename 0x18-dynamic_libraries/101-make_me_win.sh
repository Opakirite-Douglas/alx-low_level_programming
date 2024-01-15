#!/bin/bash
wget -P .. https://raw.githubusercontent.com/benjminrichie/alx-low_level_programming/master/0x18-dynamic_libraries/libtestHack.so
export LD_PRELOAD="$PWD/../libtestHack.so"
