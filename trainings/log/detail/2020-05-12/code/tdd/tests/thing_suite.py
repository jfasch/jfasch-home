import xsv.thing as thing

import unittest


# test database, containing a growing number of tests
class ThingSuite(unittest.TestCase):
    def testThisIsATemplateTestThatStartsWith_test(self):
        thing_obj = thing.Thing(name="The Thing", initial_content=[1,2,3])
        self.assertTrue(thing_obj.has(1))
        self.assertTrue(thing_obj.has(2))
        self.assertTrue(thing_obj.has(3))
        self.assertFalse(thing_obj.has(666))

    def testNotFullyImplementedStupid(self):
        thing_obj = thing.Thing(name="The Thing", initial_content=[])
        thing_obj.add(1)
        self.assertTrue(thing_obj.has(1))

    def testAnotherStupid(self):
        thing_obj = thing.Thing(name="The Thing", initial_content=[])
        thing_obj.add(1)
        thing_obj.add(1)
        thing_obj.add(1)
        self.assertTrue(thing_obj.has(1))
        self.assertEqual(thing_obj.numitems(), 1)

suite = unittest.defaultTestLoader.loadTestsFromTestCase(ThingSuite)
