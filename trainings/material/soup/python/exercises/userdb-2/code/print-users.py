import userdb
import sys

with open(sys.argv[1], encoding='cp1252') as f:
    users = userdb.parse_lines(f)
    userdb.print_users(users, sys.stdout)
