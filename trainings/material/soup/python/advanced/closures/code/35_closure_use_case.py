def print_it(msg):
    def _p():
        print(msg)
    return _p

blah = print_it('blah')
something = print_it('something')

blah()
something()
