#!/usr/bin/python

def f(obj):
    obj += 42

a = 7
f(a)
print(a)  # still 7

class Integer:
    def __init__(self, val):
            self.val = val
    def __iadd__(self, val):
            self.val += val
            return self

x = X(7)
f(x)
print(x.val)  # modified
