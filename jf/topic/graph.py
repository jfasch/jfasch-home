from . import utils

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes

from networkx.algorithms.dag import descendants
from networkx import DiGraph, draw_networkx
from networkx.drawing.nx_pydot import pydot_layout
import matplotlib.pyplot as plt

import io
import re
import subprocess


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
        g = self._build_graph(node)
        dotspec = self._graph_to_dot(g)
        try:
            completed = subprocess.run(
                ['dot', '-T', 'svg'],
                input=dotspec, check=True, text=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            raise utils.TopicError(f'dot exited with status {e.returncode}:\n[dot]\n{dotspec}\n[stderr]\n{e.stderr}')

        svgstr = completed.stdout
        node.replace_self([nodes.raw(svgstr, svgstr, format='html')])

    def _build_graph(self, node):
        assert isinstance(node, _TopicGraphNode)

        world = DiGraph()
        for topic in self._gibberish.soup:
            world.add_node(topic)
            for target_id in topic.dependencies:
                target_topic = self._gibberish.soup.find_id(target_id)
                world.add_edge(topic, target_topic)

        if len(node.entries) == 0:
            return world

        topics = set()
        for topic in (self._gibberish.soup.find_id(id) for id in node.entries):
            topics.add(topic)
            topics.update(descendants(world, topic))

        return world.subgraph(topics)

    @classmethod
    def _graph_to_dot(cls, g):
        lines = [
            'digraph {',
        ]

        for topic in g.nodes:
            lines.append(f'{topic.id}[label="{topic.title}"];')
        for src, dst in g.edges:
            lines.append(f'{src.id} -> {dst.id};')

        lines.append('}')

        return '\n'.join(lines)

    re_svg_begin_and_rest = re.compile(r'^.*?(<svg .*?>)(.*)', re.MULTILINE|re.DOTALL)
    re_width = re.compile('^(<svg.*?)width=".*?"(.*)', re.MULTILINE|re.DOTALL)
    re_height = re.compile('^(<svg.*?)height=".*?"(.*)', re.MULTILINE|re.DOTALL)

    @classmethod
    def _strip_svg_width_height(cls, xmlstr):
        '''Being too stupid to get the fucking etree namespace handling right,
        I have to remove width and height manually

        '''

        m = cls.re_svg_begin_and_rest.search(xmlstr)
        svg_begin, rest = m.group(1), m.group(2)

        m = cls.re_width.search(svg_begin)
        svg_begin = m.group(1) + m.group(2)

        m = cls.re_height.search(svg_begin)
        svg_begin = m.group(1) + m.group(2)

        return svg_begin + rest
