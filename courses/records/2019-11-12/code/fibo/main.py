#!/usr/bin/python

import fibonacci
import sys

sequence = fibonacci.fibo(int(sys.argv[1]))

for i in sequence:
    print(i)

