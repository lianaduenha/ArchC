#!/bin/sh
${SIMULATOR}bin/toast -fps -c data/small.au > output_small.encode.gsm
${SIMULATOR}bin/untoast -fps -c data/small.au.run.gsm > output_small.decode.run
