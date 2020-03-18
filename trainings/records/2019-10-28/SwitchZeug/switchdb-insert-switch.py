#!/usr/bin/python

from SwitchZeug.switch import Switch
from SwitchZeug.interface import Interface
from SwitchZeug.database import insert_switches

import sqlite3 as db
import datetime
import argparse


# parse commandline
parser = argparse.ArgumentParser(
    description="Insert two switches 'sw01' and 'sw02' into the given switch database")
parser.add_argument('db', help='sqlite3 database file')
args = parser.parse_args()
dbfile = args.db

connection = db.connect(args.db)
cursor = connection.cursor()

insert_switches(
    cursor=cursor,
    switches = [
        Switch(
            'sw01',
            interfaces=[
                Interface(
                    name='if1',
                    number=1,
                    adminstatus=Interface.UP,
                    operstatus=Interface.DOWN, 
                    last_change=datetime.datetime(year=2019, month=11, day=20, 
                                                  hour=13, minute=17, second=33),
                ),
                Interface(
                    name='if2',
                    number=2,
                    adminstatus=Interface.UP,
                    operstatus=Interface.DOWN, 
                    last_change=datetime.datetime(year=2019, month=11, day=20, 
                                                  hour=13, minute=17, second=33),
                ),
            ],
            uptime=datetime.timedelta(seconds=1),
        ),
        Switch(
            'sw02',
            interfaces=[
                Interface(
                    name='if1',
                    number=1,
                    adminstatus=Interface.UP,
                    operstatus=Interface.DOWN, 
                    last_change=datetime.datetime(year=2019, month=11, day=20, 
                                                  hour=13, minute=17, second=33),
                ),
                Interface(
                    name='if2',
                    number=2,
                    adminstatus=Interface.UP,
                    operstatus=Interface.DOWN, 
                    last_change=datetime.datetime(year=2019, month=11, day=20,
                                                  hour=13, minute=17, second=33),
                ),
                Interface(
                    name='if3',
                    number=2,
                    adminstatus=Interface.UP,
                    operstatus=Interface.DOWN, 
                    last_change=datetime.datetime(year=2019, month=11, day=20,
                                                  hour=13, minute=17, second=33),
                ),
            ],
            uptime=datetime.timedelta(seconds=1),
        ),
    ])

connection.commit()
