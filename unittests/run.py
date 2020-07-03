#!/usr/bin/python3

from jf.topic.soup import Soup
from jf.topic.topic import Topic
from jf.topic.group import Group
from jf.topic import errors

import unittest


class SoupTest(unittest.TestCase):
    def test_iter_topics_before_commit(self):
        soup = Soup()
        try:
            for e in soup.iter_topics():
                pass
        except errors.NotCommitted:
            pass
        else:
            self.fail()

    def test_worldgraph_before_commit(self):
        soup = Soup()
        self.assertRaises(errors.NotCommitted, soup.worldgraph)

    def test_subgraph_before_commit(self):
        soup = Soup()
        soup.add_element(Topic(title='Topic', path=('topic',), 
                               docname='docname-topic.rst', dependencies=[]))
        self.assertRaises(errors.NotCommitted, soup.subgraph, entrypoint_paths=[('topic',)])

    def test_add_element_after_commit(self):
        soup = Soup()
        soup.commit()
        self.assertRaises(errors.AlreadyCommitted, soup.add_element, None)

    def test_iter_topics_yields_root_topics(self):
        soup = Soup()
        soup.add_element(Topic(title='Topic', path=('topic',), 
                               docname='docname-topic.rst', dependencies=[]))
        soup.commit()
        
        for t in soup.iter_topics():
            if t.path == ['topic',]:
                print(t.path)
                break
            else:
                self.fail()

    def test_worldgraph_with_group(self):
        topic_lo = Topic(title='topic inside group', path=['group', 'topic'], 
                         docname='docname-topic-in-group.rst', dependencies=[])
        topic_hi = Topic(title='topic inside root', path=['topic'], 
                         docname='docname-topic-in-root.rst', dependencies=[['group', 'topic']])

        soup = Soup()
        soup.add_element(Group(title='group', path=['group'], docname='docname-group.rst'))
        soup.add_element(topic_lo)
        soup.add_element(topic_hi)
        soup.commit()

        g = soup.worldgraph()
        self.assertIn((topic_hi, topic_lo), g.edges)

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

    def test_whatelse(self):
        # {topic,group}.path: calculated property

        # access before soup.commit()
        # soup.purge()
        # subgroup
        # group.parent
        # group hierarchy
        # group of topic does not exist

        # error: conflict same group/topic name inside one group

        # rename topic.id to topic.name

        # duplicate topic in group

        # soup: add_*(): unify worldgraph checks

        # non-existing parent group(s)

        pass

suite = unittest.TestSuite()
suite.addTest(unittest.defaultTestLoader.loadTestsFromTestCase(SoupTest))
suite.addTest(unittest.defaultTestLoader.loadTestsFromTestCase(GroupTest))

runner = unittest.TextTestRunner(verbosity=2, descriptions=False)
runner.run(suite)
