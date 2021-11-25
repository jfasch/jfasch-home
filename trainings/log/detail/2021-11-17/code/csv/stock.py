import csv
import datetime

# note: functions prefixed with '_' are not imported when someone says
# "from there import *". those functions are internal to this module,
# so it is good practice to hide them in such a way.

def _fix_float_number(record, fieldname):
    old = record[fieldname]
    old = old.replace(',', '.')
    new = float(old)
    record[fieldname] = new

def _fix_bool(record, fieldname):
    old = record[fieldname]
    if old == 'T':
        new = True
    elif old == 'F':
        new = False
    else:
        new = True
    record[fieldname] = new

def _fix_date(record, fieldname):
    old = record[fieldname]
    new = datetime.datetime.strptime(old, '%Y%m%d')
    record[fieldname] = new

def read_stock(filename):
    csvfile = open(filename)
    rdr = csv.DictReader(csvfile, delimiter=';')

    converted_records = []
    for record in rdr:
        _fix_date(record, 'AS_OF_DATE')
        _fix_bool(record, 'FUND_IN_UNIVERSE')
        _fix_bool(record, 'FUND_OF_FUNDS')
        _fix_float_number(record, 'FUND_HOLDINGS_COUNT')
        _fix_float_number(record, 'FUND_HOLDING_FUNDS_COUNT')
        converted_records.append(record)

    return converted_records
