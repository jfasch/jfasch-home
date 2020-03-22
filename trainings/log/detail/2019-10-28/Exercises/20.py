#!/usr/bin/python3

# Exercises: Strings (~121)

# Write a program that receives any number of arguments and
# prints them out right justified at column 20.

import sys


for s in sys.argv[1:]:
    while len(s) >= 20:
        print(s[:20])
        s = s[20:]
    print(s.rjust(20))


