class Timer:
    def __init__(self, hour, minute, second):
        self.hour = hour
        self.minute = minute
        self.second = second

    def __str__(self):
        return f'{self.hour:02}:{self.minute:02}:{self.second:02}'

    def next_second(self):
        self.second += 1

        

        
t = Timer(23, 59, 59)
print(t)
