#!/usr/bin/python

from switch import Switch
from interface import Interface
from error import InterfaceNameNotUnique

import unittest
import datetime

class BasicTest(unittest.TestCase):
    def test_ok(self):
        s = Switch(name='sw01', 
                   interfaces=[
                       Interface(name='if1', number=1, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
                                 last_change=datetime.datetime(year=2019, month=11, day=20,
                                                               hour=13, minute=17, second=33)),
                       Interface(name='if2', number=2, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
                                 last_change=datetime.datetime(year=2019, month=11, day=20,
                                                               hour=13, minute=17, second=33)),

                   ],
                   uptime = datetime.timedelta(seconds=5))

        self.assertEqual(len(s.interfaces), 2) # zum beispiel
        self.assertEqual(s.interfaces[0].name, 'if1')

    def test_uniq_interface_names(self):
        with self.assertRaises(InterfaceNameNotUnique):
            Switch(name='sw01', 
                   interfaces=[
                       Interface(name='if1', number=1, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
                                 last_change=datetime.datetime(year=2019, month=11, day=20,
                                                               hour=13, minute=17, second=33)),
                       Interface(name='if1', number=2, adminstatus=Interface.UP, operstatus=Interface.DOWN, 
                                 last_change=datetime.datetime(year=2019, month=11, day=20,
                                                               hour=13, minute=17, second=33)),
                       
                   ],
                   uptime = datetime.timedelta(seconds=5))
            
        

suite = unittest.TestLoader().loadTestsFromTestCase(BasicTest)
unittest.TextTestRunner().run(suite)
