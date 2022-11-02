class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname
        
    def say_hello(self, phrase='Hello, my name is'):
        return f'{phrase} {self.firstname} {self.lastname}'

joerg = Person('Joerg', 'Faschingbauer')
greeting1 = joerg.say_hello()              # <--- call method on joerg
greeting2 = joerg.say_hello("Howdy, I'm")  # <--- call method on joerg

print('Greeting 1:', greeting1)
print('Greeting 2:', greeting2)
