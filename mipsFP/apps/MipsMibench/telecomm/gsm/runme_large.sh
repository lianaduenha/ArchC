#!/bin/sh
${SIMULATOR}bin/toast -fps -c data/large.au > output_large.encode.gsm
${SIMULATOR}bin/untoast -fps -c data/large.au.run.gsm > output_large.decode.run
