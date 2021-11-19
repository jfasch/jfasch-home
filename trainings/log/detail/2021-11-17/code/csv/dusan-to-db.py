import sys
import sqlite3
import my_csv


converted_records = my_csv.read_csv(sys.argv[1])

connection = sqlite3.connect('/tmp/dusan.sqlite')
cursor = connection.cursor()
cursor.execute('create table records (isin str, fund_in_universe bool);')

for r in converted_records:
    cursor.execute(f'insert into records values (\"{r["FUND_ISIN"]}\", \"{r["FUND_IN_UNIVERSE"]}\");')
