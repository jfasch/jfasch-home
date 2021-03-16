#!/usr/bin/python3

import csv
import sys


f = open(sys.argv[1])
rdr = csv.reader(f, delimiter=';')

for nr, (timestamp, value) in enumerate(rdr):
    print('nr:', nr, 'timestamp:', timestamp, ', value:', value)

