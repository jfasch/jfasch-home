#!/usr/bin/env python

from sensors.sensor_const import ConstantSensor

sensor = ConstantSensor(36.7)
temperature = sensor.get_temperature()
print(temperature)
