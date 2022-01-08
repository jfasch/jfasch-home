#!/usr/bin/env python3

import time

for _ in range(100):
    interval = 0.1

    before = time.time()
    time.sleep(interval)
    after = time.time()

    jitter = after - before - interval
    print(f'jitter: {jitter}s ({jitter*1000}ms)')
