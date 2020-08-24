def decorator(func):
    def wrapper():
        print('wrapper called, func =', func.__name__)
        return func()
    return wrapper

@decorator
def f1():
    print('f1 called')
    return 1

@decorator
def f2():
    print('f2 called')
    return 2

print('f1 returned', f1())
print('f2 returned', f2())
