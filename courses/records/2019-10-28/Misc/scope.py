#!/usr/bin/python3

# Functions: Local and Global Variables (~92)


def local_assignment():

    '''assign to l in local scope. this creates a local variable
    l. (variables are generally creates at first assignment.)

    '''

    l = 7

def read_global_variable():
    '''accesses a variable g that has never been assigned to in local
    scope. this goes out into the enclosing (global) scope and looks
    it up there.

    '''
    
    print('read_global_variable: g =', g)

def local_shadows_global():

    '''assign to g in local scope. this does *not* assign to the global
    variable g, but creates a local variable g.

    '''

    g = 42
    print('local_shadows_global: g =', g)

def explicit_global_assignment():
    global g

    print('explicit_global_assignment: before assignment g =', g)
    g = 42
    print('explicit_global_assignment: after assignment g =', g)


# first assignment to g in global scope creates g in global scope.
g = 666

local_assignment()
read_global_variable()

local_shadows_global()
print('global g =', g)

explicit_global_assignment()
print('global g =', g)
