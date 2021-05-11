from .group import Group
from .node import Node
from .topic import Topic
from .exercise import Exercise
from .task import Task
from . import errors
from . import element

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
        self._add_nodes_to_groups()
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

    def subgraph(self, entrypoints):
        '''Given entrypoints, compute a subgraph of the world graph that
        contains the entrypoints and all their descendants.

        entrypoints is an iterable of element paths or elements (can
        be mixed)
        '''

        self._assert_committed()
        world = self._make_worldgraph()

        entrypoint_elems = set()
        for e in entrypoints:
            try:
                element.verify_is_path(e)
            except errors.TopicError:   # not a path; must be element
                entrypoint_elems.add(e)
            else:
                entrypoint_elems.add(self.element_by_path(e))

        topics = set()
        for topic in entrypoint_elems:
            topics.add(topic)
            topics.update(descendants(world, topic))
        return world.subgraph(topics)

    def _make_worldgraph(self):
        if self._worldgraph is not None:
            return self._worldgraph

        self._worldgraph = DiGraph()
        for name, elem in self._root_group.iter_recursive():
            if not isinstance(elem, Node):
                continue
            self._worldgraph.add_node(elem)
            for target_path in elem.dependencies:
                try:
                    target_topic = self.element_by_path(target_path)
                except errors.PathNotFound:
                    raise errors.TopicError(f'{elem.docname} ({elem}): dependency {target_path} not found')
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

    def _add_nodes_to_groups(self):
        nodes = [n for n in self._elements if isinstance(n, Node)]
        for n in nodes:
            self._root_group.add_element(n)
            self._elements.remove(n)
            
    def _assert_committed(self):
        if self._root_group is None:
            raise errors.NotCommitted('soup not committed')

    def _assert_uncommitted(self):
        if self._root_group is not None:
            raise errors.AlreadyCommitted('soup already committed')
