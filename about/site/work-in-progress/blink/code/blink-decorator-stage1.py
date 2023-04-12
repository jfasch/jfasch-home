#!/usr/bin/env python

from stuff_decorator_stage1 import *
import asyncio

async def forever(factory):
    while True:
        await factory()                  # <--- call to create_coro()

async def blink(ios, interval, ntimes=None):
    loop = (ntimes is None) and itertools.count() or range(ntimes)
    for _ in loop:
        SET_VALUES(ios, 1)
        await asyncio.sleep(interval)
        SET_VALUES(ios, 0)
        await asyncio.sleep(interval)

def create_factory_for_blink(blinkfunc):
    def factory(ios, interval, ntimes=None):
        def create_coro():
            return blinkfunc(ios, interval, ntimes)
        return create_coro
    return factory

blink = create_factory_for_blink(blink)  # <--- turn blink into blink-factory

async def main():
    await forever(
        blink((11,), 0.3, 1),            # <--- use blink-factory to instantiate coroutine
    )

asyncio.run(main())
