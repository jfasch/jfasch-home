import threading
import time

def increment_background():
    global background_integer
    while True:
        print('background: value is', background_integer)
        time.sleep(0.5)
        background_integer += 1

background_integer = 0
t = threading.Thread(target=increment_background)
t.start()

foreground_integer = 0
for _ in range(3):
    print('foreground: value is', foreground_integer)
    time.sleep(0.5)
    foreground_integer -= 1
