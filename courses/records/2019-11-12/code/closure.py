#!/usr/bin/python

def func_creator(n):
    def func():
        print(n)
    return func

f = func_creator(42)
g = func_creator(666)

f()
g()
