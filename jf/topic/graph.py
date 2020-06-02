from . import utils

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx import addnodes
from sphinx.transforms.post_transforms import SphinxPostTransform
from docutils import nodes

from networkx.algorithms.dag import descendants
from networkx import DiGraph

import re
import subprocess

from sphinx.util import logging
logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-topicgraph', _TopicGraphDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topicgraph_nodes)

def _ev_doctree_resolved__expand_topicgraph_nodes(app, doctree, docname):
    '''"doctree-resolved" event handler to expand topic graph nodes'''
    expander = _TopicGraphExpander(gibberish=app.jf_gibberish, docname=docname)
    for n in doctree.traverse(_TopicGraphNode):
        expander.expand(n)

class _TopicGraphNode(nodes.Element):
    def __init__(self, entries):
        super().__init__(self)
        self.entries = entries

class _TopicGraphDirective(SphinxDirective):
    option_spec = {
        'entries': utils.list_of_stripped_str,
    }
    def run(self):
        node = _TopicGraphNode(entries=self.options.get('entries', []))
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class _TopicGraphExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, node):
        graph = self._graphnode_to_graph(node)
        dot = self._graph_to_dot(graph=graph)
        svg = self._dot_to_svg(dot=dot)
        node.replace_self(nodes.raw(svg, svg, format='html'))

    def _graphnode_to_graph(self, node):
        assert isinstance(node, _TopicGraphNode)
        soup = self._gibberish.soup
        world = build_worldgraph(soup=soup)
        if len(node.entries) == 0:
            return world
        return build_subgraph(world=world, entrypoint_ids=set(node.entries))

    def _graph_to_dot(self, graph):
        lines = [
            'digraph {',
        ]

        for topic in graph.nodes:
            uri = self._gibberish.app.builder.get_relative_uri(from_=self._docname, to=topic.docname)
            lines.append(f'{topic.id}[label="{topic.title}", href="{uri}"];')
        for src, dst in graph.edges:
            lines.append(f'{src.id} -> {dst.id};')

        lines.append('}')

        return '\n'.join(lines)
    
    def _dot_to_svg(self, dot):
        try:
            completed = subprocess.run(
                ['dot', '-T', 'svg'],
                input=dot, check=True, text=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            raise TopicError(f'dot exited with status {e.returncode}:\n[dot]\n{dotspec}\n[stderr]\n{e.stderr}')
    
        svg = completed.stdout
        # strip XML declaration (we are embedding it)
        svg = svg[svg.index('<svg'):]
        return svg

def build_worldgraph(soup):
    world = DiGraph()
    for topic in soup:
        world.add_node(topic)
        for target_id in topic.dependencies:
            target_topic = soup.find_id(target_id)
            world.add_edge(topic, target_topic)
    return world

def build_subgraph(world, entrypoint_ids):
    topics = set()
    for topic in (t for t in world if t.id in entrypoint_ids):
        topics.add(topic)
        topics.update(descendants(world, topic))
    return world.subgraph(topics)


    


