#!/usr/bin/python

from SwitchZeug.switch import Switch
from SwitchZeug.interface import Interface

import argparse
import datetime
import sqlite3 as db


# parse commandline
parser = argparse.ArgumentParser(
    description="Create report out of given switch database")
parser.add_argument('--name', help='switch name blah blah', required=True)
parser.add_argument('db', help='sqlite3 database file')
args = parser.parse_args()

connection = db.connect(args.db)
cursor = connection.cursor()

resultset = cursor.execute("select switches.name, switches.uptime, "
                           "       interfaces.name, interfaces.number, interfaces.adminstatus, "
                           "       interfaces.operstatus, interfaces.lastchange "
                           "from switches join interfaces on id = switch_id "
                           "where switches.name = ?;",
                           (args.name,))

interfaces = []
name = ''
uptime = 0

for sw_name, sw_uptime, if_name, if_number, if_adminstatus, if_operstatus, if_lastchange in resultset:
    interfaces.append(Interface(name=if_name, number=if_number, 
                                adminstatus=if_adminstatus, operstatus=if_operstatus, 
                                last_change=if_lastchange))
    name = sw_name
    uptime = sw_uptime

switch = Switch(name=name, uptime=datetime.timedelta(seconds=uptime), interfaces=interfaces)
print(switch)
