#!/usr/bin/python

from SwitchZeug.switch import Switch
from SwitchZeug.interface import Interface

import datetime


meine_interfaces = [
    Interface(name='if1', number=1, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
              last_change=datetime.datetime(year=2019, month=11, day=20, hour=13, minute=17, second=33)),
    Interface(name='if2', number=2, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
              last_change=datetime.datetime(year=2019, month=11, day=20, hour=13, minute=17, second=33)),
]
mein_switch = Switch('sw01', interfaces=meine_interfaces, uptime=datetime.timedelta(seconds=1))

alle_switches = [
    mein_switch,
    Switch('sw05', interfaces=[], uptime=datetime.timedelta(seconds=1)),
    Switch('sw07', interfaces=[], uptime=datetime.timedelta(seconds=1)),
    Switch('sw42', interfaces=[], uptime=datetime.timedelta(seconds=1)),
    Switch('sw28', interfaces=[], uptime=datetime.timedelta(seconds=1)),
]

for sw in alle_switches:
    print(sw)
