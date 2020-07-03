from . import utils
from . import soup
from .graph import TopicGraphNode
from .. import errors

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-topic', _TopicDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_topicnodes)

def _ev_doctree_read__extract_topicnodes(app, doctree):
    try:
        docname = app.env.docname
        topic_nodes = list(doctree.traverse(_TopicNode))
        if len(topic_nodes) > 1:
            raise errors.TopicError(f'{docname} contains multiple topics')

        for tn in topic_nodes:
            soup.sphinx_add_topic(
                app=app, 
                docname=docname,
                title=utils.get_document_title(docname, doctree),
                path=tn.path, 
                dependencies=tn.dependencies)
            tn.replace_self([])
    except Exception:
        logger.exception(f'{docname}: cannot extract topic nodes')
        raise
        
class _TopicNode(nodes.Element):
    def __init__(self, path, dependencies):
        super().__init__(self)
        self.title = None
        self.path = path
        self.dependencies = dependencies

class _TopicDirective(SphinxDirective):
    required_arguments = 1   # path

    option_spec = {
        'dependencies': utils.list_of_element_path,
    }

    def run(self):
        path = utils.element_path(self.arguments[0].strip())
        dependencies = self.options.get('dependencies', [])

        topic = _TopicNode(path=path, dependencies=dependencies)
        topic.document = self.state.document
        set_source_info(self, topic)

        graph = TopicGraphNode(entries=[path])
        graph.document = self.state.document
        set_source_info(self, graph)

        return [topic, graph]

