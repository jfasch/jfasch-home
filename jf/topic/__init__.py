
from . import utils
from .soup import Soup
from .topic import Topic
from .gibberish import Gibberish

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

import re
import subprocess


logger = logging.getLogger(__name__)

def setup(app):
    _setup_gibberish(app)
    _setup_topic(app)
    _setup_topiclist(app)
    _setup_graph(app)

# soup and gibberish
# ----------------------------------
def _setup_gibberish(app):
    app.connect('builder-inited', _ev_builder_inited__setup_gibberish)
    app.connect('env-purge-doc', _ev_env_purge_doc)

def _ev_env_purge_doc(app, env, docname):
    app.jf_gibberish.soup.purge(docname)

def _ev_builder_inited__setup_gibberish(app):
    if not hasattr(app.env, 'jf_topic_soup'):
        app.env.jf_topic_soup = Soup()
    app.jf_gibberish = Gibberish(app=app, soup=app.env.jf_topic_soup)

# topic
# ----------------------------------
def _setup_topic(app):
    app.add_directive('jf-topic', _TopicDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_topicnodes)

def _ev_doctree_read__extract_topicnodes(app, doctree):
    docname = app.env.docname
    for tn in doctree.traverse(_TopicNode):
        topic = tn.topic
        if not topic.title:
            topic.title = utils.get_document_title(docname, doctree)
        app.jf_gibberish.soup.add(topic)
        tn.replace_self([])
        
class _TopicNode(nodes.Element):
    def __init__(self, topic):
        super().__init__(self)
        self.topic = topic

class _TopicDirective(SphinxDirective):
    required_arguments = 1   # topicid

    option_spec = {
        'title': str,
        'dependencies': utils.list_of_stripped_str,
    }

    def run(self):
        topicid = self.arguments[0].strip()
        return [_TopicNode(topic=Topic(title = self.options.get('title', None),
                                       id = topicid,
                                       docname = self.env.docname,
                                       dependencies = self.options.get('dependencies', []))),
                _TopicGraphNode(entries=[topicid])]


# topiclist
# ----------------------------------
def _setup_topiclist(app):
    app.add_directive('jf-topiclist', _TopicListDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topiclist_nodes)

def _ev_doctree_resolved__expand_topiclist_nodes(app, doctree, docname):
    expander = _TopicListExpander(gibberish=app.jf_gibberish, docname=docname)
    for n in doctree.traverse(_TopicListNode):
        expander.expand(n)

class _TopicListNode(nodes.Element):
    pass

class _TopicListDirective(SphinxDirective):
    def run(self):
        node = _TopicListNode()
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class _TopicListExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, node):
        bl = nodes.bullet_list()
        for topic in self._gibberish.app.jf_gibberish.soup:
            li = nodes.list_item()
            li += self._topic_paragraph(topic.id)
            bl += li
        node.replace_self(bl)

    def _topic_paragraph(self, id):
        topic = self._gibberish.soup.find_id(id)
        p = nodes.paragraph()
        p += self._topic_headline_elems(id)
        if topic.dependencies:
            p += self._topic_dependencies(id)
        return p

    def _topic_headline_elems(self, id):
        topic = self._gibberish.soup.find_id(id)
        elems = []
        elems.append(nodes.Text(f'{topic.title} ('))

        ref = nodes.reference()
        ref['refuri'] = self._gibberish.app.builder.get_relative_uri(
            from_=self._docname, to=topic.docname)
        ref += nodes.Text(topic.id)
        elems.append(ref)

        elems.append(nodes.Text(')'))
        
        return elems
        
    def _topic_dependencies(self, id):
        topic = self._gibberish.soup.find_id(id)
        bl = nodes.bullet_list()
        for d in topic.dependencies:
            li = nodes.list_item()
            bl += li

            par = nodes.paragraph()
            li += par

            t = self._gibberish.soup.find_id(d)
            par += self._topic_headline_elems(t.id)
        return bl


# graph
# ----------------------------------
def _setup_graph(app):
    app.add_directive('jf-topicgraph', _TopicGraphDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topicgraph_nodes)

def _ev_doctree_resolved__expand_topicgraph_nodes(app, doctree, docname):
    '''"doctree-resolved" event handler to expand topic graph nodes'''
    try:
        expander = _TopicGraphExpander(gibberish=app.jf_gibberish, docname=docname)
        for n in doctree.traverse(_TopicGraphNode):
            expander.expand(n)
    except Exception:
        logger.exception(f'cannot expand topic graph in {docname}')
        raise

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
        if len(node.entries) == 0:
            return self._gibberish.soup.worldgraph()
        return self._gibberish.soup.subgraph(entrypoint_ids=set(node.entries))

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
