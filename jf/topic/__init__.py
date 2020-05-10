from . import list
from . import graph
from . import utils
from .soup import Soup
from . import topic
from .gibberish import Gibberish

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
    app.connect('builder-inited', _ev_builder_inited__setup_gibberish)

    topic.setup(app)
    list.setup(app)
    graph.setup(app)

def _ev_builder_inited__setup_gibberish(app):
    if not hasattr(app.env, 'jf_topic_soup'):
        app.env.jf_topic_soup = Soup()
    app.jf_gibberish = Gibberish(app=app, soup=app.env.jf_topic_soup)

