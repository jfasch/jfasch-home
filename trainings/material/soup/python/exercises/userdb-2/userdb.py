def parse_lines(lines):
    users = []
    for line in lines:
        line = line.rstrip('\n')
        id, firstname, lastname, birth = line.split(':')
        users.append({
            'id': int(id),
            'firstname': firstname,
            'lastname': lastname,
            'birth': birth,
        })
    return users
