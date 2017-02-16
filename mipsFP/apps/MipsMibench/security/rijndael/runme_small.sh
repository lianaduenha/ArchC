#!/bin/bash

if [ $ENDIAN == "little" ]; then
    ${SIMULATOR}rijndael input_small.asc LITTLE_ENDIAN_output_small.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
    ${SIMULATOR}rijndael LITTLE_ENDIAN_output_small.enc output_small.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
else
    ${SIMULATOR}rijndael input_small.asc output_small.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
    ${SIMULATOR}rijndael output_small.enc output_small.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
fi



