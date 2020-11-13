def debug(func):
    def wrapper(*args, **kwargs):
        print('debug: func =', func.__name__, args, kwargs)
        return func(*args, **kwargs)
    return wrapper

@debug
def add(l, r):
    return l+r

@debug
def sub(l, r):
    return l-r

print('add name:', add.__name__)
print('sub name:', sub.__name__)
