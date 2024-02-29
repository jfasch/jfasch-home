#!/usr/bin/env python

import gpiod
import time

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

REQUEST.set_values({i: gpiod.line.Value(1) for i in ALL_IOS})
time.sleep(0.5)
REQUEST.set_values({i: gpiod.line.Value(0) for i in ALL_IOS})
