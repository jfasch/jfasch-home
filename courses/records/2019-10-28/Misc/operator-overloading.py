#!/usr/bin/python3

# question: from C++ I know that I can overload (arithmetic) operators
# for types/classes that I define. how is this done in Python?

class Integer:
    def __init__(self, n):
        self.__n = n

    @property
    def n(self):
        return self.__n

    def __lt__(self, rhs):
        return self.__n < rhs.__n

    def __le__(self, rhs):
        return not self > rhs

    def __eq__(self, rhs):
        return self.__n == rhs.__n

    def __iadd__(self, n):
        'iadd: +=, "in-place add"'
        self.__n += n
        return self

    def __add__(self, n):
        'add: +, called on self, the right hand "a" side in "a+b"'
        new_number = self.__n + n
        return Integer(new_number)

    def __radd__(self, n):
        'radd: +, called on the right hand side if the lhs does not support it'
        new_number = n + self.__n
        return Integer(new_number)

x = Integer(1)
y = Integer(2)

print('1<2', x < y)
print('2<1', y < x)
print('1>2', x > y)
print('1==1', x == x)
print('1!=1', x != x)
print('1<=2', x <= y)
print('1<=1', x <= x)

x += 1
print(x.n)

z = x + 1
print(z.n)

z = 1 + x
print(z.n)
