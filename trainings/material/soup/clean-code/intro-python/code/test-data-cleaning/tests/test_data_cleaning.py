from stuff.conversions import make_float, clean_data
import pandas as pd
import numpy as np


def test_make_float():
    crap = '2.000,00'
    amount = make_float(crap)

    assert 1999.9 < amount < 2000.1

def test_date_conversion():
    df = pd.DataFrame({
        'account': ['AT666666666666666666'],
        'info': ['Abbuchung Onlinebanking                      BG/000009173|BAWAATWWXXX AT211420020010848041|DI Hansjörg Faschingbauer|Ausgleich Firmenkonto'],
        'time_booked': ['02.01.2023'],
        'time_valuta': ['02.01.2023'],
        'amount': ['-400,00'],
        'unit': ['EUR']
    })

    df = clean_data(df)

    assert type(df['time_booked'].iloc[0]) is pd.Timestamp
