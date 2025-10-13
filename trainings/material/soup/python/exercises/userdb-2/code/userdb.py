import json
from collections import namedtuple

User = namedtuple('User', ('id', 'firstname', 'lastname', 'birth'))

def read_userdicts_from_colon_separated_values(input):
    users = []
    for line in input:
        line = line.rstrip('\n')
        id, firstname, lastname, birth = line.split(':')
        users.append({
            'id': int(id),
            'firstname': firstname,
            'lastname': lastname,
            'birth': birth,
        })
    return users

def write_userdicts_to_json(users, output):
    json.dump(users, output)

def read_userobjs_from_colon_separated_values(input):
    userobjs = []
    for userdict in read_users_from_colon_separated_values(input):
        userobjs.append(User(id=userdict['id'],
                             firstname=userdict['firstname'],
                             lastname=userdict['lastname'],
                             birth=userdict['birth'],
                             ))
    return userobjs

def write_userobjs_to_json(users, output):
    userdicts = [{'id': user.id, 'firstname': user.firstname, 'lastname': user.lastname, 'birth': user.birth} for user in users]
    json.dump(userdicts, output)
