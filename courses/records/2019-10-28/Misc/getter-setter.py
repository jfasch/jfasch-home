#!/usr/bin/python3

# question: in C# we have getters and setters. how is this done in
# Python?

# answer: use the property *decorator*

class MakesNoSense:
    def __init__(self, number):
        self.__number = number

    @property
    def number(self):
        return self.__number

    @number.setter
    def number(self, n):
        self.__number = n

num = MakesNoSense(42)
print(num.number)
num.number = 666
print(num.number)
