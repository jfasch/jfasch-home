import threading

integer = 0
ntimes = 10000000
lock = threading.Lock()

def increment_background():
    global integer, ntimes
    for _ in range(ntimes):
        lock.acquire()
        integer += 1
        lock.release()

t = threading.Thread(target=increment_background,
                     daemon=True)    # <----- mark as daemon
t.start()

for _ in range(ntimes):
    lock.acquire()
    integer += 1
    lock.release()

print('final value:', integer)
