import sys

conffile = sys.argv[1]

# read and exec config in dict
confcode = open(conffile).read()
confdict = {}
exec(confcode, confdict)

# consume students list (the configfile must set a well-defined global
# variable, 'STUDENTS')
students = confdict['STUDENTS']

# do something with students
for student in students:
    print(f'MatNo: {student["matno"]}, First Name: {student["firstname"]}, Last Name: {student["lastname"]}')
