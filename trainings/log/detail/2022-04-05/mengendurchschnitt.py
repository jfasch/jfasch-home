import db
import mytable


f = open('mein-austausch-file.json')
json_daten = f.read()

mydaten = mytable.MyTable(db.read_mytable_from_database())
print(mydaten.mengen_durchschnitt())
