class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname
        
    @classmethod
    def make_child(cls, firstname, parent1, parent2):
        # ---- vvv --- not hardwiring class Person
        return cls(firstname, f'{parent1.lastname}-{parent2.lastname}')
    
    def say_hello(self, phrase='Hello, my name is'):
        return f'{phrase} {self.firstname} {self.lastname}'


mother = Person('Isolde', 'Haubentaucher')
father = Person('Joerg', 'Faschingbauer')

child = Person.make_child('Alex', mother, father)

child.say_hello()
