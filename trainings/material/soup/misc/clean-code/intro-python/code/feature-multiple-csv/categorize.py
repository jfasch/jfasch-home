import sys
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

def write_to_csv(df, csvname):
    df.to_csv(
        csvname,
        sep=';', encoding='iso-8859-1',
        index=False,
    )

def clean_data(df):
    df['time_booked'] = pd.to_datetime(df['time_booked'], format='%d.%m.%Y')
    df['time_valuta'] = pd.to_datetime(df['time_valuta'], format='%d.%m.%Y')

    def make_float(s):
        whole, decimal = s.rsplit(',', maxsplit=1)
        whole = whole.replace(',', '')
        whole = whole.replace('.', '')
        return float(f'{whole}.{decimal}')

    df['amount'] = df['amount'].apply(make_float)
    return df

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

    
INPUTFILES = sys.argv[1:-1]
OUTPUTFILE = sys.argv[-1]

data = read_from_csv(INPUTFILES)
data = clean_data(data)
data = categorize(data)
write_to_csv(data, OUTPUTFILE)

