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

    @lastname.setter
    def lastname(self, n):
        if n == 'Haubentaucher':
            self._lastname = n
        else:
            raise AttributeError('no!')

person = Person('Joerg', 'Faschingbauer')
person.lastname = 'Haubentaucher'

try:
    person.lastname = 'Meier'
except AttributeError:
    print('no!')
