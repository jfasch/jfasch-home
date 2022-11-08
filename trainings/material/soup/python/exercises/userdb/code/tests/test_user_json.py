import userdb_json


def test_user_to_json():
    user_sent = {
        'id': 1,
        'firstname': 'Jörg',
        'lastname': 'Faschingbauer',
        'birth': '19.6.1966',
    }

    json_user_sent = userdb_json.to_json(user_sent)
    user_received = userdb_json.from_json(json_user_sent)

    assert user_received['id'] == 1
    assert user_received['firstname'] == 'Jörg'
    assert user_received['lastname'] == 'Faschingbauer'
    assert user_received['birth'] == '19.6.1966'    
