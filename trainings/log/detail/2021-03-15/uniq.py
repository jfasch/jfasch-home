#!/usr/bin/python3

import sys
import random
import time


def uniq_naive(inliste):
    outliste = []
    for element in inliste:
        if not element in outliste:    # sloooooow: 'in' on a list is
                                       # sequential search!!
            outliste.append(element)
    return outliste

def uniq_set(inliste):
    have = set()
    outliste = []
    for element in inliste:
        if not element in have:
            outliste.append(element)
            have.add(element)
    return outliste

def uniq_set_yield(inliste):
    have = set()
    for element in inliste:
        if not element in have:
            yield element
            have.add(element)




# decide which algorithm to use
if len(sys.argv) != 2:
    print('nix algorithmus gegeben, tu schreiben: naive oder set oder set_yield', file=sys.stderr)
    sys.exit(1)

if sys.argv[1] == 'naive':
    uniq = uniq_naive
elif sys.argv[1] == 'set':
    uniq = uniq_set
elif sys.argv[1] == 'set_yield':
    uniq = uniq_set_yield
else:
    print(f'nix gut algorithmus: {sys.argv[1]}, tu schreiben: naive oder set oder set_yield', file=sys.stderr)
    sys.exit(1)


            
# generate input data, randomly
# input_liste = [random.randrange(100) for _ in range(1000)]

def generate_random_numbers(n):
    for _ in range(1000):
        yield random.randrange(100)

input_numbers = generate_random_numbers(1000)

start_time = time.time()
output_liste = uniq(input_numbers)
end_time = time.time()

elapsed = end_time - start_time
print(f'time elapsed: {elapsed:20.17f}')

# for element in output_liste:
#     print(element)
