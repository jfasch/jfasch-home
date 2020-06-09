.. include:: <mmlalias.txt>

Python: Miscellaneous String Methods
====================================

.. contents::
   :local:

.. jf-topic:: python_0320_strings_methods
   :dependencies: python_0310_strings_formatting,
		  python_0300_strings

Batteries Included: Checks
--------------------------

**Lots of small checks (returning boolean)** - for example ...

* ``'...'.isspace()``: contains only whitespace
* Character types

  * ``'...'.isalpha()``
  * ``'...'.isalnum()``
  * ``'...'.isdigit()``

* Case tests

  * ``'...'.isupper()``
  * ``'...'.islower()``

* ``'...'.isidentifier()``: a valid python identifier (e.g. variable
  name)
* Lots of others |longrightarrow| save work and `RTFM
  <https://docs.python.org/3.8/library/stdtypes.html#text-sequence-type-str>`__
  prior to coding

Batteries Included: Search
--------------------------

**Substring search** ...

* ``'...'.count(s)``: number of occurences of ``s``
* ``'...'.startswith(s)``, ``.endswith(s)``
* ``'...'.find(sub[, start[, end]])``: find ``sub``, starting at
  ``start`` (default 0), ending at ``end`` (default ``len()``)

  * ``end`` is *exclusive* |longrightarrow| ``'...'[start:end]``
  * Returns index, or -1 if not found

* ``'...'.index(sub[, start[, end]])``: like find, but raises
  exception if not found
* ``'...'.rfind(sub[, start[, end]])``: from the end
* ``'...'.rindex(sub[, start[, end]])``: from the end

Substring Search: Examples
--------------------------

.. code-block:: python

   >>> '/etc/passwd'.startswith('/etc/')
   True
   >>> 'notes.txt'.endswith('.txt')
   True
   >>> 'this is a thistle with many thorns'.count('th')
   4
   >>> 'haystack containing needle and straw'.find('needle')
   20
   >>> 'haystack containing needle and straw'.find('mouse')
   -1
   >>> 'haystack containing needle and straw'.index('mouse')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   ValueError: substring not found

Split and Join (1)
------------------

* *Very* common operations
* Error prone |longrightarrow| writing them is a major annoyance
* Off-by-one errors

.. code-block:: python
   :caption: ``split()`` and ``join()``

   >>> 'one:two:three'.split(':')
   ['one', 'two', 'three']
   >>> ':'.join(['one', 'two', 'three'])
   'one:two:three'

.. code-block:: python
   :caption: Not off-by-one

   >>> ':'.join([])
   ''
   >>> ':'.join(['one'])
   'one'

Split and Join (2)
------------------

.. code-block:: python
   :caption: Split at most 2 fields

   >>> 'one:two:three:four'.split(':', 2)
   ['one', 'two', 'three:four']
   >>> 'one:two:three:four'.rsplit(':', 2)
   ['one:two', 'three', 'four']

.. code-block:: python
   :caption: Real life example: ``/etc/passwd``

   >>> username,rest = 'jfasch:x:1000:...'.split(':', 1)
   >>> username
   'jfasch'
   >>> rest
   'x:1000:1000::/home/jfasch:/bin/bash'
