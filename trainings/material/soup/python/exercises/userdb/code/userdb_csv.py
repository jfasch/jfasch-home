import csv
import collections


Person = collections.namedtuple('Person', ('id', 'firstname', 'lastname', 'birth'))


def _make_reader_noheader(filename):
    f = open(filename, encoding='cp1252')
    return csv.reader(f, delimiter=';', quotechar='"')

def _make_reader_header(filename):
    f = open(filename, encoding='cp1252')
    return csv.DictReader(f, delimiter=';', quotechar='"')


def read_csv_noheader(filename):
    persons = []
    
    for id, firstname, lastname, birth in _make_reader_noheader(filename):
        persons.append({
            'id': int(id),
            'firstname': firstname,
            'lastname': lastname,
            'birth': birth,
        })

    return persons

def read_csv_header(filename):
    persons = []
    
    for pdict in _make_reader_header(filename):
        id = pdict['ID']
        firstname = pdict['First name']
        lastname = pdict['Last name']
        birth = pdict['Date of Birth']

        persons.append({
            'id': int(id),
            'firstname': firstname,
            'lastname': lastname,
            'birth': birth,
        })

    return persons

def read_noheader_person(filename):
    persons = []
    
    for id, firstname, lastname, birth in _make_reader_noheader(filename):
        persons.append(Person(
            id = int(id),
            firstname = firstname,
            lastname = lastname,
            birth = birth,
        ))

    return persons

def read_header_person(filename):
    persons = []
    
    for pdict in _make_reader_header(filename):
        id = pdict['ID']
        firstname = pdict['First name']
        lastname = pdict['Last name']
        birth = pdict['Date of Birth']
        
        persons.append(Person(
            id = int(id),
            firstname = firstname,
            lastname = lastname,
            birth = birth,
        ))

    return persons
