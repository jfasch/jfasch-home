from . import graph
from . import utils
from .soup import Soup
from .topic import Topic
from .gibberish import Gibberish

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
    app.connect('builder-inited', _ev_builder_inited__setup_gibberish)

    app.add_directive('jf-topic', TopicDirective)
    app.add_directive('jf-topiclist', TopicListDirective)
    app.add_directive('jf-topicgraph', graph.TopicGraphDirective)

    app.connect('env-purge-doc', _ev_env_purge_doc)
    app.connect('doctree-read', _ev_doctree_read__extract_topicnodes)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topiclists)
    app.connect('doctree-resolved', graph.event_doctree_resolved__expand_topicgraph_nodes)

def _ev_builder_inited__setup_gibberish(app):
    if not hasattr(app.env, 'jf_topic_soup'):
        app.env.jf_topic_soup = Soup()
    app.jf_gibberish = Gibberish(app=app, soup=app.env.jf_topic_soup)

def _ev_env_purge_doc(app, env, docname):
    app.jf_gibberish.soup.purge(docname)

class TopicNode(nodes.Element):
    def __init__(self, topic):
        super().__init__(self)
        self.topic = topic

class TopicDirective(SphinxDirective):
    required_arguments = 1   # topicid

    option_spec = {
        'title': str,
        'dependencies': utils.list_of_stripped_str,
    }

    def run(self):
        return [TopicNode(topic=Topic(title = self.options.get('title', None),
                                      id = self.arguments[0].strip(),
                                      docname = self.env.docname,
                                      dependencies = self.options.get('dependencies', []),
        ))]            

def _get_doctree_title(docname, doctree):
    for section in doctree.traverse(nodes.section):
        break
    else:
        raise Exception(f'{docname}: no <section> found')
    for title in section.traverse(nodes.title):
        return title.astext()
    else:
        raise Exception(f'{docname}: first <section> has no <title>')

def _ev_doctree_read__extract_topicnodes(app, doctree):
    docname = app.env.docname
    for tn in doctree.traverse(TopicNode):
        topic = tn.topic
        if not topic.title:
            topic.title = _get_doctree_title(docname, doctree)
        app.jf_gibberish.soup.add(topic)
        tn.replace_self([])

class TopicListNode(nodes.Element):
    pass

class TopicListDirective(SphinxDirective):
    def run(self):
        node = TopicListNode()
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

def _ev_doctree_resolved__expand_topiclists(app, doctree, docname):
    expander = app.jf_gibberish.topiclist_expander(docname)
    for topiclist in doctree.traverse(TopicListNode):
        topiclist.replace_self(expander.expand(topiclist))

