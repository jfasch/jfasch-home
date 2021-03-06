from .node import Node


class Task(Node):
    def __init__(self, title, path, docname, dependencies,
                 initial_estimate, spent, percent_done):
        super().__init__(title=title, path=path, docname=docname, dependencies=dependencies)
        self.initial_estimate = float(initial_estimate)
        self.spent = float(spent)
        self.percent_done = float(percent_done)

    def __str__(self):
        return 'Task:'+super().__str__()
