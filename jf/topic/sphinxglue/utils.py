from docutils import nodes


def element_path(pathstr):
    return [c.strip() for c in pathstr.split('.')]

def list_of_element_path(pathliststr):
    paths = [p.strip() for p in pathliststr.split(',')]
    return [element_path(p) for p in  paths]

def get_document_title(docname, doctree):
    for section in doctree.traverse(nodes.section):
        break
    else:
        raise Exception(f'{docname}: no <section> found')
    for title in section.traverse(nodes.title):
        return title.astext()
    else:
        raise Exception(f'{docname}: first <section> has no <title>')

