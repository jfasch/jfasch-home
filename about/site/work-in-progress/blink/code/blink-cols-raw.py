#!/usr/bin/env python

from stuff_raw import *
import asyncio
import numpy

async def main():
    cols = numpy.transpose(MATRIX).tolist()

    tasks = [
        asyncio.create_task(blink(cols[0], 0.5)),
        asyncio.create_task(blink(cols[1], 0.8)),
        asyncio.create_task(blink(cols[2], 0.1)),
        asyncio.create_task(blink(cols[3], 0.01)),
        asyncio.create_task(blink(cols[4], 0.05)),
    ]

    for t in tasks:
        await t

asyncio.run(main())
