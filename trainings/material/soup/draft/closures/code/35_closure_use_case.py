def create_f():
    intermediate = 1
    def f():
        print('f called, intermediate =', intermediate)
    return f

# inner = create_f()
# inner()

def print_it(msg):
    def _p():
        print(msg)
    return _p

blah = print_it('blah')
something = print_it('something')

blah()
something()
