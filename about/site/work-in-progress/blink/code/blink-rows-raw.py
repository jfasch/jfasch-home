#!/usr/bin/env python

from stuff_raw import *
import asyncio

async def main():
    rows = MATRIX

    tasks = [
        asyncio.create_task(blink(rows[0], 0.5)),
        asyncio.create_task(blink(rows[1], 0.8)),
        asyncio.create_task(blink(rows[2], 0.1)),
        asyncio.create_task(blink(rows[3], 0.01)),
        asyncio.create_task(blink(rows[4], 0.05)),
    ]

    for t in tasks:
        await t

asyncio.run(main())
