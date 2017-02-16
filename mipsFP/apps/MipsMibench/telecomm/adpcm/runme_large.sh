#!/bin/bash

if [ "$ENDIAN" == "big" ]; then
    ${SIMULATOR}bin/rawcaudio < data/BIG_ENDIAN_large.pcm > output_large.adpcm
else 
    ${SIMULATOR}bin/rawcaudio < data/large.pcm > output_large.adpcm
fi

if [ "$ENDIAN" == "big" ]; then
    ${SIMULATOR}bin/rawdaudio < data/large.adpcm > BIG_ENDIAN_output_large.pcm
else
    ${SIMULATOR}bin/rawdaudio < data/large.adpcm > output_large.pcm
fi


