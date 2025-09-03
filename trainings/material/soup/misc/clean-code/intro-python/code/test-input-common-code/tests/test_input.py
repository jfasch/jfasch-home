from stuff.input import read_from_csv_single, read_from_csv_multiple

import pytest

def _write_csv(csvname, lines):
    with open(csvname, 'w', encoding='iso-8859-1') as csv:
        csv.writelines([l+'\n' for l in lines])

def test_read_csv_single(tmpdir):
    _write_csv(
        tmpdir / '2023-02.csv',
        [
            r'AT666666666666666666;Bezahlung Karte                              MC/000009284|ORPHEUM BAR  2371  K002 28.02. 21:14|ORPHEUM BAR\\GRAZ\8020      ST;01.03.2023;28.02.2023;-7,40;EUR',
            r'AT666666666666666666;95111243                                     FE/000009283|AT613400000005077508 World4You Internet Services GmbH;28.02.2023;28.02.2023;-29,90;EUR',
        ])

    df = read_from_csv_single(tmpdir / '2023-02.csv')
    
    assert df['info'].iloc[0] == r'Bezahlung Karte                              MC/000009284|ORPHEUM BAR  2371  K002 28.02. 21:14|ORPHEUM BAR\\GRAZ\8020      ST'
    assert df['info'].iloc[1] == r'95111243                                     FE/000009283|AT613400000005077508 World4You Internet Services GmbH'

def test_read_csv_multiple(tmpdir):
    _write_csv(
        tmpdir / '2023-02.csv',
        [
            r'AT666666666666666666;Bezahlung Karte                              MC/000009284|ORPHEUM BAR  2371  K002 28.02. 21:14|ORPHEUM BAR\\GRAZ\8020      ST;01.03.2023;28.02.2023;-7,40;EUR',
            r'AT666666666666666666;95111243                                     FE/000009283|AT613400000005077508 World4You Internet Services GmbH;28.02.2023;28.02.2023;-29,90;EUR',
        ])
    _write_csv(
        tmpdir / '2023-01.csv',
        [
            r'AT666666666666666666;Bezahlung Karte                              MC/000009229|POS          4111  K002 30.01. 19:23|BP TANKSTELLE\\GRAZ\8010;31.01.2023;30.01.2023;-15,75;EUR',
            r'AT666666666666666666;120016487112                                 BG/000009228|BAWAATWWXXX AT081400086210003454|Österreichische Gesundheitskasse;31.01.2023;31.01.2023;-12,43;EUR',
        ])

    df = read_from_csv_multiple([tmpdir / '2023-02.csv', tmpdir / '2023-01.csv'])

    assert df['info'].iloc[0] == r'Bezahlung Karte                              MC/000009284|ORPHEUM BAR  2371  K002 28.02. 21:14|ORPHEUM BAR\\GRAZ\8020      ST'
    assert df['info'].iloc[1] == r'95111243                                     FE/000009283|AT613400000005077508 World4You Internet Services GmbH'

    assert df['info'].iloc[2] == r'Bezahlung Karte                              MC/000009229|POS          4111  K002 30.01. 19:23|BP TANKSTELLE\\GRAZ\8010'
    assert df['info'].iloc[3] == r'120016487112                                 BG/000009228|BAWAATWWXXX AT081400086210003454|Österreichische Gesundheitskasse'
