from ..soup import Soup
from ..topic import Topic
from ..group import Group
from ..errors import TopicError


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

def sphinx_add_group(app, docname, title, path):
    if hasattr(app, 'jf_soup'):
        raise TopicError('Soup already created, cannot add one more group')
    if not hasattr(app.env, 'jf_elements'):
        app.env.jf_elements = {}

    app.env.jf_elements[docname] = {
        'type': 'group',
        'title': title,
        'path': path,
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
        elif ty == 'group':
            app.jf_soup.add_element(
                Group(title=elem['title'], path=elem['path'], docname=docname))
        else:
            raise TopicError(f'{docname}: unknown type "{ty}"')

    app.jf_soup.commit()
