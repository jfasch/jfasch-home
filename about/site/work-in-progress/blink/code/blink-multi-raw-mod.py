#!/usr/bin/env python

from stuff_raw import *
import asyncio

async def main():
    t1 = asyncio.create_task(blink((11,), 0.5))
    t2 = asyncio.create_task(blink((10,), 0.8))
    t3 = asyncio.create_task(blink((27,), 1))

    await t1
    await t2
    await t3

asyncio.run(main())
