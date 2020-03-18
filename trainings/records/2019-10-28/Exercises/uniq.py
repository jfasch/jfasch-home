#!/usr/bin/python3

# Exercises: Lists, Loops, Functions (~94)

# Write a function uniq() that takes a sequence as input. It returns a
# list with duplicate elements removed, and where the contained
# elements appear in the same order that is present in the input
# sequence. The input sequence remains unmodified.


# Deviations from the requirement:

# 1. implement uniq() as a generator. use yield to produce items.

# 2. demonstrate how to use uniq() as a filter, connecting nodes
#    together using "pipes" as in the pseudo-filter expression:

#    random | uniq | print


import random


def uniq(l):
    '''filter that iterates over the input sequence and produces an item
    only if that was not yet seen in the input sequence.

    '''

    have = set()
    for i in l:
        if i not in have:
            have.add(i)
            yield i

def randomnumbers(howmany):
    "produces'howmany' random numbers."
    for _ in range(howmany):
        yield random.randrange(10)


for i in uniq(randomnumbers(100)):
    print(i)
