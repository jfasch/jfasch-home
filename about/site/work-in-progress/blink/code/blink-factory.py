#!/usr/bin/env python

from stuff_raw2 import *
import asyncio

async def forever(factory):
    while True:
        await factory.create_coro()

class blink:
    def __init__(self, ios, interval, ntimes=None):
        self.ios = ios
        self.interval = interval
        self.ntimes = ntimes

    def create_coro(self):
        async def _blink(ios, interval, ntimes=None):
            loop = (ntimes is None) and itertools.count() or range(ntimes)
            for _ in loop:
                SET_VALUES(ios, 1)
                await asyncio.sleep(interval)
                SET_VALUES(ios, 0)
                await asyncio.sleep(interval)
        return _blink(self.ios, self.interval, self.ntimes)

async def main():
    await forever(
        blink((11,), 0.3, 1),
    )

asyncio.run(main())
