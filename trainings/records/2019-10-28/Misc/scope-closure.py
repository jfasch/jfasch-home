#!/usr/bin/python3

# closure: at the time of function creation (execution of the 'def
# statement), all referenced names are captured to form an
# intermediate scope, the 'closure'

def create_function(parameter):
    loc = 42

    # at this point, we have two variables in local scope - 'loc' and
    # 'parameter'.
    print('create_function: loc={}, parameter={}'.format(loc, parameter))

    # with this in place, create a function object by executing the
    # def statement. note how the function is not executed, but only
    # created/compiled.
    def inner_function():
        # reference variables loc and parameter. these are defined
        # neither in local nor in global scope. but they are found in
        # the enclosing scope - the locals of create_function(), which
        # forms an intermediate scope, the 'closure', whic his added
        # to the lookup chain of inner_function().
        print('parameter {}, loc {}'.format(parameter, loc))

    return inner_function

f_one = create_function('one')
f_one()
f_two = create_function('two')
f_two()
