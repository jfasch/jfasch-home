class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

person = Person('Joerg', 'Faschingbauer')

print(f'firstname: {person.firstname}, {person.lastname}')
