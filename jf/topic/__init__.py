from .soup import Soup
from .topic import Topic

from sphinx.util.docutils import SphinxDirective


def setup(app):
    app.add_directive('jf-topic', TopicDirective)
    app.connect('env-purge-doc', _purge_doc)

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
