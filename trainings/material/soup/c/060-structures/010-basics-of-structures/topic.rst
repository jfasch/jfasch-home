.. include:: <mmlalias.txt>

.. jf-topic:: c.structures.basics
   :dependencies: c.pointers_and_arrays.command_line_arguments

``struct``: Basics
==================

.. contents::
   :local:

``struct``: Compound Datatypes
------------------------------

**So far** we had ...

* Scalar datatypes: ``int``, ``float``, ...
* Pointers
* Now for some ... *design*

**Fantasy:**

* Pointers give us power to do more
* How do we build more complex data structures?

  * Linked lists
  * Balanced trees
  * ...

``struct``: How?
----------------

**Short and to the point ...**

.. code-block:: c

   /* type declaration - no memory set aside */
   struct point
   {
       int x;
       int y;
   };
   
   /* set aside memory for two points */
   struct point p1, p2;

* *New type:* ``struct point``
* Used just the same as other types

Usage
-----

.. list-table::
   :align: left

   * * **Operations**

       * Initialization
       * Copy ...

         * Assignment
         * Parameter passing
         * Return from function

       * Member access

     * .. code-block:: c

          /* initialization */
	  struct point p = { 42, 7 };
          
          /* member access */
          p.x = 1;
          
          /* assignment */
          p2 = p;

Nested Structures
-----------------

.. list-table::
   :align: left

   * * **Nesting**

       * Nesting is possible
       * But: structures become large through nesting
       * *Call-by-value* (and ``return``) makes *copies*!

     * .. code-block: c

          struct rect
          {
              struct point p1;
              struct point p2;
          };

Memory Layout
-------------

.. list-table::
   :align: left

   * * Structures are laid out in *flat memory*

       * Linear sequence of bytes
       * *Copy* (assignment, parameter, return) of memory is made

     * .. code-block:: c

          struct rect
          {
              struct point p1;
              struct point p2;
          };

.. image:: 06-01-00-memory-layout.dia

Recursive Structures?
---------------------

.. code-block:: c

   struct xxx
   {
       struct xxx x;
   };

* That particular structure would be infinitely large
* |longrightarrow| Compiler error
* |longrightarrow| *Pointers*
