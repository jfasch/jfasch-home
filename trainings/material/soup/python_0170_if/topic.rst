.. include:: <mmlalias.txt>

The ``if`` Statement
====================

.. contents::
   :local:

.. jf-topic:: python.basics.python_0170_if
   :dependencies: python.basics.python_0160_boolean

The ``if`` Statement
--------------------

**Conditional code execution** ...

.. list-table::
   :align: left

   * - .. code-block:: python
          :caption: ``if``

          if i <= 3:
              print(i)

       .. code-block:: python
          :caption: ``else (optional)``

	  if i <= 3:
	      print(i)
	  else:
	      print('many')

     - .. code-block:: python
          :caption: ``elif (optional)``

          if i == 1:
              print('1')
          elif i == 2:
              print('2')
          elif i == 3:
              print('3')
          else:
              print('many')
