from . import utils
from . import soup
from .. import errors

from sphinx.util.docutils import SphinxDirective
from sphinx.util.nodes import set_source_info
from sphinx.util import logging
from docutils import nodes

logger = logging.getLogger(__name__)


def setup(app):
    app.add_directive('jf-exercise', _ExerciseDirective)
    app.connect('doctree-read', _ev_doctree_read__extract_exercisenodes)

def _ev_doctree_read__extract_exercisenodes(app, doctree):
    try:
        docname = app.env.docname
        exercise_nodes = list(doctree.traverse(_ExerciseNode))
        if len(exercise_nodes) > 1:
            raise errors.TopicError(f'{docname} contains multiple exercises')

        for en in exercise_nodes:
            soup.sphinx_add_exercise(
                app=app, 
                docname=docname,
                title=utils.get_document_title(docname, doctree),
                path=en.path, 
                dependencies=en.dependencies)
            en.replace_self([])
    except Exception:
        logger.exception(f'{docname}: cannot extract topic nodes')
        raise
        
class _ExerciseNode(nodes.Element):
    def __init__(self, path, dependencies):
        super().__init__(self)
        self.title = None
        self.path = path
        self.dependencies = dependencies

class _ExerciseDirective(SphinxDirective):
    required_arguments = 1   # path

    option_spec = {
        'dependencies': utils.list_of_element_path,
    }

    def run(self):
        path = utils.element_path(self.arguments[0].strip())
        dependencies = self.options.get('dependencies', [])

        exercise = _ExerciseNode(path=path, dependencies=dependencies)
        exercise.document = self.state.document
        set_source_info(self, exercise)

        return [exercise]

