class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def fullname(self):
        return f'{self.firstname} {self.lastname}'

class Employee(Person):
    pass

emp = Employee('Joerg', 'Faschingbauer')
print(emp.fullname())
