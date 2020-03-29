from docutils import nodes
from docutils.parsers.rst import Directive
from sphinx.util.nodes import set_source_info


def setup(app):
    app.add_directive("jf-screenplay", ScreenplayDirective)
    app.connect("doctree-read", _collect_screenplays)

def _collect_screenplays(app, doctree):
    # carry a sitewide soup. lacking a place to init soup, we init
    # soup lazily.
    if not hasattr(app.builder.env, '_jf_screenplays'):
        app.builder.env._jf_screenplays = [] # [(docname: nodeid)]
    screenplays = app.builder.env._jf_screenplays

    # if document (doctree represents one) is a screenplay, add it to
    # soup.
    spnodes = list(doctree.traverse(ScreenplayNode))
    if len(spnodes) == 0:
        return
    if len(spnodes) == 1:
        node = spnodes[0]
        docname = app.builder.env.docname
        nodeid = node.nodeid

        # check duplicates. todo: SphinxError
        assert docname not in (docname for docname,_ in screenplays)
        assert nodeid not in (nodeid for _,nodeid in screenplays)

        if False:
            # argh. app.builder.env is pickled and comes back with all
            # its entries. build up a second "live/current" list, and
            # compare both?
            app.builder.env._jf_screenplays.append((docname, nodeid))

        # remove node from document (writers know nothing about it)
        node.parent.remove(node)

        return

    # todo: SphinxError
    assert False, f'document {docname} has {len(spnodes)} screenplays'

class ScreenplayNode(nodes.Element):
    def __init__(self, nodeid):
        super().__init__()
        self._nodeid = nodeid
    @property
    def nodeid(self): return self._nodeid

class ScreenplayDirective(Directive):
    required_arguments = 1   # nodeid

    def run(self):
        node = ScreenplayNode(nodeid=self.arguments[0].strip())
        set_source_info(self, node)
        return [node]
