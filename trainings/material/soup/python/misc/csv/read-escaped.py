import csv

f = open('escaped.csv')
rdr = csv.reader(f, delimiter=',', quotechar='"')
for num, firstname, lastname in rdr:
    print(f'ID: {num} --- First name: {firstname} - Last name: {lastname}')
