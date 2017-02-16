#!/bin/sh
${SIMULATOR}jpeg-6a/cjpeg -dct int -progressive -opt -outfile output_large_encode.jpeg input_large.ppm
${SIMULATOR}jpeg-6a/djpeg -dct int -ppm -outfile output_large_decode.ppm input_large.jpg
