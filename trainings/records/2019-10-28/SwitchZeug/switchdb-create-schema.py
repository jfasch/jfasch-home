#!/usr/bin/python

import sqlite3 as db
import argparse


# parse commandline
parser = argparse.ArgumentParser(
    description="Create database schema in the given switch database")
parser.add_argument('db', help='sqlite3 database file')
args = parser.parse_args()
dbfile = args.db

connection = db.connect(dbfile)
cursor = connection.cursor()

cursor.execute('''
CREATE TABLE switches (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT UNIQUE,
    uptime INTEGER);
''')

cursor.execute('''
CREATE TABLE interfaces (
    internal_id INTEGER PRIMARY KEY AUTOINCREMENT,
    switch_id INTEGER,
    name TEXT,
    number TEXT,
    adminstatus INTEGER,
    operstatus INTEGER,
    lastchange INTEGER,
    FOREIGN KEY(switch_id) REFERENCES switches(id));
''')

cursor.execute('''
CREATE UNIQUE INDEX if2switch ON interfaces(switch_id, name);
''')

cursor.execute('PRAGMA foreign_keys = ON;')

connection.commit()
