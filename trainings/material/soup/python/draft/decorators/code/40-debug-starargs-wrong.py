def debug(func):
    def wrapper():
        print('debug: func =', func.__name__)
        return func()
    return wrapper

@debug
def add(l, r):
    return l+r

@debug
def sub(l, r):
    return l-r

print('add(1,2) returned', add(1,2))
print('sub(1,2) returned', sub(1,2))
