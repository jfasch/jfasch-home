.. include:: <mmlalias.txt>


Miscellaneous String Methods
============================

.. topic:: Documentation

   * `Text Sequence Type — str
     <https://docs.python.org/3/library/stdtypes.html#text-sequence-type-str>`__

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

.. jupyter-execute::

   '/etc/passwd'.startswith('/etc/')

.. jupyter-execute::

   'notes.txt'.endswith('.txt')

.. jupyter-execute::

   'this is a thistle with many thorns'.count('th')

.. jupyter-execute::

   'haystack containing needle and straw'.find('needle')

* ``find()`` returns position - ``-1`` if not found

.. jupyter-execute::

   'haystack containing needle and straw'.find('mouse')

* ``index()`` returns position - raises if not found

.. jupyter-execute::
   :raises:

   'haystack containing needle and straw'.index('mouse')

Split and Join (1)
------------------

* *Very* common operations
* Error prone |longrightarrow| writing them is a major annoyance
* Off-by-one errors

.. jupyter-execute::

   'one:two:three'.split(':')

.. jupyter-execute::

   ':'.join(['one', 'two', 'three'])

.. jupyter-execute::

   ':'.join([])

.. jupyter-execute::

   ':'.join(['one'])

Split and Join (2)
------------------

* Split at most 2 fields

  .. jupyter-execute::

     'one:two:three:four'.split(':', 2)

  .. jupyter-execute::

     'one:two:three:four'.rsplit(':', 2)

* Real life example: ``/etc/passwd``

  .. jupyter-execute::

     username,rest = 'jfasch:x:1000:...'.split(':', 1)
     username

  .. jupyter-execute::

     rest
