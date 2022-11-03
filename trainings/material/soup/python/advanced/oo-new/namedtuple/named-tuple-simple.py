from collections import namedtuple

Person = namedtuple('Person', ('firstname', 'lastname'))

person = Person('Joerg', 'Faschingbauer')
print('Firstname:', person.firstname)
print('Lastname:', person.lastname)
