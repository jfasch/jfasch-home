from . import errors
from .element import Element
from .node import Node


class Group(Element):
    def __init__(self, title, path, docname):
        super().__init__(title=title, path=path, docname=docname)
        self._children = {}    # {name: element}

    def __str__(self):
        return 'Group:'+super().__str__()

    def __len__(self):
        return len(self._children)

    def add_element(self, element):
        child_name = element._requested_path[0]
        if len(element._requested_path) == 1: # leaf; add to children
            child = self._children.get(child_name)
            if child:
                raise errors.TopicError(f'{self}: cannot add "{child_name}"; already exists: {child}')
            self._children[child_name] = element
            del element._requested_path
            element.parent = self
        else:
            parent = self._children.get(child_name)
            if parent is None:
                raise errors.TopicError(f'{self}: cannot add "{element._requested_path}": '
                                        f'intermediate "{child_name}" does not exist')
            element._requested_path = element._requested_path[1:]
            parent.add_element(element)

    def element_by_path(self, path):
        '''Get element by path. path is relative to this group.'''

        element = self._children.get(path[0])
        if element is None:
            raise errors.PathNotFound(f'{self}: no element with name "{path[0]}"')
        if len(path) == 1:
            return element
        try:
            return element.element_by_path(path[1:])
        except errors.PathNotFound:
            raise errors.PathNotFound(f'{self}: no element with name "{path[0]}"')

    def child_by_name(self, name):
        '''Get direct child element by name.'''
        child = self._children.get(name)
        if child is None:
            raise errors.TopicError(f'{self}: no child with name {name}')
        return child

    def element_name(self, element):
        '''Get name of element under which it is know to his group.

        Raises TopicError if element not there.

        '''
        for name, elem in self._children.items():
            if elem is element:
                return name
        else:
            raise errors.TopicError(f'{element} is not a child of {self}')

    def has_element(self, element):
        '''Does this group have the element?'''
        for name, elem in self._children.items():
            if elem is element:
                return True
        return False

    def iter_children(self):
        '''Iterator (name, element) over direct children'''
        yield from self._children.items()

    def iter_recursive(self):
        '''Iterator (name, element) over descendants, recursively'''
        for name, elem in self._children.items():
            if isinstance(elem, Node):
                yield name, elem
            elif isinstance(elem, Group):
                yield name, elem
                #yield from elem.iter_children_dfs()
                for n,e in elem.iter_recursive():
                    yield n,e
            else:
                assert False, f'invalid element type {type(e)}'
