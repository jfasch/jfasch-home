def create_f():
    intermediate = 1
    def f():
        print('inner f called, intermediate =', intermediate)
    return f

inner = create_f()
inner()
