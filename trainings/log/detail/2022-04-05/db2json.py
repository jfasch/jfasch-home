import db

austausch_string = db.mytable_to_json()
f = open('mein-austausch-file.json', 'w')
f.write(austausch_string)
