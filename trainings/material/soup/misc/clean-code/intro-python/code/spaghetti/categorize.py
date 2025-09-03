INPUTFILE = 'bank.csv'
OUTPUTFILE = 'bank-cat.csv'

import pandas as pd


data = pd.read_csv(
    INPUTFILE, 
    sep=';', encoding='iso-8859-1',
    names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))

data['time_booked'] = pd.to_datetime(data['time_booked'], format='%d.%m.%Y')
data['time_valuta'] = pd.to_datetime(data['time_valuta'], format='%d.%m.%Y')

def make_float(s):
    whole, decimal = s.rsplit(',', maxsplit=1)
    whole = whole.replace(',', '')
    whole = whole.replace('.', '')
    return float(f'{whole}.{decimal}')

data['amount'] = data['amount'].apply(make_float)

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
    
data['category'] = data['info'].apply(make_category)

data.to_csv(
    OUTPUTFILE,
    sep=';', encoding='iso-8859-1',
    index=False,
)
