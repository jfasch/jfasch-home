#!/usr/bin/python

def fibonacci(max_numbers=100):
    fibo_numbers = []

    previous = 1
    current = 1
    while len(fibo_numbers) < max_numbers:
        next = previous + current
        fibo_numbers.append(next)
        previous, current = current, next
        
    return fibo_numbers

if __name__ == '__main__':
    for num in fibonacci():
        print(num)
