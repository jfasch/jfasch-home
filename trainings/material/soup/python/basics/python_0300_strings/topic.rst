.. include:: <mmlalias.txt>


More About Strings
==================

String Delimiters
-----------------

* Double quotes ("...") or single quotes ('...')
* No difference

  .. jupyter-execute::
  
     'spam eggs'
  
  .. jupyter-execute::
  
     "spam eggs"

* Single quote (``'``) embedded as literal character inside a string
  delimited with single quotes |longrightarrow| *escaping* needed

  .. jupyter-execute::
  
     'doesn\'t'

* Alternative: choose double quote as string delimiter

  .. jupyter-execute::
  
     "doesn't"

* Or, the other way around

  .. jupyter-execute::
  
     '"Yes," he said.'

* No way out though if both double *and* single quotes need to be part
  of a string

  .. jupyter-execute::
  
     '"Isn\'t," she said.'

Escape Sequences
----------------

* Newline, embedded in string

  .. jupyter-execute::
  
     print('first line\nsecond line')

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

* Unwanted escaping (Doze pathnames) ...

  .. jupyter-execute::

     print('C:\some\name')
     print(r'C:\some\name')

* Unwanted escaping (regular expressions)

  .. jupyter-execute::
     
     import re
     regex = re.compile(r'^(.*)\.(\d+)$')

Multiline Strings
-----------------

**Escaping newlines is no fun** ...

.. jupyter-execute::

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

* String literal concatenation

  .. jupyter-execute::

     'Hello' ' ' 'World'

* String literal concatenation (multiple lines)

  .. jupyter-execute::

     ('Hello'
     ' '
     'World')
