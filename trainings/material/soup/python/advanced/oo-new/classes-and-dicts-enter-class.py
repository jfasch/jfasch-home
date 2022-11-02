class Person:                            # <--- create empty class
    pass

print('Type of Person:', type(Person))   # <--- is-a type (huh?)

person = Person()                        # <--- calling type creates object

print('Type of object:', type(person))   # <--- is-a type (huh?)

person.firstname = 'Joerg'               # <--- setting *real* attributes
person.lastname = 'Faschingbauer'

print('firstname:', person.firstname)    # <--- getting *real* attributes
print('lastname:', person.firstname)

try:
    person.svnr                          # <--- attribute 'svnr' does not exist
except AttributeError:                   #      (just the same as raw dict)
    print('Error: no attribute "svnr"')
    pass

