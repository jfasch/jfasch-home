import xsv.dict_extensions as dict_extensions

import unittest


class DictExtensionSuite(unittest.TestCase):
    def test_basic(self):
        container = dict_extensions.well_ordered_dict()

        sample_element = (66,'name_of_element_66',{1:1})
        container.add(sample_element)

        data1, name = container.get_by_index(66)
        data2, idx  = container.get_by_name('name_of_element_66')

        self.assertEqual(name, 'name_of_element_66')
        self.assertEqual(idx, 66)

        self.assertTrue(isinstance(name,str))
        self.assertTrue(isinstance(idx,int))
        self.assertTrue(isinstance(data1,dict))
        self.assertTrue(isinstance(data2,dict))
        self.assertTrue(data1==data2)
        self.assertTrue(data1==sample_element[2])

        # self.assertTrue(container.get_name(66))
        # self.assertTrue(container.get_index('name_of_element_66'))
        # self.assertTrue(container.get_data(66))
        # self.assertTrue(container.get_data('name_of_element_66'))

suite = unittest.defaultTestLoader.loadTestsFromTestCase(DictExtensionSuite)

