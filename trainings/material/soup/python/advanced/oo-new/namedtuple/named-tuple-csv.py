from collections import namedtuple

persons_from_csv = [
    ['Joerg', 'Faschingbauer'],
    ['Caro', 'Faschingbauer'],
]

Person = namedtuple('Person', ('firstname', 'lastname'))
for person in map(Person._make, persons_from_csv):
    print('Firstname:', person.firstname)
    print('Lastname:', person.lastname)
