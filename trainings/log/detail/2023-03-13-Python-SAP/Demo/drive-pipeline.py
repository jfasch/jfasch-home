#!/usr/bin/env python

import sys
import pandas as pd


csvname = sys.argv[1]
pipe_stages = sys.argv[2:]

data = pd.read_csv(
    csvname, 
    sep=';', encoding='iso-8859-1', 
    names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))


for ps in pipe_stages:
    context = {}
    exec('import pandas as pd', context)
    exec('import numpy as np', context)

    code = open(ps).read()
    exec(code, context)

    transform = context['transform']

    data = transform(data)


pd.options.display.max_colwidth = None
pd.options.display.max_columns = None
pd.options.display.max_rows = None
pd.options.display.width = None

print(data)
