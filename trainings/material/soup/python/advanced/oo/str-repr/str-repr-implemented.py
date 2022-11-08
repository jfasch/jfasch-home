class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def __str__(self):
        return f'{self.firstname} {self.lastname}'

    def __repr__(self):
        return f'Person("{self.firstname}", "{self.lastname}")'

person = Person('Joerg', 'Faschingbauer')
print('str(person):', str(person))
print('person:', person)          # <--- str() on object

print('repr(person):', repr(person))
print('[person]:', [person])      # <--- repr() on list elements
