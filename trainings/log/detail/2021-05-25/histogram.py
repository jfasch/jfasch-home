#!/usr/bin/python

import io
import sys
from collections import defaultdict


def make_histogram(fileobj):
    histogram = defaultdict(int)
    while True:
        c = fileobj.read(1)
        if len(c) == 0:
            break

        # VERSION 1: not pythonic
        
        # if c in histogram:
        #     histogram[c] += 1
        # else:
        #     histogram[c] = 1


        # VERSION 2: a little more pythonic

        # count = histogram.setdefault(c, 0)
        # histogram[c] += 1

        # VERSION 3: most pythonic

        histogram[c] += 1

    return histogram

# f = io.StringIO('Jörg')
f = open(sys.argv[1], encoding='iso-8859-1')
for k, v in make_histogram(f).items():
    print(f'{k} -> {v*"-"}')
