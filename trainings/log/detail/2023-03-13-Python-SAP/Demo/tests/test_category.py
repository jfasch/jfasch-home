from stuff.category import categorize

def test_basic():
    info = r'Bezahlung Karte                              MC/000009258|POS          2800  K002 07.02. 12:34|SPAR DANKT 5362\\GRAZ\8020'
    cat = categorize(info)
    assert cat == 'living'
