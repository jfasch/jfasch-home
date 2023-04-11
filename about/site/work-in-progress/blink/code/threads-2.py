from threading import Thread
from time import sleep

def hello_left():
    while True:
        print('hello left')
        sleep(0.5)

def hello_right():
    while True:
        print('hello right'.rjust(60))
        sleep(0.8)

def hello_middle():
    while True:
        print('hello middle'.center(60))
        sleep(1)

t1 = Thread(target=hello_left)
t2 = Thread(target=hello_right)
t3 = Thread(target=hello_middle)
t1.start()
t2.start()
t3.start()
