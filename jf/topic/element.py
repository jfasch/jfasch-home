from . import errors


class Element:
    def __init__(self, title, path, docname):
        verify_is_path(path)

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


def verify_is_path(path):
    if type(path) not in (list, tuple):
        raise errors.BadPath(f'Not a valid path: {path} is neither list nor tuple')
        
    for elem in path:
        if type(elem) is not str:
            raise errors.BadPath(f'Not a valid path: {path} ({elem} is not str)')
        if not elem.isidentifier():
            raise errors.BadPath(f'Not a valid path: {path} ({elem} is not an identifier)')
    
