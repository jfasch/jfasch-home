from .node import Node


class Exercise(Node):
    def __init__(self, title, path, docname, dependencies):
        super().__init__(title=title, path=path, docname=docname, dependencies=dependencies)

    def __str__(self):
        return 'Exercise:'+super().__str__()
