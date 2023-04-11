from threading import Thread
from time import sleep

def hello():
    while True:
        print('hello')
        sleep(0.5)

t1 = Thread(target=hello)
t1.run()
