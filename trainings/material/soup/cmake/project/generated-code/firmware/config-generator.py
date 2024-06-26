#!/usr/bin/env python

from configparser import ConfigParser
import sys


infile = sys.argv[1]
outfile = sys.argv[2]


config = ConfigParser()
config.read(infile)

includes = set()
sensors = {}  # { 'name': sensor }

for name, section in config.items():
    if name == 'DEFAULT':
        continue
    ty = section.get('type')
    if ty is None:
        print(f'section "{name}" has no "Type" attribute', file=sys.stderr)
        continue
    if ty == 'Const':
        value = section.get('value')
        if value is None:
            print(f'section "{name}" is of type "Const", but has no "Value" attribute', file=sys.stderr)
            continue
        includes.add('sensor-const.h')
        sensors[name] = ('ConstantSensor', (value,))
        continue
    if ty == 'Random':
        low = section.get('low')
        if low is None:
            print(f'section "{name}" is of type "Random", but has no "Low" attribute', file=sys.stderr)
            continue
        high = section.get('high')
        if high is None:
            print(f'section "{name}" is of type "Random", but has no "High" attribute', file=sys.stderr)
            continue
        includes.add('sensor-random.h')
        sensors[name] = ('RandomSensor', (low, high))
        continue

    print(f'section "{name}" is of unknown type "{ty}"', file=sys.stderr)
    

content = """
#include "conf-sensors.h"

"""

for inc in includes:
    content += f'#include <{inc}>\n'

content += """
SensorConfig conf_sensors;

namespace {

struct conf_sensors_init
{
    conf_sensors_init()
    {
"""

for name, (ctor, args) in sensors.items():
    argstr = ','.join(args)
    stmt = f'        conf_sensors.add_sensor("{name}", std::make_unique<{ctor}>({argstr}));\n';
    content += stmt;

content += """
    };
};

conf_sensors_init init;
};
"""

with open(outfile, 'w') as f:
    f.write(content)
