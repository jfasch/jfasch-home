import threading

integer = 0
ntimes = 10000000

def increment_background():
    global integer, ntimes
    for _ in range(ntimes):
        integer += 1

t = threading.Thread(target=increment_background,
                     daemon=True)    # <----- mark as daemon
t.start()

for _ in range(ntimes):
    integer += 1

print('final value:', integer)
