import functools

def debug(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(func.__name__, 'called:', args, kwargs)
        return func(*args, **kwargs)
    return wrapper

@debug
def add(a, b):
    return a+b

print(add.__name__)
