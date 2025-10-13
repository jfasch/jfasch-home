import userdb
import io
import json

def test_write_users_to_json():
    users_out = [
        {
            'id': 666,
            'firstname': 'Jörg',
            'lastname': 'Faschingbauer',
            'birth': '1966-06-19',
        },
        {
            'id': 42,
            'firstname': 'Caro',
            'lastname': 'Faschingbauer',
            'birth': '1997-04-25',
        },
        {
            'id': 7,
            'firstname': 'Johanna',
            'lastname': 'Faschingbauer',
            'birth': '1995-06-11',
        },
        {
            'id': 1024,
            'firstname': 'Philipp',
            'lastname': 'Lichtenberger',
            'birth': '1986-04-06',
        },
    ]

    output = io.StringIO()                             # <-- file-like, for output
    userdb.write_users_to_json(users_out, output)

    input = io.StringIO(output.getvalue())             # <-- file-like, for input
    users_in = json.load(input)

    assert users_out[0] == users_in[0]
    assert users_out[1] == users_in[1]
    assert users_out[2] == users_in[2]
    assert users_out[3] == users_in[3]
