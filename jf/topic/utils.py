from docutils import nodes


def list_of_stripped_str(optval):
    'directive option conversion'
    return [s.strip() for s in optval.split(',')]

def get_document_title(docname, doctree):
    for section in doctree.traverse(nodes.section):
        break
    else:
        raise Exception(f'{docname}: no <section> found')
    for title in section.traverse(nodes.title):
        return title.astext()
    else:
        raise Exception(f'{docname}: first <section> has no <title>')

