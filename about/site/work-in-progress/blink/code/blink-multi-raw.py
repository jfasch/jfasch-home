#!/usr/bin/env python

import gpiod
import asyncio
import itertools

MATRIX = (
    (11, 10, 27,  4,  2),
    ( 0,  9, 22, 17,  3),
    ( 5, 20,  1, 25, 18),
    ( 6, 16,  7, 24, 15),
    (13, 12,  8, 23, 14),
)
ALL_IOS = sum(MATRIX, start=())

REQUEST = gpiod.request_lines(
    '/dev/gpiochip0',
    consumer='blink',
    config={ALL_IOS: gpiod.LineSettings(direction=gpiod.line.Direction.OUTPUT)})

def SET_VALUES(ios, b):
    REQUEST.set_values({i: gpiod.line.Value(b) for i in ios})

async def blink(ios, interval, ntimes=None):
    loop = (ntimes is None) and itertools.count() or range(ntimes)
    for _ in loop:
        SET_VALUES(ios, 1)
        await asyncio.sleep(interval)
        SET_VALUES(ios, 0)
        await asyncio.sleep(interval)

async def main():
    t1 = asyncio.create_task(blink((11,), 0.5))
    t2 = asyncio.create_task(blink((10,), 0.8))
    t3 = asyncio.create_task(blink((27,), 1))

    await t1
    await t2
    await t3

asyncio.run(main())
