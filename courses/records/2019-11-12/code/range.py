#!/usr/bin/python

def my_range(n):
    cur = 0
    while cur != n:
        yield cur
        cur += 1

for i in my_range(10):
    print(i)
