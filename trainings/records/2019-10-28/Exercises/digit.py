#!/usr/bin/python3

# Exercises: Basics (~51)

# Write a program that takes a single digit as commandline
# parameter. Print the English word for that digit.

import sys


translation = {
    0: 'zero',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
}

digit = int(sys.argv[1])
if 0 <= digit <= 9:
    print(translation[digit])
else:
    print('nix')
