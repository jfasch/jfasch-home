def decorator(func):
    def wrapper():
        print('wrapper called, func =', func.__name__)
        return func()
    return wrapper

def f1():
    print('f1 called')
    return 1

def f2():
    print('f2 called')
    return 2

f1 = decorator(f1)
f2 = decorator(f2)

print('f1 returned', f1())
print('f2 returned', f2())
