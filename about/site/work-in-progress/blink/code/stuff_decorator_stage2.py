import asyncio
import gpiod
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

@program
async def all(progs):
    tasks = [asyncio.create_task(p()) for p in progs]
    for t in tasks:
        await t

@program
async def sequence(progs):
    for p in progs:
        await p()
