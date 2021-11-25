import csv
from pprint import pprint

f = open('headers.csv')
rdr = csv.DictReader(f, delimiter=',', quotechar='"')
for record in rdr:
    pprint(record, width=30)
