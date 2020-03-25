def doctree_read(app, doctree):
    pass

def setup(app):
    app.connect("doctree-read", doctree_read)
