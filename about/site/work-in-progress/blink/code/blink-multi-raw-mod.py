#!/usr/bin/env python

from stuff_raw import *          # <-- this is not about "clean code"
import asyncio

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
