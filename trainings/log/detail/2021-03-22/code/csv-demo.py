#!/usr/bin/python

import sys
import csv


f = open(sys.argv[1])

rdr = csv.reader(f, delimiter=';')
for timestamp, name, value in rdr:
    print(f'zeitstempel: {timestamp}, name: {name}, wert: {value}')
