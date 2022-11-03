class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def fullname(self):
        return f'{self.firstname} {self.lastname}'

    __str__ = fullname

class Employee(Person):
    def __init__(self, firstname, lastname, salary):
        super().__init__(firstname, lastname)
        self.salary = salary

    def title(self):
        return f'{self.fullname()} ({self.salary})'

    __str__ = title

class Manager(Employee):
    def __init__(self, firstname, lastname, salary, employees):
        super().__init__(firstname, lastname, salary) # <--- Employee.__init__()
        self.employees = employees

    def add_employee(self, employee):
        self.employees.append(employee)

    def title(self):
        title = super().title()
        return title + f' (manages {len(self.employees)} employees)'

    __str__ = title

joerg = Employee('Joerg', 'Faschingbauer', 6000)
mgr = Manager('Isolde', 'Haubentaucher', 10000, [joerg])
caro = Employee('Caro', 'Faschingbauer', 5000)
mgr.add_employee(caro)

print('joerg:', joerg)
print('mgr:', mgr)
