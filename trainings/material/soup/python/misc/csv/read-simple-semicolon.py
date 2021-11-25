import csv

f = open('simple-semicolon.csv')
rdr = csv.reader(f, delimiter=';')
for num, firstname, lastname in rdr:
    print(f'ID: {num} --- First name: {firstname} - Last name: {lastname}')
