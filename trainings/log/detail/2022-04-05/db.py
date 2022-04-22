import json


def read_mytable_from_database():
    table = {
        1: { 'umsatz': 66,
             'menge': 42,},
        2: { 'umsatz': 4567,
             'menge': 1234},
    }
        
    return table

def mytable_from_json(s):
    return json.loads(s)

def mytable_to_json():
    daten = read_mytable_from_database()
    austausch_string = json.dumps(daten)
    return austausch_string

