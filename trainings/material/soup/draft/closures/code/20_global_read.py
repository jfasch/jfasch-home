g = 1

def create_f():
    def f():
        print('inner f called, g =', g)
    return f

inner = create_f()
inner()
