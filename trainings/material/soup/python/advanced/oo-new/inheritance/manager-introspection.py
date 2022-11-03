class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

class Employee(Person):
    def __init__(self, firstname, lastname, salary):
        super().__init__(firstname, lastname)
        self.salary = salary

class Manager(Employee):
    def __init__(self, firstname, lastname, salary, employees):
        super().__init__(firstname, lastname, salary)
        self.employees = employees

joerg = Employee('Joerg', 'Faschingbauer', 6000)
print('joerg is-a Employee:', isinstance(joerg, Employee));
print('joerg is-a Person:', isinstance(joerg, Person));
print('joerg is-a Manager:', isinstance(joerg, Manager));

print('Manager is-a Person:', issubclass(Manager, Person))
print('Person is-a Manager:', issubclass(Person, Manager))
print('Person is-a Person:', issubclass(Person, Person))    # <--- well, yes
