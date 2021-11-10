import functools

class debug:
    def __init__(self, msg):
        self.msg = msg

    def __call__(self, func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            print(f'{self.msg}: func = {func.__name__}, {args}, {kwargs}')
            return func(*args, **kwargs)
        return wrapper

@debug('wtf')
def add(l, r):
    return l+r

@debug('gosh')
def sub(l, r):
    return l-r

print('add(1,2) = ', add(1,2))
print('sub(1,2) = ', sub(1,2))
