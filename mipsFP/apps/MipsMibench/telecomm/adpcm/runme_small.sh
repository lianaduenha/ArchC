#!/bin/bash

if [ "$ENDIAN" == "big" ]; then
    ${SIMULATOR}bin/rawcaudio < data/BIG_ENDIAN_small.pcm > output_small.adpcm
else 
    ${SIMULATOR}bin/rawcaudio < data/small.pcm > output_small.adpcm
fi

if [ "$ENDIAN" == "big" ]; then
    ${SIMULATOR}bin/rawdaudio < data/small.adpcm > BIG_ENDIAN_output_small.pcm
else
    ${SIMULATOR}bin/rawdaudio < data/small.adpcm > output_small.pcm
fi


