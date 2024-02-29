#!/usr/bin/env python

import asyncio

async def hello_left():
    for _ in range(5):
        print('hello left')
        await asyncio.sleep(0.5)

async def hello_right():
    for _ in range(5):
        print('hello right'.rjust(60))
        await asyncio.sleep(0.8)

async def hello_middle():
    for _ in range(4):
        print('hello middle'.center(60))
        await asyncio.sleep(1)

async def main():
    t1 = asyncio.create_task(hello_left())
    t2 = asyncio.create_task(hello_middle())
    t3 = asyncio.create_task(hello_right())

    await t1
    await t2
    await t3

asyncio.run(main())
