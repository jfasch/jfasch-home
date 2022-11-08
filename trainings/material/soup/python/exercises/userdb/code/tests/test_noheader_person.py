import userdb_csv


def test_noheader_person(tmpdir):
    with open(tmpdir/'noheader.csv', 'w', encoding='cp1252') as f:
        f.writelines([
            '1;"Jörg;DI";Faschingbauer;19.6.1966\n',
            '2;Caro;Faschingbauer;25.4.1997\n',
            '3;Johanna;Faschingbauer;11.6.1995\n',
            '4;Philipp;Lichtenberger;6.4.1986\n',
            '5;Elizabeth II;Queen;1.1.1900\n',
        ])

    users = list(userdb_csv.read_noheader_person(tmpdir/'noheader.csv'))

    assert type(users[0]) is userdb_csv.Person
    assert users[0].id == 1
    assert users[0].firstname == 'Jörg;DI'
    assert users[0].lastname == 'Faschingbauer'
    assert users[0].birth == '19.6.1966'

    assert type(users[1]) is userdb_csv.Person
    assert users[1].id == 2
    assert users[1].firstname == 'Caro'
    assert users[1].lastname == 'Faschingbauer'
    assert users[1].birth == '25.4.1997'

    assert type(users[2]) is userdb_csv.Person
    assert users[2].id == 3
    assert users[2].firstname == 'Johanna'
    assert users[2].lastname == 'Faschingbauer'
    assert users[2].birth == '11.6.1995'

    assert type(users[3]) is userdb_csv.Person
    assert users[3].id == 4
    assert users[3].firstname == 'Philipp'
    assert users[3].lastname == 'Lichtenberger'
    assert users[3].birth == '6.4.1986'

    assert type(users[4]) is userdb_csv.Person
    assert users[4].id == 5
    assert users[4].firstname == 'Elizabeth II'
    assert users[4].lastname == 'Queen'
    assert users[4].birth == '1.1.1900'

def test_must_not_use_global_variables_as_return_object(tmpdir):
    filename1 = tmpdir/'noheader1.csv'
    with open(filename1, 'w', encoding='cp1252') as f:
        f.writelines([
            '1;"Jörg;DI";Faschingbauer;19.6.1966\n',
            '2;Caro;Faschingbauer;25.4.1997\n',
            '3;Johanna;Faschingbauer;11.6.1995\n',
            '4;Philipp;Lichtenberger;6.4.1986\n',
            '5;Elizabeth II;Queen;1.1.1900\n',
        ])

    filename2 = tmpdir/'noheader2.csv'
    with open(filename2, 'w', encoding='cp1252') as f:
        f.writelines([
            '3;Johanna;Faschingbauer;11.6.1995\n',
            '4;Philipp;Lichtenberger;6.4.1986\n',
            '5;Elizabeth II;Queen;1.1.1900\n',
        ])

    users1 = list(userdb_csv.read_noheader_person(filename1))
    users2 = list(userdb_csv.read_noheader_person(filename2))

    assert len(users1) == 5
    assert len(users2) == 3
