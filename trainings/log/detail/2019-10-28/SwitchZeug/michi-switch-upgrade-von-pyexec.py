#!/usr/bin/python

import sys

switchlist = sys.argv[1]
switchimages = sys.argv[2]

with open(switchimages) as f:
    fw_defs = {}
    exec(f.read(), fw_defs)

print('sw_2960', fw_defs['sw_2960'])
print('sw_2960s', fw_defs['sw_2960s'])
print('sw_2960x', fw_defs['sw_2960x'])
print('sw_2960cx', fw_defs['sw_2960cx'])
print('sw_2960cg', fw_defs['sw_2960cg'])
print('sw_3560cx', fw_defs['sw_3560cx'])
