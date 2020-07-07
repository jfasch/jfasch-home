#!/usr/bin/python3

from souptest import suite as soup_suite
from grouptest import suite as group_suite
from projectplantest import suite as projectplan_suite

import unittest


suite = unittest.TestSuite()
suite.addTest(soup_suite)
suite.addTest(group_suite)
suite.addTest(projectplan_suite)

runner = unittest.TextTestRunner(verbosity=2, descriptions=False)
runner.run(suite)
