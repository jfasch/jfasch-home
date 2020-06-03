from .utils import TopicError

from networkx.algorithms.dag import descendants
from networkx import DiGraph


class Soup:
    def __init__(self, topics=None):
        if topics:
            self._topics = topics
        else:
            self._topics = []
        self._worldgraph = None

    def __len__(self):
        return len(self._topics)
    def __iter__(self):
        return iter(self._topics)
    def add(self, topic):
        if self._worldgraph:
            raise TopicError(f'cannot add topic {topic.id}: graph already made')
        self._topics.append(topic)
    def purge(self, docname):
        self._topics = [topic for topic in self._topics if topic.docname != docname]
        
    def find_id(self, id):
        for t in self._topics:
            if t.id == id:
                return t
        raise KeyError('no topic with ID '+id)

    def worldgraph(self):
        return self._make_worldgraph()

    def subgraph(self, entrypoint_ids):
        world = self._make_worldgraph()
        topics = set()
        for topic in (t for t in world if t.id in entrypoint_ids):
            topics.add(topic)
            topics.update(descendants(world, topic))
        return world.subgraph(topics)

    def _make_worldgraph(self):
        if self._worldgraph is None:
            self._worldgraph = DiGraph()
            for topic in self._topics:
                self._worldgraph.add_node(topic)
                for target_id in topic.dependencies:
                    target_topic = self.find_id(target_id)
                    self._worldgraph.add_edge(topic, target_topic)
        return self._worldgraph

