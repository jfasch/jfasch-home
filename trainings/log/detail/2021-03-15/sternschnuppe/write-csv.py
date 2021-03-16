#!/usr/bin/python3

import sys
import csv


print('sys.argv ist', sys.argv)
filename = sys.argv[1]

f = open(filename, 'a')

w = csv.writer(f, delimiter=';')
w.writerow([1, 6.666])
