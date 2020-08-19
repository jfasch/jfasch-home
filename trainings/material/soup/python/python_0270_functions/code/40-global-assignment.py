x = 666

def f():
    global x
    x = 1
    print('assigned global:', x)

f()
print('global:', x)
