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

class TopicListExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, topiclist):
        bl = nodes.bullet_list()
        for topic in self._gibberish.app.jf_gibberish.soup:
            li = nodes.list_item()
            li += self._topic_paragraph(topic.id)
            bl += li
        return bl

    def _topic_paragraph(self, id):
        topic = self._gibberish.soup.find_id(id)
        p = nodes.paragraph()
        p += self._topic_headline_elems(id)
        if topic.dependencies:
            p += self._topic_dependencies(id)
        return p

    def _topic_headline_elems(self, id):
        topic = self._gibberish.soup.find_id(id)
        elems = []
        elems.append(nodes.Text(f'{topic.title} ('))

        ref = nodes.reference()
        ref['refuri'] = self._gibberish.app.builder.get_relative_uri(
            from_=self._docname, to=topic.docname)
        ref += nodes.Text(topic.id)
        elems.append(ref)

        elems.append(nodes.Text(')'))
        
        return elems
        
    def _topic_dependencies(self, id):
        topic = self._gibberish.soup.find_id(id)
        bl = nodes.bullet_list()
        for d in topic.dependencies:
            li = nodes.list_item()
            bl += li

            par = nodes.paragraph()
            li += par

            t = self._gibberish.soup.find_id(d)
            par += self._topic_headline_elems(t.id)
        return bl