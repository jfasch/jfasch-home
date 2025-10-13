import userdb

def test_read_users_from_colon_separated_values():
    input = [                                          # <-- file-like (iterable)
        '666:Jörg:Faschingbauer:1966-06-19\n',
        '42:Caro:Faschingbauer:1997-04-25\n',
        '7:Johanna:Faschingbauer:1995-06-11\n',
        '1024:Philipp:Lichtenberger:1986-04-06\n',
    ]

    users = userdb.read_users_from_colon_separated_values(input)

    assert len(users) == 4

    assert users[0]['id'] == 666
    assert users[0]['firstname'] == 'Jörg'
    assert users[0]['lastname'] == 'Faschingbauer'
    assert users[0]['birth'] == '1966-06-19'

    assert users[1]['id'] == 42
    assert users[1]['firstname'] == 'Caro'
    assert users[1]['lastname'] == 'Faschingbauer'
    assert users[1]['birth'] == '1997-04-25'

    assert users[2]['id'] == 7
    assert users[2]['firstname'] == 'Johanna'
    assert users[2]['lastname'] == 'Faschingbauer'
    assert users[2]['birth'] == '1995-06-11'

    assert users[3]['id'] == 1024
    assert users[3]['firstname'] == 'Philipp'
    assert users[3]['lastname'] == 'Lichtenberger'
    assert users[3]['birth'] == '1986-04-06'
