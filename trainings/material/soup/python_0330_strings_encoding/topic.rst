.. include:: <mmlalias.txt>

Python: Strings and Encoding
============================

.. contents::
   :local:

.. jf-topic:: python_0330_strings_encoding
   :dependencies: python_0300_strings

Character Encodings
-------------------

**Problem** ...

* Files (and networks, and ...) contain arbitrary bytes
* Files don't have an idea of their content
* |longrightarrow| Content can be anything

  * Raw bytes
  * Plain 7-bit ASCII
  * ISO 8859-1
  * One of 2156 Chinese (multibyte) character sets
  * One of 1375 Japanese (multibyte) character sets
  * UTF-8, UTF-16, UTF-32
  * Many *many* more ...

**Solution** ...

* Unicode --- one encoding to rule them all
* Internally, Python *strings* are sequences of Unicode *code points*

Strings and Encodings
---------------------

**Where does the data come from and go to?**

* Programmer has to know what the source contains, and act accordingly
* Raw bytes |longrightarrow| create ``bytes`` objects
* Strings |longrightarrow| which encoding?

  * Email: MIME headers (|longrightarrow| ``email`` module)
  * Files: specify ``encoding`` parameter at ``file`` object creation
    (|longrightarrow| later)
  * Otherwise: read byte data and convert to string objects

**At the programmer's responsibility!**

* Has always been programmer's responsibility
* Python 3 just doesn't let you mix ``str`` and ``bytes``

From Raw Bytes to Strings (1)
-----------------------------

**Pre-Unicode:** ISO/IEC 8859-1 ("Latin-1") for Mid-European alphabet

.. code-block:: python
   :caption: Jörg, as read from a file with unknown encoding

   >>> joerg_raw = b'J\xf6rg'
   >>> type(joerg_raw)
   <class 'bytes'>

* File happens to be Latin-1 encoded
* ``\xf6`` is "ö" in Latin-1
* ... but that information isn't there |longrightarrow| binary

From Raw Bytes to Strings (2)
-----------------------------

**Transformation to string should be done as early as possible**

* Everything's clear if one *knows* what's in
* |longrightarrow| Transformation to Unicode (rules them all)
* |longrightarrow| Nobody *has* to know anymore what's in

.. code-block:: python
   :caption: Transfer raw bytes into string

   >>> joerg = str(joerg_raw, encoding='iso-8859-1')
   >>> type(joerg)
   <class 'str'>
   >>> joerg
   'Jörg'

From Strings to Raw Bytes
-------------------------

**Internal string representation is Unicode**

* No-one cares (has to care)
* Unicode is a set of numbers, not a concrete encoding

.. code-block:: python
   :caption: "ö" is obviously multibyte in UTF-8

   >>> joerg.encode('utf-8')
   b'J\xc3\xb6rg'

.. code-block:: python
   :caption: "ö" is unknown in China

   >>> joerg.encode('big5')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   UnicodeEncodeError: 'big5' codec can't encode ....

Source File Encoding
--------------------

**Question:** how are string literals encoded?

* Default: ASCII
* |longrightarrow| umlauts not properly encoded in strings
* Unless otherwise specified

.. code-block:: python
   :caption: Explicit source encoding

   #!/usr/bin/python3
   # -*- encoding: utf-8 -*-

   print('Jörg')
