#!/usr/bin/env python

from threading import Thread
import time

def hello_left():
    for _ in range(10):
        print('hello left')
        time.sleep(0.5)

def hello_right():
    for _ in range(10):
        print('hello right'.rjust(60))
        time.sleep(0.4)

def hello_middle():
    for _ in range(10):
        print('hello middle'.center(60))
        time.sleep(0.3)

t1 = Thread(target=hello_left)
t2 = Thread(target=hello_right)
t3 = Thread(target=hello_middle)

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()
