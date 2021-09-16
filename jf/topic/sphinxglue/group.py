from . import utils
from . import soup
from .. import errors
from ..topic import Topic
from ..errors import TopicError

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

from networkx.algorithms.dag import topological_sort

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-group', _GroupDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_groupnodes)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_group_nodes)

def _ev_doctree_read__extract_groupnodes(app, doctree):
    '''Add group metadata to soup. Leave group node intact; it is expanded
    later when all metadata has been collected.'''

    try:
        docname = app.env.docname
        group_nodes = list(doctree.traverse(_GroupNode))
        if len(group_nodes) > 1:
            raise TopicError(f'{docname} contains multiple groups')

        for gn in group_nodes:
            soup.sphinx_add_group(
                app=app, 
                docname=docname, 
                title=utils.get_document_title(docname, doctree), 
                path=gn.path)
    except Exception:
        logger.exception(f'{docname}: cannot extract group nodes')
        raise

def _ev_doctree_resolved__expand_group_nodes(app, doctree, docname):
    try:
        soup.sphinx_create_soup(app)
        expander = _GroupTopicListExpander(app=app, docname=docname)
        for n in doctree.traverse(_GroupNode):
            expander.expand(n)
    except Exception:
        logger.exception(f'{docname}: cannot expand group')
        raise

class _GroupNode(nodes.Element):
    def __init__(self, path):
        super().__init__(self)
        self.path = path

class _GroupDirective(SphinxDirective):
    required_arguments = 1   # path

    def run(self):
        path = utils.element_path(self.arguments[0].strip())

        group = _GroupNode(path=path)
        group.document = self.state.document
        set_source_info(self, group)

        return [group]

class _GroupTopicListExpander:
    def __init__(self, app, docname):
        self._app = app
        self._docname = docname

    def expand(self, node):
        group = self._app.jf_soup.element_by_path(node.path)
        topics = (t for _,t in group.iter_recursive() if isinstance(t, Topic))
        graph = self._app.jf_soup.worldgraph().subgraph(topics)
        topo = topological_sort(graph)

        bl = nodes.bullet_list()
        for topic in reversed(list(topo)):
            if not isinstance(topic, Topic):
                continue
            li = nodes.list_item()
            li += self._topic_paragraph(topic.path)
            bl += li
        node.replace_self(bl)

    def _topic_paragraph(self, path):
        topic = self._app.jf_soup.element_by_path(path)
        assert isinstance(topic, Topic), f'dependency on non-topic {path}?'
        p = nodes.paragraph()
        p += self._topic_headline_elems(path)
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
