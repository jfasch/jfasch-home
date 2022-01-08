#!/usr/bin/env python3

import time
import sys
import statistics


INTERVAL = float(sys.argv[1])
LOOPS = int(sys.argv[2])

data = []

for _ in range(LOOPS):
    before = time.time()
    time.sleep(INTERVAL)
    after = time.time()

    jitter = after - before - INTERVAL
    data.append(jitter)

mean = statistics.mean(data)
stdev = statistics.stdev(data)

print(f'mean: {mean:.6f}s ({mean*1000:.6f}ms, {mean*1000*1000}us)')
print(f'stdev: {stdev:.6f}s ({stdev*1000:.6f}ms, {stdev*1000*1000}us)')
