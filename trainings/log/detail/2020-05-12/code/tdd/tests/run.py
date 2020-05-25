#!/usr/bin/python

import sys
import os.path

xsv_containing_dir = os.path.join(os.path.dirname(sys.argv[0]), '..')
sys.path.insert(0, xsv_containing_dir)

from thing_suite import suite as th_suite
from dict_extensions_suite import suite as de_suite

import unittest

suite = unittest.TestSuite()
suite.addTest(th_suite)
suite.addTest(de_suite)

runner = unittest.TextTestRunner(verbosity=2, descriptions=False)
runner.run(suite)
