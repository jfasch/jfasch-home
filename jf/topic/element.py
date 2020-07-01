from . import errors


class Element:
    def __init__(self, title, path, docname):
        if type(path) is not tuple:  # need hashable
            raise errors.NotPath(f'Not a valid path: {path} (must be tuple)')
        for elem in path:
            if type(elem) is not str:
                raise errors.NotPath(f'Not a valid path: {path} ({elem} is not str)')
            if not elem.isidentifier():
                raise errors.NotPath(f'Not a valid path: {path} ({elem} is not an identifier)')

        self.title = title
        self.docname = docname
        if path:
            self._requested_path = path
        else:   # root group; no parent
            self.parent = None

    def __str__(self):
        if hasattr(self, '_requested_path'):
            return f'{self._requested_path} (uncommitted)'
        else:
            return f'{self.path}'

    @property
    def path(self):
        if hasattr(self, '_requested_path'):
            raise errors.TopicError(f'{self} is not yet committed (path not known)')
        if self.parent:
            return self.parent.path + [self.parent.element_name(self)]
        else:
            return []
