#!/bin/bash

touch backup_`date -I`_`whoami`.txt
ls -alh backup_`date -I`_`whoami`.txt
ls -l | grep ^d | awk '{ print $2,$6,$7 }' | sort -R
