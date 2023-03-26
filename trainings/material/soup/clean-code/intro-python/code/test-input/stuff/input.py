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
