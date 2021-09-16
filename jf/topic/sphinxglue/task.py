from . import utils
from . import soup
from .graph import TopicGraphNode
from .. import errors

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-task', _TaskDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_tasknodes)

def _ev_doctree_read__extract_tasknodes(app, doctree):
    try:
        docname = app.env.docname
        task_nodes = list(doctree.traverse(_TaskNode))
        if len(task_nodes) > 1:
            raise errors.TopicError(f'{docname} contains multiple tasks')

        for tn in task_nodes:
            soup.sphinx_add_task(
                app=app, 
                docname=docname,
                title=utils.get_document_title(docname, doctree),
                path=tn.path, 
                dependencies=tn.dependencies,
                responsible=tn.responsible,
                initial_estimate=tn.initial_estimate,
                spent=tn.spent,
                percent_done=tn.percent_done,
            )
            tn.replace_self([])
    except Exception:
        logger.exception(f'{docname}: cannot extract task nodes')
        raise
        
class _TaskNode(nodes.Element):
    def __init__(self, path, dependencies,
                 responsible, initial_estimate, spent, percent_done):
        super().__init__(self)
        self.title = None
        self.path = path
        self.dependencies = dependencies
        self.responsible = responsible
        self.initial_estimate = initial_estimate
        self.spent = spent
        self.percent_done = percent_done

class _TaskDirective(SphinxDirective):
    required_arguments = 1   # path

    option_spec = {
        'dependencies': utils.list_of_element_path,
        'responsible': str,
        'initial-estimate': int,
        'spent': int,
        'percent-done': int,
    }

    def run(self):
        path = utils.element_path(self.arguments[0].strip())
        dependencies = self.options.get('dependencies', [])
        responsible = self.options.get('responsible', '')
        initial_estimate = self.options.get('initial-estimate', 0)
        spent = self.options.get('spent', 0)
        percent_done = self.options.get('percent-done', 0)

        task = _TaskNode(path=path, 
                         dependencies=dependencies,
                         responsible=responsible,
                         initial_estimate=initial_estimate, 
                         spent=spent, 
                         percent_done=percent_done)
        task.document = self.state.document
        set_source_info(self, task)

        # graph = TopicGraphNode(entries=[path])
        # graph.document = self.state.document
        # set_source_info(self, graph)

        return [task
                # , graph
                ]

