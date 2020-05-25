#!/usr/bin/python

import xsv.dict_extensions

import json, time

data1 = {
    0:'Zero',
    1:'One',
    2:'Two',
    3:'Three',
    4:'Four',
    5:'Five',
    6:'Six',
    7:'Seven',
    8:'Eight',
    9:'Nine'
}

data2 = {}

container = xsv.dict_extensions.well_ordered_dict()
container.add((66, '66-the-name', data1))
container.add((42, '42-the-name', data2))

for _ in range(10):
    data, name = container.get_by_index(66)
    js = json.dumps(data)
    print(js)

time.sleep(2)

for _ in range(10):
    data, name = container.get_by_index(42)
    js = json.dumps(data)
    print(js)
