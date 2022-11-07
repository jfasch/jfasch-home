import csv


def read_csv_noheader(filename):
    f = open(filename, encoding='cp1252')
    rdr = csv.reader(f, delimiter=';', quotechar='"')

    persons = []
    
    for id, firstname, lastname, birth in rdr:
        persons.append({
            'id': int(id),
            'firstname': firstname,
            'lastname': lastname,
            'birth': birth,
        })

    return persons

def read_csv_header(filename):
    f = open(filename, encoding='cp1252')
    rdr = csv.DictReader(f, delimiter=';', quotechar='"')

    persons = []
    
    for pdict in rdr:
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
