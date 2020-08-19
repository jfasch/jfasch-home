def create_f():
    def f():
        print('inner f called')
    return f

inner = create_f()
inner()
