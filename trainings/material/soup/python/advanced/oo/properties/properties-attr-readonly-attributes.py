class Person:
    def __init__(self, firstname, lastname):
        self._firstname = firstname
        self._lastname = lastname

    @property
    def firstname(self):
        return self._firstname

    @property
    def lastname(self):
        return self._lastname

person = Person('Joerg', 'Faschingbauer')

try:
    person.lastname = 'Haubentaucher'
except AttributeError:
    print('no!')
