#!/usr/bin/env python

import gpiod
import time

REQUEST = gpiod.request_lines(
    '/dev/gpiochip0',
    consumer='mytest',
    config={(11,10,27): gpiod.LineSettings(direction=gpiod.line.Direction.OUTPUT)})

REQUEST.set_values({11: gpiod.line.Value(1),
                    10: gpiod.line.Value(1),
                    27: gpiod.line.Value(1),
                   })

time.sleep(1)

REQUEST.set_values({11: gpiod.line.Value(0),
                    10: gpiod.line.Value(0),
                    27: gpiod.line.Value(0),
                   })

