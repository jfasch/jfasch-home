#!/usr/bin/python

def fibonacci():
    previous = 1
    current = 1
    while True:
        next = previous + current
        yield next
        previous, current = current, next

if __name__ == '__main__':
    for num in fibonacci():
        print(num)
