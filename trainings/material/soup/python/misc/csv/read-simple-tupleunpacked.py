import csv

f = open('simple.csv')
rdr = csv.reader(f)
for num, firstname, lastname in rdr:
    print(f'ID: {num} --- First name: {firstname} - Last name: {lastname}')
