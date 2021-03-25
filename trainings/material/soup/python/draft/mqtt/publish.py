#!/usr/bin/env python

from paho.mqtt import client

c = client.Client()
c.connect('localhost', 1883)
c.publish('/random/topic', 'blech')
