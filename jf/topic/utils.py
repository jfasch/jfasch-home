from .soup import Soup
from .topic import Topic

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


def sphinx_add_topic(app, docname, title, path, dependencies):
    if hasattr(app, 'jf_soup'):
        raise TopicError('Soup already created, cannot add one more topic')
    if not hasattr(app.env, 'jf_elements'):
        app.env.jf_elements = {}

    app.env.jf_elements[docname] = {
        'type': 'topic',
        'title': title,
        'path': path,
        'dependencies': dependencies,
    }

def sphinx_purge_doc(app, env, docname):
    if hasattr(env, 'jf_elements'):
        env.jf_elements.pop(docname, None)

def sphinx_create_soup(app):
    if hasattr(app, 'jf_soup'):
        return

    app.jf_soup = Soup()
    for docname, elem in app.env.jf_elements.items():
        ty = elem['type']
        if ty == 'topic':
            app.jf_soup.add_element(
                Topic(title=elem['title'], path=elem['path'], docname=docname,
                      dependencies=elem['dependencies']))
        else:
            raise TopicError(f'{docname}: unknown type "{ty}"')

    app.jf_soup.commit()
