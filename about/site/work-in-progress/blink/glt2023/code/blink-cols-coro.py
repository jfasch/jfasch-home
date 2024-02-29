#!/usr/bin/env python

from stuff_raw import *
import asyncio
import numpy

async def all(coros):
    tasks = [asyncio.create_task(c) for c in coros]
    for t in tasks:
        await t

async def main():
    cols = numpy.transpose(MATRIX).tolist()

    await all([
        blink(cols[0], 0.5),
        blink(cols[1], 0.4),
        blink(cols[2], 0.3),
        blink(cols[3], 0.2),
        blink(cols[4], 0.1),
    ])

asyncio.run(main())
