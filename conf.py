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

import os
import sys
sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'Jörg Faschingbauer'
copyright = '2020, Jörg Faschingbauer'
author = 'Jörg Faschingbauer'

# The full version, including alpha/beta/rc tags
release = '0.0.0'


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
    blog_baseurl = 'https://faschingbauer.me'

    blog_authors = {
        'jfasch': ('Jörg Faschingbauer', 'https://faschingbauer.me'),
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


templates_path.append('_templates')

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# context that jinja (and rst, via the rstjinja extension) sees.
html_context = {
    # experimental: this is how we can get settings into templates
    'READTHEDOCS': False, # {en,dis}able versions.html
    'versions': [('blah', 'https://www.google.com'),],
}

# ---
html_theme = 'sphinx_rtd_theme'
html_theme_options = {
    'collapse_navigation': False,
    'navigation_depth': -1,
}

html_static_path = []

# hmmm. somehow this is disregarded by rtd theme.
html_sidebars = {
}
