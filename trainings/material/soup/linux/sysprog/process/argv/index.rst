.. ot-topic:: sysprog.process.argv

.. include:: <mmlalias.txt>


Argument Vector (``argv``)
==========================

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/basics/intro/process`
   * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/050-command-line-arguments/topic`

Argument Vector (``int argc, char** argv``)
-------------------------------------------

* Passing parameters to programs
* ``argc``: number of arguments
* ``argv``: string array - the "argument vector"
* ``argv[0]``: how the command was invoked (unused, mostly)

.. image:: argv.dia
   :scale: 40%

.. literalinclude:: code/argv.cpp
   :language: c++
   :caption: :download:`code/argv.cpp`

.. code-block:: console

   $ ./argv
   argc: 1
   argv[0]: ./argv
   
.. code-block:: console

   $ ./argv hello sweetheart
   argc: 3
   argv[0]: ./argv
   argv[1]: hello
   argv[2]: sweetheart
