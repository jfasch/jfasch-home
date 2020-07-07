from jf.topic.soup import Soup
from jf.topic.topic import Topic
from jf.topic.group import Group
from jf.topic import errors

import unittest


class GroupTest(unittest.TestCase):
    def test_basic(self):
        soup = Soup()

        topic = Topic(title='Topic', path=('group', 'topic'), docname='docname-topic.rst', dependencies=[])
        soup.add_element(topic)
        
        group = Group(title='Group', path=('group',), docname='docname-group.rst')
        soup.add_element(group)

        soup.commit()

        self.assertEqual(topic.parent, group)
        self.assertEqual(len(group._children), 1)
        self.assertTrue(group.has_element(topic))

    def test_group_hierarchy(self):
        soup = Soup()
        parent = Group(title='Parent', path=('parent',), docname='parent.rst')
        child = Group(title='Child', path=('parent', 'child'), docname='child.rst')
        soup.add_element(parent)
        soup.add_element(child)

        soup.commit()

        self.assertTrue(parent.has_element(child))
        self.assertEqual(child.parent, parent)


suite = unittest.defaultTestLoader.loadTestsFromTestCase(GroupTest)
