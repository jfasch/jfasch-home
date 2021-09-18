.. include:: <mmlalias.txt>

.. ot-topic:: c.program_sanity.struct_initialization
   :dependencies: c.program_sanity.const


Struct Initialization
=====================

Good Old Struct Initialization
------------------------------

.. code-block:: c

   struct person
   {
     char fn[16];
     char ln[16];
     int age;
     int height;
   };
   struct person me = { "Joerg", "Faschingbauer", 50, 172 };

**As always: Ambiguity**


* One can only guess as to what the initializer means

  * Imagine somebody's name is "Beman Dawes"
  * ``age``? ``height``? Or is it ``weight``?

* Have to lookup the definition of ``struct person``

C99 *Designated Initializer*
----------------------------

.. code-block:: c

   struct person me = {
     .fn = "Joerg",
     .ln = "Faschingbauer",
     .age = 50,
     .height = 172
   };

**Consequences:**

* A couple more characters of typing
* Safety: when member names (semantics?) change, the compiler *forces* checking
* **Clarity**
