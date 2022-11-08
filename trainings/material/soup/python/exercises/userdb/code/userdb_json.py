from userdb_csv import Person

import json


def to_json(pyobj):
    return json.dumps(pyobj)

def from_json(jobj):
    return json.loads(jobj)


def to_json_person(pyobj):
    return json.dumps({
        'id': pyobj.id,
        'firstname': pyobj.firstname,
        'lastname': pyobj.lastname,
        'birth': pyobj.birth,
    })

def from_json_person(jobj):
    pdict = json.loads(jobj)
    return Person(
        id=pdict['id'],
        firstname=pdict['firstname'],
        lastname=pdict['lastname'],
        birth=pdict['birth'])
