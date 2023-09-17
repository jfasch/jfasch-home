#!/usr/bin/env python

from threading import Thread
import os

the_global_integer = 0

def increment():
    global the_global_integer

    for _ in range(10_000_000):
        tmp = the_global_integer
        os.sched_yield()
        tmp += 1
        the_global_integer = tmp

threads = [Thread(target=increment) for _ in range(2)]
for t in threads:
    t.start()
for t in threads:
    t.join()

print(the_global_integer)
