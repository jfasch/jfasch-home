class Topic:
    def __init__(self, title, id, docname, dependencies):
        self.title = title
        self.id = id
        self.docname = docname
        self.dependencies = dependencies


from . import utils

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
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
        return [_TopicNode(topic=Topic(title = self.options.get('title', None),
                                      id = self.arguments[0].strip(),
                                      docname = self.env.docname,
                                      dependencies = self.options.get('dependencies', []),
        ))]            

