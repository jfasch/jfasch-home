#!/usr/bin/python3

import sys

filename = sys.argv[1]
print('opening file', filename)
f = open(filename)
for line in f:
    print(line)
