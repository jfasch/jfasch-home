import userdb

def test_read_userobjs_from_colon_separated_values():
    input = [
        '666:Jörg:Faschingbauer:1966-06-19\n',
        '42:Caro:Faschingbauer:1997-04-25\n',
        '7:Johanna:Faschingbauer:1995-06-11\n',
        '1024:Philipp:Lichtenberger:1986-04-06\n',
    ]

    persons = userdb.read_userobjs_from_colon_separated_values(input)

    assert persons[0].id == 666
    assert persons[0].firstname == 'Jörg'
    assert persons[0].lastname == 'Faschingbauer'
    assert persons[0].birth == '1966-06-19'

    assert persons[1].id == 42
    assert persons[1].firstname == 'Caro'
    assert persons[1].lastname == 'Faschingbauer'
    assert persons[1].birth == '1997-04-25'

    assert persons[2].id == 7
    assert persons[2].firstname == 'Johanna'
    assert persons[2].lastname == 'Faschingbauer'
    assert persons[2].birth == '1995-06-11'

    assert persons[3].id == 1024
    assert persons[3].firstname == 'Philipp'
    assert persons[3].lastname == 'Lichtenberger'
    assert persons[3].birth == '1986-04-06'
