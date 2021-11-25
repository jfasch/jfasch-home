import csv

f = open('simple.csv')
rdr = csv.reader(f)
for row in rdr:
    print(row)
