def decorator(param):
    def wrapper():
        print('wrapper called, param =', param)
        return param
    return wrapper

eins = decorator(1)
zwei = decorator(2)
blah = decorator('blah')

print('eins', eins())
print('zwei', zwei())
print('blah', blah())
