#!/usr/bin/python3

import sys

import queue


q = queue.Queue(sys.argv[1])
messwerte_von_beginn_an = q.extract(0)

assert len(messwerte_von_beginn_an) == 9
assert len(messwerte_von_beginn_an[0]) == 4
