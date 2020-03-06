#!/usr/bin/python

previous = 1
current = 1

while True:
    next = previous + current
    print(next)
    previous, current = current, next
