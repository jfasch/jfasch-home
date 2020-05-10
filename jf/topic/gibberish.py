from .soup import Soup

from docutils import nodes
import networkx as nx
class Gibberish:
    def __init__(self, app, soup):
        self._app = app
        self._soup = soup

    @property
    def app(self):
        return self._app
    @property
    def soup(self):
        return self._soup

    def topiclist_expander(self, docname):
        return TopicListExpander(gibberish=self, docname=docname)

