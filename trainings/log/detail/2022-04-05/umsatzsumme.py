import db
import mytable

f = open('mein-austausch-file.json')
austausch_str = f.read()

table = db.mytable_from_json(austausch_str)
daten_objekt = mytable.MyTable(table)
print(daten_objekt.umsatz_summe())
