.. include:: <mmlalias.txt>


Encoding
========

.. contents::
   :local:

ASCII
-----

.. list-table::
   :align: left
   :widths: 10 20

   * * * ASCII: American Standard Code for Information Interchange
       * A character has 7 bits of information. Apparently bytes in a
	 computer were composed of 7 bits at that time.
       * ``encoding = 'ascii'``
     * .. figure:: ascii-table-overcoded-2048x1220.jpg
          :scale: 50%

	  (Kindly copied from
	  https://www.overcoded.net/ascii-table-512119/)

.. _iso-8859-1:

ISO Latin 1 (ISO-8859-1)
------------------------

.. list-table::
   :align: left
   :widths: 10 20

   * * * Bytes have 8 bits of information, nowadays
       * One bit is wasted
       * Latin Europeans (and Germans) said, "Hey, lets use all 8 bits
	 and cram umlauts and accents in"
       * ASCII on steroids
       * ``encoding = 'iso-8859-1'``
     * .. figure:: latin1.gif
          :scale: 50%

	  (Kindly copied from
	  https://www.htmlhelp.com/reference/charset/latin1.gif)

And Python?
-----------

* ``str`` is `Unicode <https://en.wikipedia.org/wiki/Unicode>`__
* :doc:`Sequence
  </trainings/material/soup/python/basics/python_0200_sequential_types/topic>`
  of *Unicode Code Points*

  * To differentiate the concept from *characters* (which are
    generally thought of as having eight bits)
  * Size of a code point is irrelevant (if at all defined)
  * *Enough room to contain all Chinese character sets*, for example
  * "One encoding to rule them all"

* Python programs (usually) use strings internally

  * No encoding mistakes

Liebe Grüße, Jörg
-----------------

Python strings are Unicode |longrightarrow| all fine (but see
:ref:`later <source-encoding>`) ...

.. code-block:: python

   >>> s = 'Liebe Grüße, Jörg'
   >>> type(s)
   <class 'str'>
   >>> len(s)
   17

Is that ASCII? Probably not:

.. code-block:: python

   >>> s.encode(encoding='ascii')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   UnicodeEncodeError: 'ascii' codec can't encode characters in position 8-9: ordinal not in range(128)

A Better Encoding for *Liebe Grüße, Jörg*: ISO-8859-1
-----------------------------------------------------

.. code-block:: python

   >>> enc = s.encode(encoding='iso-8859-1')
   >>> enc
   b'Liebe Gr\xfc\xdfe, J\xf6rg'
   >>> type(enc)
   <class 'bytes'>
   >>> len(enc)
   17

* Bytes: 8 bit entities, *not* Unicode characters of transparent
  character size
* ISO-8859-1 is a *single byte encoding* |longrightarrow| 17 bytes,
  just as the Unicode character count in the original string.

.. code-block:: python

   >>> 0xfc, 0xdf, 0xf6
   (252, 223, 246)

Aha. Lookup in :ref:`table <iso-8859-1>`:

.. csv-table::
   :align: left

   252,ü
   223,ß
   246,ö

Encoding Mess
-------------

.. code-block:: python

   >>> s = 'Liebe Grüße, Jörg'
   >>> enc = s.encode('iso-8859-1')

* Send ``enc`` in an Email (which is a chunk of bytes)
* Somewhere in Russia, receive Email (ISO-8859-5 is their ASCII on
  steroids - the Cyrillic alphabet in a single byte encoding)

.. code-block:: python

   >>> received_enc = enc     # receive Email
   >>> received_enc.decode('iso-8859-5')
   'Liebe Grќпe, Jіrg'

And *祝好, Jörg*? (1)
-----------------------

"祝好" is Chinese for "Liebe Grüße" (kindly taken from `here
<http://www.new-chinese.org/lernwortschatz-chinesisch-emails-schreiben.html>`__)

.. list-table::
   :align: left

   * * .. code-block:: python

          >>> lg = '祝好'
	  >>> len(lg)
	  2
     * After all, it's two Unicode code points
   * * .. code-block:: python

          >>> lg_enc = lg.encode('big5')
	  >>> len(lg_enc)
	  4
     * * `Big5 <https://en.wikipedia.org/wiki/Big5>`__ is one of many
         Chinese character sets.
       * Apparently multi-byte |longrightarrow| 4.

And *祝好, Jörg*? (2)
-----------------------

* Mixed string?
* No, it's all Unicode

.. code-block:: python

   >>> name = 'Jörg'
   >>> bye = lg + ', ' + name
   >>> bye
   '祝好, Jörg'

* Write that out
* Need to choose an encoding

.. code-block:: python

   >>> bye.encode('iso-8859-1')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   UnicodeEncodeError: 'latin-1' codec can't encode characters in position 0-1: ordinal not in range(256)
   >>> bye.encode('big5')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   UnicodeEncodeError: 'big5' codec can't encode character '\xf6' in position 5: illegal multibyte sequence

* Hell!

Enter UTF-8
-----------

* `Wikipedia <https://en.wikipedia.org/wiki/UTF-8>`__
* Variable length encoding
* Compatible with ASCII

.. code-block:: python

   >>> bye_enc = bye.encode('utf-8')
   >>> bye_enc
   b'\xe7\xa5\x9d\xe5\xa5\xbd, J\xc3\xb6rg'

* A-ha: "祝好" takes 6 bytes in UTF-8
* A-ha: "ö" takes 2 bytes (as opposed to one in Latin-1)
* A-ha: "J", "r", and "g" have the same ordinal as in ASCII (not shown
  here)

**One encoding to rule them all**

Boundary Code
-------------

* Python code deals with strings internally |longrightarrow| Unicode

  * Mixing Chinese with German is the norm
  * Technically, this is not mixing, because it is ... well
    ... Unicode

* When strings leave Python at the *boundary*, they are converted into
  binary data |longrightarrow| *encoded*

  * Explicitly, using ``str.encode()``
  * Implicitly (|longrightarrow| :doc:`File I/O
    </trainings/material/soup/python/basics/python_0500_files/topic>`, Web,
    E-Mail)

Ah Yes: ``decode()``
--------------------

* Same is true for the opposite direction: bringing bytes *into* a
  Python program, at the *boundary*
* Explicitly, using ``str.decode()``
* Implicitly

.. code-block:: python

   >>> bye_enc.decode('utf-8')
   '祝好, Jörg'

* Of course this is not restricted to UTF-8

.. _source-encoding:

And Source Encoding?
--------------------

**Interactive interpreter** (as used in those slides)

* Uses whatever encoding the terminal is set to be in
* Linux is all UTF-8, nowadays

**Source code**

* Dogmatic rule: source code is 7 bit ASCII, comments and variable
  names are in English
* Breaking the rule leads to encoding mess
* Solution (if you really want)

  .. code-block:: python

     # -*- coding: utf-8 -*-
