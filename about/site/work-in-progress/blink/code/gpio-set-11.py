#!/usr/bin/env python

import gpiod

REQUEST = gpiod.request_lines(
    '/dev/gpiochip0',
    consumer='mytest',
    config={(11,): gpiod.LineSettings(direction=gpiod.line.Direction.OUTPUT)})

REQUEST.set_value(11, gpiod.line.Value(1))
