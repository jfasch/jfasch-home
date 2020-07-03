from .sphinxglue import topic
from .sphinxglue import group
from .sphinxglue import topiclist
from .sphinxglue import graph
from .sphinxglue import soup

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes


logger = logging.getLogger(__name__)

def setup(app):
    app.connect('env-purge-doc', soup.sphinx_purge_doc)

    topic.setup(app)
    group.setup(app)
    topiclist.setup(app)
    graph.setup(app)


