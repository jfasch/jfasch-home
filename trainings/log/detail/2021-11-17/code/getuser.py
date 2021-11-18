import sys
import pprint


filename = sys.argv[1]
username = sys.argv[2]

userdatabase = {}

f = open(filename)
for line in f:
    line = line.rstrip()   # remove linefeed at end of line
    fields = line.split(':')

    username = fields[0]
    password = fields[1]
    userid = int(fields[2])
    groupid = int(fields[3])
    description = fields[4]
    home = fields[5]
    loginshell = fields[6]

    userrecord = {}
    userrecord['username'] = username
    userrecord['password'] = password
    userrecord['userid'] = userid
    userrecord['groupid'] = groupid
    userrecord['description'] = description
    userrecord['home'] = home
    userrecord['loginshell'] = loginshell

    # pprint.pprint(userrecord, indent=4)

    userdatabase[username] = userrecord
    
#pprint.pprint(userdatabase, indent=4)

pprint.pprint(userdatabase[username])
