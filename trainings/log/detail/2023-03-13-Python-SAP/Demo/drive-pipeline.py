#!/usr/bin/env python

import sys
import pandas


csvname = sys.argv[1]
pipe_stages = sys.argv[2:]

data = pandas.read_csv(
    csvname, 
    delimiter=';', encoding='iso-8859-1', 
    names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))


for ps in pipe_stages:
    context = {
        'pd': pandas,
    }
    exec('import numpy as np', context)

    code = open(ps).read()
    exec(code, context)

    transform = context['transform']

    data = transform(data)


pandas.options.display.max_colwidth = None
pandas.options.display.max_columns = None
pandas.options.display.max_rows = None
pandas.options.display.width = None

print(data)
