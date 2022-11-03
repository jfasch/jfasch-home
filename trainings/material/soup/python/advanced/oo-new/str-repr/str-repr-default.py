class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

person = Person('Joerg', 'Faschingbauer')
print('str(person):', str(person))
print('person:', person)          # <--- str() on object

print('repr(person):', repr(person))
print('[person]:', [person])      # <--- repr() on list elements
