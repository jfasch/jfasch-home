import sys
import sqlite3

db = sqlite3.connect(sys.argv[1])
cursor = db.cursor()

stmt = '''
create table records (
    isin str primary key,
    fund_name str,
    fund_ticker str);
'''

cursor.execute(stmt)
