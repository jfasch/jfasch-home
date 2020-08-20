.. include:: <mmlalias.txt>

Positional and Keyword Arguments (Livehacking Screenplay)
=========================================================

.. contents::
   :local:

Plain Function with Positional Arguments
----------------------------------------

.. literalinclude:: code/10-plain-positional.py
   :caption: :download:`code/10-plain-positional.py`
   :language: python

.. code-block:: console

   $ python code/10-plain-positional.py 
   1 2
   3 4

Arbitrary Number of Arguments?
------------------------------

.. literalinclude:: code/20-arbitrary-positional-tuple.py
   :caption: :download:`code/20-arbitrary-positional-tuple.py`
   :language: python

.. code-block:: console

   $ python code/20-arbitrary-positional-tuple.py
   (1, 2, 3)

* A-ha: positional arguments passed as tuple
* "Unpack" tuple as positional arguments?

.. literalinclude:: code/30-unpack-positional.py
   :caption: :download:`code/30-unpack-positional.py`
   :language: python

.. code-block:: console

   $ python code/30-unpack-positional.py
   1 2 3

* Unpack any sequence as positional arguments?

.. literalinclude:: code/40-unpack-any-sequence-positional.py
   :caption: :download:`code/40-unpack-any-sequence-positional.py`
   :language: python

.. code-block:: console

   $ python code/40-unpack-any-sequence-positional.py
   1 2 3

And Keyword Arguments?
----------------------

* ``*args`` |longrightarrow| no parameter names
* no keyword arguments

.. literalinclude:: code/50-keyword-dict.py
   :caption: :download:`code/50-keyword-dict.py`
   :language: python

.. code-block:: console

   $ python code/50-keyword-dict.py
   {'a': 1, 'b': 2}

* A-ha: similar to ``*args``, ``**kwargs`` is passed as dictionary
* And unpacking |longrightarrow| same: ``**``

