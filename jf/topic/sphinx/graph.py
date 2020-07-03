from . import utils
from .. import errors

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

import subprocess

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-topicgraph', _TopicGraphDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topicgraph_nodes)

def _ev_doctree_resolved__expand_topicgraph_nodes(app, doctree, docname):
    '''"doctree-resolved" event handler to expand topic graph nodes'''
    try:
        utils.sphinx_create_soup(app)
        expander = _TopicGraphExpander(app=app, docname=docname)
        for n in doctree.traverse(TopicGraphNode):
            expander.expand(n)
    except Exception:
        logger.exception(f'{docname}: cannot expand topic graph')
        raise

class TopicGraphNode(nodes.Element):
    def __init__(self, entries):
        super().__init__(self)
        self.entries = entries

class _TopicGraphDirective(SphinxDirective):
    option_spec = {
        'entries': utils.list_of_element_path,
    }
    def run(self):
        node = TopicGraphNode(entries=self.options.get('entries', []))
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class _TopicGraphExpander:
    def __init__(self, app, docname):
        self._app = app
        self._docname = docname

    def expand(self, node):
        graph = self._graphnode_to_graph(node)
        dot = self._graph_to_dot(graph=graph)
        svg = self._dot_to_svg(dot=dot)
        node.replace_self(nodes.raw(svg, svg, format='html'))

    def _graphnode_to_graph(self, node):
        assert isinstance(node, _TopicGraphNode)
        if len(node.entries) == 0:
            return self._app.jf_soup.worldgraph()
        return self._app.jf_soup.subgraph(entrypoint_paths=node.entries)

    def _graph_to_dot(self, graph):
        lines = [
            'digraph {',
        ]

        for topic in graph.nodes:
            uri = self._app.builder.get_relative_uri(from_=self._docname, to=topic.docname)
            node_id = '_'.join(topic.path)
            lines.append(f'{node_id}[label="{topic.title}", href="{uri}"];')
        for src, dst in graph.edges:
            src_id = '_'.join(src.path)
            dst_id = '_'.join(dst.path)
            lines.append(f'{src_id} -> {dst_id};')

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
