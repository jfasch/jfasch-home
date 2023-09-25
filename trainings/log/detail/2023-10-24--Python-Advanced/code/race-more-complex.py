#!/usr/bin/env python

from threading import Thread

a_dict_of_integers = {
    'one': 0,
    'two': 0,
}

def increment():
    for _ in range(10_000_000):
        a_dict_of_integers['one'] += 1
        a_dict_of_integers['two'] += 1

threads = [Thread(target=increment) for _ in range(3)]
for t in threads:
    t.start()
for t in threads:
    t.join()

print(a_dict_of_integers)
