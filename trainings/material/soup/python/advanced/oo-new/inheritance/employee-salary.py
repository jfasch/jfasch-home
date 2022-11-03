class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def fullname(self):
        return f'{self.firstname} {self.lastname}'

class Employee(Person):
    def __init__(self, firstname, lastname, salary):
        super().__init__(firstname, lastname)   # <--- Person.__init__()
        self.salary = salary

    def title(self):
        return f'{self.fullname()} ({self.salary})'

emp = Employee('Joerg', 'Faschingbauer', 6000)
print(emp.title())
