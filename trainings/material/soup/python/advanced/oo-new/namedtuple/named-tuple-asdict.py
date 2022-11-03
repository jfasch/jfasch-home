from collections import namedtuple

Person = namedtuple('Person', ('firstname', 'lastname'))

person = Person('Joerg', 'Faschingbauer')
person_dict = person._asdict()
print(person_dict)
