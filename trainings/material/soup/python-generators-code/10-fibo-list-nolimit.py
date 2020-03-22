#!/usr/bin/python

def fibonacci():
    fibo_numbers = []

    previous = 1
    current = 1
    while True:
        next = previous + current
        fibo_numbers.append(next)
        previous, current = current, next
        
    return fibo_numbers

if __name__ == '__main__':
    for num in fibonacci():
        print(num)
