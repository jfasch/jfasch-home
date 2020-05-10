from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from docutils import nodes


def setup(app):
    app.add_directive('jf-topiclist', _TopicListDirective)
    app.connect('doctree-resolved', _ev_doctree_resolved__expand_topiclist_nodes)

def _ev_doctree_resolved__expand_topiclist_nodes(app, doctree, docname):
    expander = TopicListExpander(gibberish=app.jf_gibberish, docname=docname)
    for n in doctree.traverse(_TopicListNode):
        expander.expand(n)

class _TopicListNode(nodes.Element):
    pass

class _TopicListDirective(SphinxDirective):
    def run(self):
        node = _TopicListNode()
        node.document = self.state.document
        set_source_info(self, node)
        return [node]

class TopicListExpander:
    def __init__(self, gibberish, docname):
        self._gibberish = gibberish
        self._docname = docname

    def expand(self, node):
        bl = nodes.bullet_list()
        for topic in self._gibberish.app.jf_gibberish.soup:
            li = nodes.list_item()
            li += self._topic_paragraph(topic.id)
            bl += li
        node.replace_self(bl)

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
