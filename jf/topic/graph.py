from . import utils

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes

from networkx.algorithms.dag import descendants
from networkx import DiGraph, draw_networkx
import matplotlib.pyplot as plt

import io


def event_doctree_resolved__expand_topicgraph_nodes(app, doctree, docname):
    '''"doctree-resolved" event handler to expand topic graph nodes'''
    expander = TopicGraphExpander(gibberish=app.jf_gibberish, docname=docname)
    for n in doctree.traverse(TopicGraphNode):
        expander.expand(n)

class TopicGraphNode(nodes.Element):
    def __init__(self, entries):
        super().__init__(self)
        self.entries = entries

class TopicGraphDirective(SphinxDirective):
    option_spec = {
        'entries': utils.list_of_stripped_str,
    }
    def run(self):
        node = TopicGraphNode(entries=self.options.get('entries', []))
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class TopicGraphExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, node):
        world = DiGraph()
        for topic in self._gibberish.soup:
            world.add_node(topic)
            for target_id in topic.dependencies:
                target_topic = self._gibberish.soup.find_id(target_id)
                world.add_edge(topic, target_topic)

        if len(node.entries):
            topics = set()
            for topic in (self._gibberish.soup.find_id(id) for id in node.entries):
                topics.add(topic)
                topics.update(descendants(world, topic))
            g = world.subgraph(topics)
            for n in g.nodes:
                print(n.id)
        else:
            g = world

        draw_networkx(g, labels={topic: topic.id for topic in g.nodes}, with_label=True)

        data = io.StringIO()
        plt.savefig(data, format='svg')
        plt.clf()
        plt.cla()
        plt.close()


        s = data.getvalue()
        s = s[s.find('<svg'):]

        node.replace_self([nodes.raw(s, s, format='html')])