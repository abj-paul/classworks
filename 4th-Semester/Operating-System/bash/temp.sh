#!/bin/bash
gcc sin.c -o sin -lm
./sin | awk '{print $1 " equals to " $2}'
