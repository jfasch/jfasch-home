#!/usr/bin/env python

import gpiod

request = gpiod.request_lines(
    '/dev/gpiochip0',
    consumer='mytest',
    config={(11,): gpiod.LineSettings(direction=gpiod.line.Direction.OUTPUT)})

request.set_value(11, gpiod.line.Value(1))
