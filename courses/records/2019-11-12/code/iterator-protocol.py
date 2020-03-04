#!/usr/bin/python

import sys

class MeinGanzesGlump:
    def __init__(self):
        self.__glump = {}

    def add_glump(self, name, glump):
        if name in self.__glump:
            raise RuntimeError('glump {} schon drin'.format(name))
        self.__glump[name] = glump

    def __iter__(self):
        return iter(self.__glump.values())

glumphaufen = MeinGanzesGlump()
glumphaufen.add_glump('dies', [1,2,3])
glumphaufen.add_glump('sys.path', sys.path)
glumphaufen.add_glump('das', {1:'one', 2:'two'})
glumphaufen.add_glump('sonstnochwas', 42)

for glump in glumphaufen:
    print(glump)
