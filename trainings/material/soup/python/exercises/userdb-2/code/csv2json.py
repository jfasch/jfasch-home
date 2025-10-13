import userdb
import sys

destname = sys.argv[2]

with open(sys.argv[1], encoding='cp1252') as f:
    users = userdb.read_userdicts_from_colon_separated_values(f)

with open(sys.argv[2], 'w') as f:
    userdb.write_userdicts_to_json(users, f)
