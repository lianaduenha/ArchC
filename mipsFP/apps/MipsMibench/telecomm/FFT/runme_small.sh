#!/bin/sh
${SIMULATOR}fft 4 4096 > output_small.txt
${SIMULATOR}fft 4 8192 -i > output_small.inv.txt
