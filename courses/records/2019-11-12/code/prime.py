#!/usr/bin/python

import sys

def isprime(n):
    if n == 1:
        return False

    for divisor in range(2,n//2):
        if n % divisor == 0:
            return False
    else:
        return True

pnum = int(sys.argv[1])
if isprime(pnum):
    print('jo')
else:
    print('na')
    
