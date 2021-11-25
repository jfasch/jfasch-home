import stock

import sys
import sqlite3

csvname = sys.argv[1]
dbname = sys.argv[2]

db = sqlite3.connect(dbname)

for record in stock.read_stock(csvname):
    stmt = f'''
    insert into records values (
        "{record['FUND_ISIN']}", 
        "{record['FUND_NAME']}", 
        "{record['FUND_TICKER']}"
    );
    '''
    db.execute(stmt)

db.commit()
