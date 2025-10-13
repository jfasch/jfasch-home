import userdb
import io
import json

def test_write_users_to_json():
    users_out = [
        userdb.User(id=666,
                    firstname = 'Jörg',
                    lastname = 'Faschingbauer',
                    birth = '1966-06-19',
                    ),
        userdb.User(id = 42,
                    firstname = 'Caro',
                    lastname = 'Faschingbauer',
                    birth = '1997-04-25',
                    ),
        userdb.User(id = 7,
                    firstname = 'Johanna',
                    lastname = 'Faschingbauer',
                    birth = '1995-06-11',
                    ),
        userdb.User(id = 1024,
                    firstname = 'Philipp',
                    lastname = 'Lichtenberger',
                    birth = '1986-04-06',
                    ),
    ]

    output = io.StringIO()
    userdb.write_userobjs_to_json(users_out, output)

    input = io.StringIO(output.getvalue())
    users_in = json.load(input)

    assert users_out[0].id == users_in[0]['id']
    assert users_out[0].firstname == users_in[0]['firstname']
    assert users_out[0].lastname == users_in[0]['lastname']
    assert users_out[0].birth == users_in[0]['birth']

    assert users_out[1].id == users_in[1]['id']
    assert users_out[1].firstname == users_in[1]['firstname']
    assert users_out[1].lastname == users_in[1]['lastname']
    assert users_out[1].birth == users_in[1]['birth']

    assert users_out[2].id == users_in[2]['id']
    assert users_out[2].firstname == users_in[2]['firstname']
    assert users_out[2].lastname == users_in[2]['lastname']
    assert users_out[2].birth == users_in[2]['birth']

    assert users_out[3].id == users_in[3]['id']
    assert users_out[3].firstname == users_in[3]['firstname']
    assert users_out[3].lastname == users_in[3]['lastname']
    assert users_out[3].birth == users_in[3]['birth']
