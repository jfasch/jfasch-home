from .errors import TopicError
from .soup import Soup
from .topic import Topic
from . import utils

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

import re
import subprocess


logger = logging.getLogger(__name__)

def setup(app):
    app.connect('env-purge-doc', utils.sphinx_purge_doc)

    _setup_topic(app)
    _setup_topiclist(app)
    _setup_graph(app)

# topic
# ----------------------------------
def _setup_topic(app):
    app.add_directive('jf-topic', _TopicDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_topicnodes)

def _ev_doctree_read__extract_topicnodes(app, doctree):
    try:
        docname = app.env.docname
        topic_nodes = list(doctree.traverse(_TopicNode))
        if len(topic_nodes) > 1:
            raise TopicError(f'{docname} contains multiple topics')

        for tn in topic_nodes:
            if tn.title is None:
                title = utils.get_document_title(docname, doctree)
            else:
                title = tn.title
            
            utils.sphinx_add_topic(app=app, docname=docname,
                                   title=title, path=tn.path, dependencies=tn.dependencies)
            tn.replace_self([])
    except Exception:
        logger.exception(f'{docname}: cannot extract topic nodes')
        raise
        
class _TopicNode(nodes.Element):
    def __init__(self, title, path, dependencies):
        super().__init__(self)
        self.title = title
        self.path = path
        self.dependencies = dependencies

class _TopicDirective(SphinxDirective):
    required_arguments = 1   # topic path

    option_spec = {
        'title': str,
        'dependencies': utils.list_of_element_path,
    }

    def run(self):
        path = utils.element_path(self.arguments[0].strip())
        title = self.options.get('title', None)
        dependencies = self.options.get('dependencies', [])

        return [_TopicNode(title=title, path=path, dependencies=dependencies),
                _TopicGraphNode(entries=[path])]

# topiclist
# ----------------------------------
def _setup_topiclist(app):
    app.add_directive('jf-topiclist', _TopicListDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topiclist_nodes)

def _ev_doctree_resolved__expand_topiclist_nodes(app, doctree, docname):
    try:
        utils.sphinx_create_soup(app)
        expander = _TopicListExpander(app=app, docname=docname)
        for n in doctree.traverse(_TopicListNode):
            expander.expand(n)
    except Exception:
        logger.exception(f'{docname}: cannot expand topic list')
        raise

class _TopicListNode(nodes.Element):
    pass

class _TopicListDirective(SphinxDirective):
    def run(self):
        node = _TopicListNode()
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class _TopicListExpander:
    def __init__(self, app, docname):
        self._app = app
        self._docname = docname

    def expand(self, node):
        bl = nodes.bullet_list()
        for topic in self._app.jf_soup.iter_topics():
            li = nodes.list_item()
            li += self._topic_paragraph(topic.path)
            bl += li
        node.replace_self(bl)

    def _topic_paragraph(self, path):
        topic = self._app.jf_soup.element_by_path(path)
        assert isinstance(topic, Topic), f'dependency on non-topic {path}?'
        p = nodes.paragraph()
        p += self._topic_headline_elems(path)
        if topic.dependencies:
            p += self._topic_dependencies(path)
        return p

    def _topic_headline_elems(self, path):
        topic = self._app.jf_soup.element_by_path(path)
        elems = []
        elems.append(nodes.Text(f'{topic.title} ('))

        ref = nodes.reference()
        ref['refuri'] = self._app.builder.get_relative_uri(
            from_=self._docname, to=topic.docname)
        ref += nodes.Text('.'.join(topic.path))
        elems.append(ref)

        elems.append(nodes.Text(')'))
        
        return elems
        
    def _topic_dependencies(self, path):
        topic = self._app.jf_soup.element_by_path(path)
        bl = nodes.bullet_list()
        for d in topic.dependencies:
            li = nodes.list_item()
            bl += li

            par = nodes.paragraph()
            li += par

            t = self._app.jf_soup.element_by_path(d)
            par += self._topic_headline_elems(t.path)
        return bl


# graph
# ----------------------------------
def _setup_graph(app):
    app.add_directive('jf-topicgraph', _TopicGraphDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topicgraph_nodes)

def _ev_doctree_resolved__expand_topicgraph_nodes(app, doctree, docname):
    '''"doctree-resolved" event handler to expand topic graph nodes'''
    try:
        utils.sphinx_create_soup(app)
        expander = _TopicGraphExpander(app=app, docname=docname)
        for n in doctree.traverse(_TopicGraphNode):
            expander.expand(n)
    except Exception:
        logger.exception(f'{docname}: cannot expand topic graph')
        raise

class _TopicGraphNode(nodes.Element):
    def __init__(self, entries):
        super().__init__(self)
        self.entries = entries

class _TopicGraphDirective(SphinxDirective):
    option_spec = {
        'entries': utils.list_of_element_path,
    }
    def run(self):
        node = _TopicGraphNode(entries=self.options.get('entries', []))
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
