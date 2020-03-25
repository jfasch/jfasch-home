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
sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------
_me = 'Jörg Faschingbauer'
project = author = _me
copyright = '2020, '+_me
html_title = _me
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
    'sphinx_rtd_theme',
    'ablog',
    'nbsphinx',
    'sphinxcontrib.fulltoc',

    'jf',
]
todo_include_todos = True

# ablog
if True:
    import ablog
    templates_path.append(ablog.get_html_templates_path())
    post_date_format = '%Y-%m-%d'

    blog_title = u'Jörg Faschingbauer'
    blog_path = 'blog'

    # a side effect of setting blog_baseurl is that atom.axml feeds
    # are generated altogether
    blog_baseurl = 'https://www.faschingbauer.me'

    blog_authors = {
        'jfasch': ('Jörg Faschingbauer', 'https://www.faschingbauer.me'),
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

_BASIC = 'basic'
_RTD = 'sphinx_rtd_theme'
_BETTER = 'better'
_CLOUD = 'cloud'
_PYRAMID = 'pyramid'
_PRESS = 'press'
_NATURE = 'nature'
_ALABASTER = 'alabaster'
_BOOTSTRAP = 'bootstrap'

html_theme = _ALABASTER
html_theme_path = []
html_theme_options = {}

_jf_csss = []

if html_theme == _ALABASTER:
    # RANT: the settings below (page_width 90%, sidebar_width 20% (of
    # page_width, essentially)) result in 

    # * div.bodywrapper: margin-left: 20% (=274.75 on my screen)

    # * div.sphinxsidebar: width: 20% (305.267)

    # though the plan is obviously that they have the same calculated
    # size, so the sphinxsidebar fits in bodywrapper's left
    # margin. (sidenote: why the f**k is it done in this way? why not
    # just position clearly with ... whatever ... some flexbox fancy?)

    # however: this *not* the case. for some reason (*), the
    # calculated values are *not* equal, and the sidebar's
    # width=305.267 overlaps into bodywrapper's 274.75 margin-left.

    # (*) hmm ... when I look at the element hierarchy, I see that

    # * div.sphinxsidebar is a child of div.document

    # * div.bodywrapper is a child of div.documentwrapper which is a
    #   child of div.document

    # question: how can it be that bodywrapper'div.s margin-left
    # calculates to a value that appears to be derived from
    # div.document?

    # ANYWAY: stick with it, but keep looking out for better
    # solutions/themes. learn to do web crap better.

    import alabaster

    html_theme_path.append(alabaster.get_path())

    templates_path.append('_templates')

    html_theme_options.update({
        'fixed_sidebar': True,
        'logo': 'logo.jpg',
        'description': 'Linux und Open Source',
        'page_width': '90%',
        'sidebar_width': '20%',

        # hardwired by default by "basic" theme, to 800px. no idea
        # why. occupy what we can get.
        'body_max_width': '100%',

        # 'github_banner': True,
        # 'github_button': True,

        'font_family': '"Lucida Sans Unicode", "Lucida Grande", sans-serif;'
    })

    html_sidebars = {
        # the more specific match must come first (fortunately
        # dictionary order is preserved since 3.7 :-) prior to that we
        # would have had no chance to fix that other than changing
        # html_sidebars to a list of tuples).
        'blog/**': [
            'about.html',
            'searchbox.html',
            'navigation.html',
            'postcard.html',
        ],
        '**': [
            'about.html',
            'searchbox.html',
            'navigation.html',
        ],
    }

    html_context.update({
        'jf_nav_bg': '#f0f3f8',
        'jf_info_bg': '#fcfcfc',
        'jf_note_bg': '#eee',
    })

    _jf_csss.append('css/jf-alabaster.css')

if html_theme == _RTD:
    # nav and location feedback really great
    
    # looks good on mobile
    
    # on wider screen a lot of screen real estate to the right is wasted
    
    # html_sidebars disregarded

    # RTD css unreadable (uglified?)
    
    html_theme_options['collapse_navigation'] = False
    html_theme_options['navigation_depth'] = -1
    
    # context that jinja (and rst, via the rstjinja extension) sees.
    html_context.update({
        # experimental: this is how we can get settings into templates
        'READTHEDOCS': False, # {en,dis}able versions.html
        'versions': [('blah', 'https://www.google.com'),],
    
        # reading the RTD theme sources, I see that this is the RTD way of
        # adding my own css.
        'extra_css_files': ['_static/css/jf.css'],
    })

if html_theme == _BETTER:
    from better import better_theme_path
    html_theme_path = [better_theme_path]

if html_theme == _CLOUD:
    html_theme_options['max_width'] = '100%'
    pass

if html_theme == _PYRAMID:
    import pyramid_sphinx_themes
    html_theme_path += pyramid_sphinx_themes.get_html_themes_path()

if html_theme == _PRESS:
    # html_sidebars as set above won't work. emptying it does,
    # somehow.

    # nav is buggy.
    pass

if html_theme == _NATURE:
    pass

if html_theme == _BASIC:
    pass

if html_theme == _BOOTSTRAP:
    # just a try, no navigation with location feedback

    import sphinx_bootstrap_theme
    html_theme_path += sphinx_bootstrap_theme.get_html_theme_path()




def rstjinja(app, docname, source):
    """
    Render our pages as a jinja template for fancy templating goodness.
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
    for css in _jf_csss:
        app.add_stylesheet(css)

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
