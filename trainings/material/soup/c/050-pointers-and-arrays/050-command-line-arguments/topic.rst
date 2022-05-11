.. include:: <mmlalias.txt>

.. ot-topic:: c.pointers_and_arrays.command_line_arguments
   :dependencies: c.pointers_and_arrays.pointers_and_arrays

Commandline Arguments
=====================

.. contents::
   :local:

``main()`` Can Take Parameters
------------------------------

**So far:** ``int main(void)``

* A process has an *exit status* |longrightarrow| implicitly ``int
  main(...)``
* |longrightarrow| compiler magic: ``main()`` is special
* C++: compiler error if ``main()`` does not return an ``int``
* No commandline arguments expected |longrightarrow| ``main(void)``

|longrightarrow| How are commandline arguments passed?

Commandline Arguments
---------------------

.. code-block:: c

   int main(int argc, char **argv)
   {
       char *opt = argv[1]; /* "-l" */
       char *dir = argv[2]; /* "/tmp" */
       ...
   }

``ls -l /tmp``

.. image:: 05-10-00-argv-main.dia
