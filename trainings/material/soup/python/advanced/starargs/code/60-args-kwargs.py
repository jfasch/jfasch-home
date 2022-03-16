def f(*args, **kwargs):
    print('args:', args)
    print('kwargs:', kwargs)

f(1, 2, 3, a=7, b=42, c='hallo', blah={'eins', 'zwei'})
