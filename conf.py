# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#

import logging
import os
import sys

#sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------
_me = 'Jörg Faschingbauer'
_canonical = 'https://www.faschingbauer.me'
project = author = _me
copyright = '2019-2025 (GPLv3), '+_me
html_title = _me
html_baseurl = _canonical
release = version = ''

# -- General configuration ---------------------------------------------------
master_doc = 'index'
templates_path = []

# suppress terminal color codes during "cmake -P ..." inclusion via
# ".. command-output::"
os.environ['CLICOLOR'] = '0'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.todo',
    'sphinx.ext.viewcode',
    'sphinx.ext.autodoc',
    'sphinx.ext.doctest',
    'sphinx.ext.graphviz',
    'sphinx.ext.intersphinx',
    'ablog',

    'nbsphinx',
    'jupyter_sphinx',

    #'IPython.sphinxext.ipython_directive',    
    # .../notebook.ipynb:: WARNING: Could not lex literal_block as "ipython3". Highlighting skipped.    
    #'IPython.sphinxext.ipython_console_highlighting',

    # ??? 'sphinxcontrib.fulltoc',
    'sphinxcontrib.programoutput',
    'sphinxcontrib.images',
    'sphinxemoji.sphinxemoji',
    'sphinx_design',

    'sphinxcontrib.plantuml',

    'opentraining.sphinxglue.dia',
]
intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'opentraining': ('https://opentraining.readthedocs.io/en/latest/', None),
    'pytest': ('https://docs.pytest.org/en/latest/', None),
    'numpy': ('https://numpy.org/doc/stable/', None),
}
todo_include_todos = True

plantuml_output_format = 'svg_img'

# nbsphinx by default loads RequireJS, and changes config to do
# so. sphinx then warns me that the config has changed @#$%. suppress
# that by setting those config options to not-None.
nbsphinx_requirejs_path = ''
nbsphinx_requirejs_options = 666

# libreoffice_format = dict(latex='pdf', html='svg')

# ablog
if True:
    import ablog
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
html_css_files = ['mycss.css']

html_theme = 'pydata_sphinx_theme'
html_theme_path = []
html_theme_options = {}


if False: # Gaphor
    extensions.append("gaphor.extensions.sphinx")

    # the extensions does not regognize .gaphor files which I can then
    # refer to by name. bring that information in.

    # normally, this should not be a burden because models are cental
    # to a project anyway, phycially existing in ``Documentation/``
    # once and for all.

    gaphor_models = {  
        "fh_source_sink": './about/site/work-in-progress/playground/gaphor/SourceAndSink.gaphor',
    }    

if True:
    html_context['default_mode'] = 'light'
    html_theme_options['logo'] = {
        'image_light': '_static/logo.png',
        'image_dark': '_static/logo.png',
    }
    html_theme_options['show_prev_next'] = False
    html_theme_options['secondary_sidebar_items'] = ['page-toc']
    html_theme_options['navbar_end'] = ["navbar-icon-links"]
    html_theme_options['navbar_align'] = 'left'
    html_theme_options['footer_start'] = ['copyright']
    html_theme_options['footer_center'] = ['sphinx-version', 'theme-version']
    html_theme_options['footer_end'] = ['sourcelink']

    fontawesome_included = True

def rstjinja(app, docname, source):
    """Render our pages as a jinja template for fancy templating goodness.

    Eric Holscher mentions this somewhere in his blog.

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
    app.add_css_file('mycss.css')

    app.connect("source-read", rstjinja)

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
