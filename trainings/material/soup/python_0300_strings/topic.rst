.. include:: <mmlalias.txt>

Python: More About Strings
==========================

.. contents::
   :local:

.. jf-topic:: python_0300_strings
   :dependencies: python_0200_sequential_types, 
		  python_0150_datatypes_overview, 
		  python_0250_refs_flat_deep_copy

String Delimiters
-----------------

**Delimiters**: double quotes ("...") or single quotes ('...'), as
needed

.. code-block:: python

   >>> 'spam eggs'  # single quotes
   'spam eggs'
   >>> 'doesn\'t'  # use \' to escape the single quote...
   "doesn't"
   >>> "doesn't"  # ...or use double quotes instead
   "doesn't"
   >>> '"Yes," he said.'
   '"Yes," he said.'
   >>> "\"Yes,\" he said."
   '"Yes," he said.'
   >>> '"Isn\'t," she said.'
   '"Isn\'t," she said.'

Escape Sequences
----------------

.. code-block:: python
   :caption: Newline, embedded in string

   >>> print('first line\nsecond line')
   first line
   second line

**More (but not all) escape sequences** ...

.. csv-table::
   :header: Escape character, Meaning
   :align: left

   ``\n``, Linefeed
   ``\r``, Carriage return
   ``\t``, Tab
   ``\b``, Backspace
   ``\0``, ASCII 0
   ``\130``, ASCII dec. 88 ('X') in octal
   ``\x58``, ASCII dec. 88 ('X') in hexadecimal

Raw Strings
-----------

**Unwanted escaping (Doze pathnames)** ...

.. code-block:: python

   >>> print('C:\some\name')
   C:\some
   ame
   >>> print(r'C:\some\name')
   C:\some\name

.. code-block:: python
   :caption: Unwanted escaping (regular expressions)

   regex = re.compile(r'^(.*)\.(\d+)$')

Multiline Strings
-----------------

**Escaping newlines is no fun** ...

.. code-block:: python

   print("""\
   Bummer!
   You messed it up!
   """)

will produce ...

.. code-block:: console

   Bummer!
   You messed it up!

* Note how the initial newline is escaped |longrightarrow| *line continuation*
* Newline must immediately follow backslash

More String Tricks
------------------

.. code-block:: python
   :caption: String literal concatenation

   >>> 'Hello' ' ' 'World'
   'Hello World'

.. code-block:: python
   :caption: String literal concatenation (multiple lines)

   >>> ('Hello'
   ... ' '
   ... 'World')
   'Hello World'
