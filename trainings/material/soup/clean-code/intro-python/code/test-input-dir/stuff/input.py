import re
import os
import pandas


def read_from_csv_single(csvname):
    return pandas.read_csv(
        csvname, 
        sep=';', encoding='iso-8859-1',
        names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))

def read_from_csv_multiple(csvnames):
    ret = pandas.DataFrame()

    for csvname in csvnames:
        ret = pandas.concat([ret, read_from_csv_single(csvname)])

    return ret

def read_from_csv_dir(dirname):
    re_yyyy_mm = re.compile(r'^\d\d\d\d-\d\d\.csv')

    names = []
    for name in os.listdir(dirname):
        if re_yyyy_mm.search(name) is not None:
            names.append(os.path.join(dirname, name))

    return read_from_csv_multiple(names)
