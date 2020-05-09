from .soup import Soup

from docutils import nodes
import networkx as nx
from networkx.algorithms.dag import descendants
import matplotlib.pyplot as plt

import io


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

    def topicgraph_expander(self, docname):
        return TopicGraphExpander(gibberish=self, docname=docname)

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

class TopicGraphExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, topicgraph):
        world = nx.DiGraph()
        for topic in self._gibberish.soup:
            world.add_node(topic)
            for target_id in topic.dependencies:
                target_topic = self._gibberish.soup.find_id(target_id)
                world.add_edge(topic, target_topic)

        if len(topicgraph.entries):
            topics = set()
            for topic in (self._gibberish.soup.find_id(id) for id in topicgraph.entries):
                topics.add(topic)
                topics.update(descendants(world, topic))
            g = world.subgraph(topics)
            for n in g.nodes:
                print(n.id)
        else:
            g = world

        node_labels = {topic: topic.id for topic in g.nodes}
        nx.draw_networkx(g, labels=node_labels, with_label=True)

        data = io.StringIO()
        plt.savefig(data, format='svg')
        plt.clf()
        plt.cla()
        plt.close()


        s = data.getvalue()
        s = s[s.find('<svg'):]

        return [nodes.raw(s, s, format='html')]
