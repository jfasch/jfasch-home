class WeekDayError(Exception):
    pass

class Weeker:
    weekdays = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']

    def __init__(self, day):
        try:
            self.day_n = self.weekdays.index(day)
        except ValueError as e:
            raise WeekDayError()

    def __str__(self):
        return self.weekdays[self.day_n]

    def add_days(self, n):
        self.day_n += n
        self.day_n %= 7


# print(Weeker.weekdays)

# w = Weeker('Sun')
# print(w)
# w.add_days(13)
# print(w)

try:
    Weeker('Monday')
except WeekDayError as e:
    print(type(e), e)
