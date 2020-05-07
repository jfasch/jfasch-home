from .soup import Soup
from .topic import Topic

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
    app.add_directive('jf-topic', TopicDirective)
    app.add_directive('jf-topiclist', TopicListDirective)
    app.connect('env-purge-doc', _purge_doc)
    app.connect('doctree-resolved', _doctree_resolved__convert_topiclist)

def _purge_doc(app, env, docname):
    if hasattr(env, 'jf_topic_soup'):
        env.jf_topic_soup.purge(docname)

def _list_of_str(optval):
    return ','.split(optval)

def _get_soup(env):
    if not hasattr(env, 'jf_topic_soup'):
        env.jf_topic_soup = Soup()
    return env.jf_topic_soup
    
class TopicDirective(SphinxDirective):
    required_arguments = 1   # topicid

    option_spec = {
        'dependencies': _list_of_str,
    }

    def run(self):
        soup = _get_soup(self.env)

        topicid = self.arguments[0].strip()
        dependencies = self.options.get('dependencies')

        soup.add(
            Topic(topicid=topicid,
                  docname=self.env.docname,
                  dependencies=dependencies,
            ))

        return []

class TopicList(nodes.General, nodes.Element):
    pass

class TopicListDirective(SphinxDirective):
    def run(self):
        node = TopicList()
        node.document = self.state.document
        set_source_info(self, node)

        return [node]

def _doctree_resolved__convert_topiclist(app, doctree, docname):
    soup = _get_soup(app.env)
    if len(soup) == 0:
        return

    for topiclist in doctree.traverse(TopicList):
        bl = nodes.bullet_list()
        for topic in soup:
            ref = nodes.reference()
            ref['refuri'] = app.builder.get_relative_uri(from_=docname, to=topic.docname)
            ref.append(nodes.Text(topic.topicid))

            par = nodes.paragraph()
            par.append(ref)

            li = nodes.list_item()
            li.append(par)

            bl.append(li)

        topiclist.replace_self(bl)
