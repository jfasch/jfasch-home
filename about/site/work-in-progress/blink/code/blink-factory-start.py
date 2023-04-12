#!/usr/bin/env python

from stuff_raw2 import *
import asyncio

async def forever(coro):
    while True:
        await coro

async def blink(ios, interval, ntimes=None):
    loop = (ntimes is None) and itertools.count() or range(ntimes)
    for _ in loop:
        SET_VALUES(ios, 1)
        await asyncio.sleep(interval)
        SET_VALUES(ios, 0)
        await asyncio.sleep(interval)

async def main():
    await forever(
        blink((11,), 0.3, 1),
    )

asyncio.run(main())
