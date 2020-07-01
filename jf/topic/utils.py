from .soup import Soup

from docutils import nodes


def list_of_stripped_str(optval):
    'directive option conversion'
    return [s.strip() for s in optval.split(',')]

def path_from_dotted_str(elem_name):
    return tuple(s.strip() for s in elem_name.split('.'))

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
    print('jjjj', app.env.jf_elements)
    for docname, elem in app.env.jf_elements.items():
        ty = elem['type']
        if ty == 'topic':
            app.jf_soup.add_element(
                Topic(title=elem['title'], path=elem['path'], docname=docname,
                      dependencies=elem['dependencies']))
        else:
            raise TopicError(f'{docname}: unknown type "{ty}"')

    app.jf_soup.commit()
