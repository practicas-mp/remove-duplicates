#!/bin/bash

DATA_FILE=$1
OUTPUT_IMAGE=$2
GRAPHIC_NAME=$3

gnuplot <<EOF
set term png
set output "$OUTPUT_IMAGE"

set xlabel "Input size"
set ylabel "Time (ms)"

filenames = '$DATA_FILE'

plot for [f in filenames] f with lines title f
EOF
