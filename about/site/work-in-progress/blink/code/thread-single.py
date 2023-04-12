#!/usr/bin/env python

from threading import Thread
import time

def hello():
    for _ in range(5):
        print('hello')
        time.sleep(0.5)

t1 = Thread(target=hello)
t1.start()
t1.join()
