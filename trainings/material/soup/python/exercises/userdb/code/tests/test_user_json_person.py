from userdb_csv import Person
import userdb_json


def test_person_to_json():
    joerg = Person(
        id=1,
        firstname='Jörg',
        lastname='Faschingbauer',
        birth='19.6.1966',
    )

    joerg_sent = userdb_json.to_json_person(joerg)
    joerg_received = userdb_json.from_json_person(joerg_sent)

    assert joerg_received.id == 1
    assert joerg_received.firstname == 'Jörg'
    assert joerg_received.lastname == 'Faschingbauer'
    assert joerg_received.birth == '19.6.1966'    
