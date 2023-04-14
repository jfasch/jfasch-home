#!/usr/bin/env python

from stuff_raw import *
import asyncio
import numpy

async def main():
    rows = MATRIX
    cols = numpy.transpose(MATRIX).tolist()

    tasks = [
        asyncio.create_task(blink(cols[0], 0.5)),
        asyncio.create_task(blink(cols[1], 0.4)),
        asyncio.create_task(blink(cols[2], 0.3)),
        asyncio.create_task(blink(cols[3], 0.2)),
        asyncio.create_task(blink(cols[4], 0.1)),
    ]
    for t in tasks:
        await t

asyncio.run(main())
