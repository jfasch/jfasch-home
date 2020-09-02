Context Managers (Livehacking Tutorial)
=======================================

Exception Unsafety
------------------

.. list-table::
   :align: left

   * *

       .. literalinclude:: code/05-manual-file.py
	  :caption: :download:`code/05-manual-file.py`
	  :language: python

       .. code-block:: console

          $ python code/05-manual-file.py
          Traceback (most recent call last):
            File "code/05-manual-file.py", line 3, in <module>
              if line.find('jfasch') >= 0:
          TypeError: argument should be integer or bytes-like object, not 'str'

     * * File object remains open
       * Fix would have to have ``try ... finally``
       * Convoluted

Exception Safety
----------------

.. list-table::
   :align: left

   * *

       .. literalinclude:: code/10-with-file.py
	  :caption: :download:`code/10-with-file.py`
	  :language: python

       .. code-block:: console

          $ python code/10-with-file.py 
	  jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

     *


#. encapsulate that into context manager, raw ``__enter__`` and
   ``__exit__``
#. find more esoteric example. replace print to do coloring?
#. contextlib.contextmanager

.. code-block:: python

   orig_print = print
   def prefix_print(*args, **kwargs):
       pfargs = ('prefix',) + args
       orig_print(*pfargs, **kwargs)
   print = prefix_print
   print('blah')
