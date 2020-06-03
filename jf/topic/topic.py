from . import utils

class Topic:
    def __init__(self, title, id, docname, dependencies):
        if not id.isidentifier():
            raise utils.TopicError(f'Topic id={id} is not an identifier')

        self.title = title
        self.id = id
        self.docname = docname
        self.dependencies = dependencies

