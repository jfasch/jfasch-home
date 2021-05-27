#!/usr/bin/python

import unittest
import sys
import os.path
import io

# direct python module path to ../lib
sys.path.insert(1, os.path.join('..', 'lib'))

import matutil.matrix


class FirstTest(unittest.TestCase): # a test suite, according to Kent Beck
    def testBadNumberInMatrix(self):  # test case, according to
                                      # hinself
        csv_file = io.StringIO('A2;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;0;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;xxx;1;1;1;1;1;1;1')

        m = matutil.matrix.Matrix(csv_file)

        # try:
        #     subm = m.extract('A2')
        #     self.fail()
        # except matutil.matrix.EugenieError as e:
        #     pass

        # better this way:

        # leads to "AssertionError: EugenieError not raised by
        # extract" if exception is not raised
        self.assertRaises(matutil.matrix.EugenieError, m.extract, 'A2')

suite = unittest.TestLoader().loadTestsFromTestCase(FirstTest)
unittest.TextTestRunner().run(suite)
