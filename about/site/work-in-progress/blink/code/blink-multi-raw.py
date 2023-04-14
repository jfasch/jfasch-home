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
    tasks = [
        asyncio.create_task(blink((11,), 0.5)),
        asyncio.create_task(blink((10,), 0.4)),
        asyncio.create_task(blink((27,), 0.3)),
        asyncio.create_task(blink(( 4,), 0.2)),
        asyncio.create_task(blink(( 2,), 0.1)),
    ]
    for t in tasks:
        await t

asyncio.run(main())
