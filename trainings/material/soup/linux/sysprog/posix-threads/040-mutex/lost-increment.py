#!/usr/bin/env python3

import threading


the_innocent_integer = 0

def race_inc(num):
    global the_innocent_integer

    for _ in range(num):
        the_innocent_integer += 1

th1 = threading.Thread(target=race_inc, args=(10000000,))
th2 = threading.Thread(target=race_inc, args=(10000000,))

th1.start()
th2.start()

th1.join()
th2.join()

print(the_innocent_integer)
