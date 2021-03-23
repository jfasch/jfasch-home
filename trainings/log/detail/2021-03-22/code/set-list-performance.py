import random
import time


print('building up ...')

s = set()
l = list()

for _ in range(3*10**6):
    rnd = random.randrange(3*10**6)
    s.add(rnd)
    l.append(rnd)

print('... done')

nsearches = 3000

print('searching list ...')

list_before = time.time()
key = random.randrange(3*10**6)
for _ in range(3000):
    key in l
list_after = time.time()
list_total = list_after - list_before

print('searching set ...')

set_before = time.time()
key = random.randrange(3*10**6)
for _ in range(3000):
    key in s
set_after = time.time()
set_total = set_after - set_before

print('... done')

print('list total:', list_total)
print('set total:', set_total)
