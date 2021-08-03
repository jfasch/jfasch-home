x = 666

def f():
    x = 1
    print('local:', x)

f()
print('global:', x)
