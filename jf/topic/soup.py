from . import errors
from .group import Group
from .topic import Topic

from networkx.algorithms.dag import descendants
from networkx import DiGraph


class Soup:
    def __init__(self):
        self._elements = set()
        self._root_group = None
        self._worldgraph = None

    def __len__(self):
        # well this is a bit dumb
        return len(list(self._root_group.iter_recursive()))

    def iter_topics(self):
        self._assert_committed()
        for name, elem in self._root_group.iter_recursive():
            if isinstance(elem, Topic):
                yield elem
            else:
                assert False, elem

    def add_element(self, element):
        self._assert_uncommitted()
        if self._worldgraph:
            raise errors.TopicError(f'cannot add {element}: graph already made')
        self._elements.add(element)

    def commit(self):
        if self._root_group is not None:
            return

        self._root_group = Group(title='Root', path=(), docname='')
        self._make_hierarchy()
        self._add_topics_to_groups()
        assert len(self._elements) == 0
        del self._elements

    @property
    def root(self):
        return self._root_group

    def element_by_path(self, path):
        return self._root_group.element_by_path(path)

    def worldgraph(self):
        self._assert_committed()
        return self._make_worldgraph()

    def subgraph(self, entrypoint_paths):
        self._assert_committed()
        world = self._make_worldgraph()
        topics = set()
        for topic in (t for t in world if t.path in entrypoint_paths):
            topics.add(topic)
            topics.update(descendants(world, topic))
        return world.subgraph(topics)

    def _make_worldgraph(self):
        if self._worldgraph is not None:
            return self._worldgraph

        self._worldgraph = DiGraph()
        for name, elem in self._root_group.iter_recursive():
            if not isinstance(elem, Topic):
                continue
            self._worldgraph.add_node(elem)
            for target_path in elem.dependencies:
                target_topic = self.element_by_path(target_path)
                self._worldgraph.add_edge(elem, target_topic)

        return self._worldgraph

    def _make_hierarchy(self):
        level = 1
        while True:
            all_groups = [g for g in self._elements if isinstance(g, Group)]
            if not all_groups:   # no more groups
                break
            level_groups = [g for g in all_groups if len(g._requested_path) == level]
            for g in level_groups:
                self._root_group.add_element(g)
                self._elements.remove(g)
            level += 1

    def _add_topics_to_groups(self):
        topics = [t for t in self._elements if isinstance(t, Topic)]
        for t in topics:
            self._root_group.add_element(t)
            self._elements.remove(t)
            
    def _assert_committed(self):
        if self._root_group is None:
            raise errors.NotCommitted('soup not committed')

    def _assert_uncommitted(self):
        if self._root_group is not None:
            raise errors.AlreadyCommitted('soup already committed')
