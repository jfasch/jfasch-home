import sys
import pprint


filename = sys.argv[1]
username = sys.argv[2]

userdatabase = {}

f = open(filename)
for line in f:
    username, password, userid, groupid, description, home, loginshell = line.rstrip().split(':')
    userdatabase[username] = {
        'username': username,
        'password': password,
        'userid': userid,
        'groupid': groupid,
        'description': description,
        'home': home,
        'loginshell': loginshell,
    }

pprint.pprint(userdatabase[username])
