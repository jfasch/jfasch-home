from stuff.conversions import clean_data

import sys
import os
import re
import pandas as pd

def read_from_csv(csvname_or_list_thereof):
    if type(csvname_or_list_thereof) is str:
        files = [csvname_or_list_thereof]
    else:     # must be iterable
        files = csvname_or_list_thereof

    ret = pd.DataFrame()
    for csvname in files:
        df = pd.read_csv(
            csvname, 
            sep=';', encoding='iso-8859-1',
            names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))
        ret = pd.concat([ret, df])

    return ret

def read_from_dir(dirname):
    re_yyyy_mm = re.compile(r'^\d\d\d\d-\d\d\.csv')

    names = []
    for name in os.listdir(dirname):
        if re_yyyy_mm.search(name) is not None:
            names.append(os.path.join(dirname, name))

    return read_from_csv(names)      # <--- filename-list version

def write_to_csv(df, csvname):
    df.to_csv(
        csvname,
        sep=';', encoding='iso-8859-1',
        index=False,
    )

def categorize(df):
    def make_category(info):
        if info.startswith('Bezahlung Karte'):
            which, terminal, organization = info.split('|')
    
            if organization.startswith('ORPHEUM BAR'):
                return 'goingout'
            if organization.startswith('BILLA DANKT'):
                return 'living'
            if organization.startswith('HERVIS'):
                return 'sport'
            if organization.startswith('SHELL'):
                return 'car'
            return 'card-unknown'
        else:
            return 'unknown'
        
    df['category'] = df['info'].apply(make_category)
    return df

    
INPUTDIR = sys.argv[1]
OUTPUTFILE = sys.argv[2]

data = read_from_dir(INPUTDIR)
data = clean_data(data)
data = categorize(data)
write_to_csv(data, OUTPUTFILE)

