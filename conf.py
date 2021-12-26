# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,

# documentation root, use os.path.abspath to make it absolute, like shown here.
#

import logging
import os
import sphinx_rtd_theme


# -- Project information -----------------------------------------------------
_me = 'Jörg Faschingbauer'
_canonical = 'https://www.faschingbauer.me'
project = author = _me
copyright = '2019-2021 (GPLv3), '+_me
html_title = _me
html_baseurl = _canonical
release = version = ''

# -- General configuration ---------------------------------------------------
master_doc = 'index'
templates_path = []

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.todo',
    'sphinx.ext.viewcode',
    'sphinx.ext.autodoc',
    'sphinx.ext.graphviz',
    'sphinx.ext.intersphinx',
    'ablog',
    'nbsphinx',
    # ??? 'sphinxcontrib.fulltoc',
    'sphinxcontrib.programoutput',
    'sphinxcontrib.images',
    'sphinxemoji.sphinxemoji',

    'sphinx_rtd_theme',
    'opentraining',
]

html_theme = 'sphinx_rtd_theme'
html_theme_options = {
    'collapse_navigation': False,
    'navigation_depth': -1,
    'prev_next_buttons_location': None,
    
    # 'includehidden': False,
    # 'style_external_links': True,
}

# context that jinja (and rst, via the rstjinja extension) sees.
html_context = {
    # experimental: this is how we can get settings into templates
    'READTHEDOCS': False, # {en,dis}able versions.html
    'versions': [('blah', 'https://www.google.com'),],
}

intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'opentraining': ('https://opentraining.readthedocs.io/en/latest/', None),
    'pytest': ('https://docs.pytest.org/en/latest/', None),
    'numpy': ('https://numpy.org/doc/stable/', None),
}

todo_include_todos = True

# ablog
if True:
    import ablog
    templates_path.append(ablog.get_html_templates_path())
    post_date_format = '%Y-%m-%d'

    blog_title = u'Jörg Faschingbauer'
    blog_path = 'blog'

    # a side effect of setting blog_baseurl is that atom.xml feeds
    # are generated altogether
    blog_baseurl = _canonical

    blog_authors = {
        'jfasch': ('Jörg Faschingbauer', _canonical),
    }
    blog_default_author = 'jfasch'
    
    blog_locations = {
        'daham': ('Graz, Austria', 'https://de.wikipedia.org/wiki/Graz'),
    }
    blog_default_location = 'daham'
    fontawesome_link_cdn = 'https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.min.css'
    blog_feed_fulltext = True
    blog_feed_length = 10
    blog_feed_archives = True

    # feed is http://feeds.feedburner.com/JoergFaschingbauer

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = [
    '_build',
    '**.ipynb_checkpoints',
]
html_context = {}
html_static_path = ['_static']

def rstjinja(app, docname, source):
    """Render our pages as a jinja template for fancy templating goodness.

    Eroc Holscher mentions this somewhere in his blog.

    """
    # Make sure we're outputting HTML
    if app.builder.format != 'html':
        return
    src = source[0]
    rendered = app.builder.templates.render_string(
        src, app.config.html_context
    )
    source[0] = rendered

def setup(app):
    app.connect("source-read", rstjinja)

    app.add_css_file('css/jf.css')

    # html_sidebars has two matches, and both match any /blog/
    # docname. the first match is more specific than the second, which
    # I consider a common case. nevertheless sphinx generates a
    # warning. filter that out.

    # (rant) I have no idea what's the benefit of wrapping loggers
    # into LoggerAdapter's. Or what SphinxLoggerAdapter's purpose
    # is. Fortunately the LoggerAdapter (victim.logger) is friendly
    # enough to have a 'logger' member. gosh; I only want to silence a
    # warning.
    class NoWarnMultipleMatches(logging.Filter):
        def filter(self, record):
            return 'matches two patterns in html_sidebars' not in record.getMessage()
    import sphinx.builders.html as victim
    victim.logger.logger.addFilter(NoWarnMultipleMatches())
