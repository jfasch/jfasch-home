class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    @property
    def fullname(self):
        return f'{self.firstname} {self.lastname}'

person = Person('Joerg', 'Faschingbauer')
print(person.fullname)
