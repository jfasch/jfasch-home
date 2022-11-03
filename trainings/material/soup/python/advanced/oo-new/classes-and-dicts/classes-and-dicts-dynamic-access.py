class Person:
    pass

person = Person()
person.firstname = 'Joerg'
person.lastname = 'Faschingbauer'

print('hasattr "firstname":', hasattr(person, 'firstname'))  # <--- query by string
print('hasattr "svnr":',      hasattr(person, 'svnr'))       # <--- query by string

print('getattr "firstname":', getattr(person, 'firstname'))  # <--- get by string
try:
    getattr(person, 'svnr')                                  # <--- get by string
except AttributeError:                                       # <--- still same as dict access
    print('getattr "svnr": not there')

setattr(person, 'svnr', '1037190666')                        # <--- set by string

print('Boing, now having an ID', person.svnr)
