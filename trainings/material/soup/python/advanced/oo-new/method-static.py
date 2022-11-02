class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname
        
    @staticmethod
    def make_child(firstname, parent1, parent2):
        # ---- vvvvvv --- hardwiring class Person
        return Person(firstname, f'{parent1.lastname}-{parent2.lastname}')
    
    def say_hello(self, phrase='Hello, my name is'):
        return f'{phrase} {self.firstname} {self.lastname}'


mother = Person('Isolde', 'Haubentaucher')
father = Person('Joerg', 'Faschingbauer')

child = Person.make_child('Alex', mother, father)

child.say_hello()
