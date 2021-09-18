.. include:: <mmlalias.txt>

.. ot-topic:: c.structures.typedef
   :dependencies: c.structures.structures_and_functions

``typedef``: Type Alias
=======================

Alias for Type Names
--------------------

**Why?**

* Semantics of a type is one story
* Implementation is another story
* Type names can become long

.. code-block:: c

   typedef unsigned long int uint64_t;
   typedef int pid_t;

|longrightarrow| Type name and alias name are equivalent
