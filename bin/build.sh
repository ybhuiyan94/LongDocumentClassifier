#!/bin/bash
# This file builds all relevant .c files
# and puts their respective .exe files in
# the bin folder of the project
scriptdir="$(dirname "$0")"
cd "$scriptdir"

gcc -o wordFrequency ../src/wordFrequency.c
gcc -o generateWeights ../src/generateWeights.c
gcc -o analyzeText ../src/analyzeText.c
