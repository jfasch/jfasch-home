#!/usr/bin/python

def uniq(sequence):
    have = set()

    for item in sequence:
        if item not in have:
            yield item
            have.add(item)

for i in uniq([1,5,1,4,5,100,100,1]):
    print(i)
