from . import soup
from .. import errors
from ..topic import Topic

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-topiclist', _TopicListDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topiclist_nodes)

def _ev_doctree_resolved__expand_topiclist_nodes(app, doctree, docname):
    try:
        soup.sphinx_create_soup(app)
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

