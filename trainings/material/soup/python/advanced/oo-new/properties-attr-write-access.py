class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

person = Person('Joerg', 'Faschingbauer')
person.lastname = 'Haubentaucher'      # <--- write access possible but unwanted
