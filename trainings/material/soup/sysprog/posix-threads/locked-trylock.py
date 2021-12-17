#!/usr/bin/env python3


import threading

lock = threading.Lock()


def lock_race():
    global lock

    while True:
        if not lock.locked():
            locked = lock.acquire(blocking=False)
            if locked:
                print('SUCCEEDED')
                lock.release()
            else:
                print('FAILED')

background = threading.Thread(target=lock_race, daemon=True)
background.start()

lock_race()
