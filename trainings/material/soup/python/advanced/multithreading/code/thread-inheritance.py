import threading
import time

class BackgroundIncrementer(threading.Thread):
    def run(self):
        global background_integer
        while True:
            print('background: value is', background_integer)
            time.sleep(0.5)
            background_integer += 1

background_integer = 0
t = BackgroundIncrementer()
t.start()

foreground_integer = 0
while True:
    print('foreground: value is', foreground_integer)
    time.sleep(0.5)
    foreground_integer -= 1
