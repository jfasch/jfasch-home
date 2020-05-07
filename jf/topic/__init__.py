from .soup import Soup
from .topic import Topic

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
    app.add_directive('jf-topic', TopicDirective)
    app.add_directive('jf-topiclist', TopicListDirective)
    app.connect('env-purge-doc', _purge_doc)
    app.connect('doctree-resolved', _doctree_resolved__expand_topiclists)
    app.connect('doctree-read', _doctree_read__extract_topicnodes)

def _purge_doc(app, env, docname):
    if hasattr(env, 'jf_topic_soup'):
        env.jf_topic_soup.purge(docname)

def _list_of_stripped_str(optval):
    return [s.strip() for s in optval.split(',')]

def _get_soup(env):
    if not hasattr(env, 'jf_topic_soup'):
        env.jf_topic_soup = Soup()
    return env.jf_topic_soup

class TopicNode(nodes.Element):
    def __init__(self, topic):
        super().__init__(self)
        self.topic = topic

class TopicDirective(SphinxDirective):
    required_arguments = 1   # topicid

    option_spec = {
        'title': str,
        'dependencies': _list_of_stripped_str,
    }

    def run(self):
        return [TopicNode(topic=Topic(title = self.options.get('title', None),
                                      topicid = self.arguments[0].strip(),
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

def _doctree_read__extract_topicnodes(app, doctree):
    docname = app.env.docname
    soup = _get_soup(app.env)
    for tn in doctree.traverse(TopicNode):
        topic = tn.topic
        if not topic.title:
            topic.title = _get_doctree_title(docname, doctree)
        soup.add(topic)
        tn.replace_self([])

class TopicListNode(nodes.Element):
    pass

class TopicListDirective(SphinxDirective):
    def run(self):
        node = TopicListNode()
        node.document = self.state.document
        set_source_info(self, node)

        return [node]

def _doctree_resolved__expand_topiclists(app, doctree, docname):
    soup = _get_soup(app.env)

    for topiclist in doctree.traverse(TopicListNode):
        topics_bl = nodes.bullet_list()
        for topic in soup:
            topic_li = nodes.list_item()
            topics_bl.append(topic_li)

            paragraph = nodes.paragraph()
            topic_li.append(paragraph)

            paragraph.append(nodes.Text(topic.title))
            topic_meta_bl = nodes.bullet_list()
            paragraph.append(topic_meta_bl)

            title_li = nodes.list_item()
            title_li.append(nodes.Text(topic.title))
            topic_meta_bl.append(title_li)

            id_li = nodes.list_item()
            id_li.append(nodes.Text(topic.topicid))
            topic_meta_bl.append(id_li)

            if topic.dependencies:
                dependencies_li = nodes.list_item()
                dependencies_li.append(nodes.Text(','.join(topic.dependencies)))
                topic_meta_bl.append(dependencies_li)

            # ref = nodes.reference()
            # ref['refuri'] = app.builder.get_relative_uri(from_=docname, to=topic.docname)
            # ref.append(nodes.Text(topic.topicid))

            # par = nodes.paragraph()
            # par.append(ref)

            # li = nodes.list_item()
            # li.append(par)

            # bl.append(li)

        topiclist.replace_self(topics_bl)
