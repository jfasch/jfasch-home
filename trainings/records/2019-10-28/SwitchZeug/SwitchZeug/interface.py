class Interface:
    UP, DOWN = (1,2)

    def __init__(self, name, number, adminstatus, operstatus, last_change):
        self.name = name
        self.number = number
        self.adminstatus = adminstatus
        self.operstatus = operstatus
        self.last_change = last_change

    def __str__(self):
        return f'Interface({self.name}, {self.number}, {self.adminstatus}, {self.operstatus}, {self.last_change})'
