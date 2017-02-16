#!/bin/bash

if [ $ENDIAN == "little" ]; then
    ${SIMULATOR}rijndael input_large.asc LITTLE_ENDIAN_output_large.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
    ${SIMULATOR}rijndael LITTLE_ENDIAN_output_large.enc output_large.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
else
    ${SIMULATOR}rijndael input_large.asc output_large.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
    ${SIMULATOR}rijndael output_large.enc output_large.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321
fi



