from stuff.category import categorize, category, Category
from stuff.input import read_from_csv_single
from stuff.conversions import clean_data

from .testutils import write_csv

def test_category_csv(tmpdir):
    write_csv(
        tmpdir / 'file.csv',
        [
            r'AT666666666666666666;Bezahlung Karte MC/000009168|POS 2800  K002 27.12. 09:33|SPAR DANKT 5362\\GRAZ\8020;28.12.2022;27.12.2022;-8,06;EUR',
            r'AT666666666666666666;Bezahlung Karte MC/000009169|POS 2801  K002 23.12. 14:02|STRASSENBAHN GRAZ\\GRAZ\8010;28.12.2022;23.12.2022;-2,70;EUR',
        ]
    )

    df = read_from_csv_single(tmpdir / 'file.csv')
    df = clean_data(df)
    df = categorize(df)

    assert df['category'].iloc[0] == 'living'
    assert df['category'].iloc[1] == 'card-unknown'

def test_more_of_it():
    assert Category.Car == category(r'Bezahlung Karte                              MC/000009153|POS          2802  K002 19.12. 02:00|FLUGHAFEN WIEN PARKEN\\WIEN-FL')
