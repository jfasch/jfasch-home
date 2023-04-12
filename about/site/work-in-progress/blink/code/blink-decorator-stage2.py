#!/usr/bin/env python

from stuff_decorator_stage2 import *
import asyncio
import numpy


cols = numpy.transpose(MATRIX).tolist()

prog = forever(
    all([
        blink(cols[0], 0.1, 1),
        blink(cols[1], 0.2, 1),
        blink(cols[2], 0.3, 1),
        blink(cols[3], 0.4, 1),
        blink(cols[4], 0.5, 1),
    ])
)

asyncio.run(prog())
