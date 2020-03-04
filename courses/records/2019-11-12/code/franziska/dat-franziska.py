#!/usr/bin/python

import dat
import sys


filename = sys.argv[1]
matrix = dat.load_dat(filename)

print(matrix)
