#!/usr/bin/python3

# Exercises: While Loop (~58)

# Write a program that takes an integer commandline parameter and
# checks whether that number is prime!


# Exercises: Lists, Loops, Functions (~94)

# Modify the prime number detection program from one of the previous
# exercises: make the prime number detection a function, and call the
# function instead. The function (is prime() is a likely name) takes a
# number, and returns a boolean value as appropriate.


import sys

def is_prime(candidate):
    if candidate < 2:
        return False

    divisor = 2
    while divisor <= candidate//2:
        if candidate % divisor == 0:
            return False
        divisor += 1
    else:
        return True



candidate = int(sys.argv[1])

print(is_prime(candidate))
