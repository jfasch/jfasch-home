#!/usr/bin/python

def debug(f):
    def wrapped(*args, **kwargs):
        print('calling:', f, 'posargs:', args, 'kwargs:', kwargs)
        return f(*args, **kwargs)
    return wrapped

@debug
def f(n):
    print(n)

@debug
def g(i, j, k):
    print(i,j,k)

f(42)
g(i=1,j=2,k=3)
