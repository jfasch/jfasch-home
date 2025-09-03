import pandas as pd


def make_float(s):
    whole, decimal = s.rsplit(',', maxsplit=1)
    whole = whole.replace(',', '')
    whole = whole.replace('.', '')
    return float(f'{whole}.{decimal}')

def clean_data(df):
    df['time_booked'] = pd.to_datetime(df['time_booked'], format='%d.%m.%Y')
    df['time_valuta'] = pd.to_datetime(df['time_valuta'], format='%d.%m.%Y')
    df['amount'] = df['amount'].apply(make_float)
    return df
