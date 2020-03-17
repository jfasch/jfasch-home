#!/usr/bin/python

import sys
import configparser

switchlist = sys.argv[1]
switchimages = sys.argv[2]

config = configparser.ConfigParser()
config.read(switchimages)

for sectionname in config.sections():
    section = config[sectionname]
    print('sectionname:', sectionname)
    print(' '*7, 'image:', section['image'])
    print(' '*7, 'md5:', section['md5'])
    
