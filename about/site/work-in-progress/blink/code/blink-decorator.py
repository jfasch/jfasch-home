#!/usr/bin/env python

from stuff_raw2 import *
import asyncio

def program(func):
    def factory(*args, **kwargs):
        def create_coro():
            return func(*args, **kwargs)
        return create_coro
    return factory

@program
async def forever(prog):
    while True:
        await prog()

@program
async def blink(ios, interval, ntimes=None):
    loop = (ntimes is None) and itertools.count() or range(ntimes)
    for _ in loop:
        SET_VALUES(ios, 1)
        await asyncio.sleep(interval)
        SET_VALUES(ios, 0)
        await asyncio.sleep(interval)

prog = forever(
    blink((11,), 0.3, 1),
)
        
asyncio.run(prog())
