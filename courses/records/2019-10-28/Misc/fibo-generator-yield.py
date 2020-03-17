#!/usr/bin/python3

# Generators, yield. implementing an infinite sequence (fibonacci is a
# cool example) which would not be so easy if we had only functions
# (these can only return once).

import time


def fibonacci():
    prev = 1
    cur = 1

    yield prev
    yield cur
    
    while True:
        next = prev + cur
        yield next
        prev = cur
        cur = next

for fibonum in fibonacci():
    print(fibonum)
