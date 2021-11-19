import csv
import datetime


def fix_float_number(record, fieldname):
    old = record[fieldname]
    old = old.replace(',', '.')
    new = float(old)
    record[fieldname] = new

def fix_bool(record, fieldname):
    old = record[fieldname]
    if old == 'T':
        new = True
    elif old == 'F':
        new = False
    else:
        new = True
    record[fieldname] = new

def fix_date(record, fieldname):
    old = record[fieldname]
    new = datetime.datetime.strptime(old, '%Y%m%d')
    record[fieldname] = new

def read_csv(filename):
    csvfile = open(filename)
    rdr = csv.DictReader(csvfile, delimiter=';')

    converted_records = []
    for record in rdr:
        fix_date(record, 'AS_OF_DATE')
        fix_bool(record, 'FUND_IN_UNIVERSE')
        fix_bool(record, 'FUND_OF_FUNDS')
        fix_float_number(record, 'FUND_HOLDINGS_COUNT')
        fix_float_number(record, 'FUND_HOLDING_FUNDS_COUNT')
        converted_records.append(record)

    return converted_records
