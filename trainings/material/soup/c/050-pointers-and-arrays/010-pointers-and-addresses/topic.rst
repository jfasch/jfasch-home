.. include:: <mmlalias.txt>

.. ot-topic:: c.pointers_and_arrays.pointers_and_addresses
   :dependencies: c.functions_and_program_structure.c_preprocessor_advanced


Pointers and Addresses
======================

.. contents::
   :local:

Pointers: Basics
----------------

**Pointer** is a **Memory address**

* Variable that *points* to another variable
* Basis for e.g. *call-by-reference*
* Simple in theory
* Practically difficult and dangerous

**Pointer to integer (64 bit)**

.. list-table::
   :align: left

   * * 

       .. image:: 05-01-pointer-to-int.dia

     * 
       .. figure:: addrspace.png

	  Showing the entire address space (``0..2^64-1``) (a Wacom
	  sketch, made during :doc:`a course
	  </trainings/log/detail/2021-07-12/index>`)

Pointer: Operators
------------------

**Operations**

* *Taking an address*: what is the address of the variable ``i``?
* *Dereferencing*: what is the content of the memory location that a
  pointer points to?

.. image:: 05-01-pointer-to-int-small.dia

.. list-table::
   :align: left

   * * **Taking an address**

       .. code-block:: c

          int i = 35129;
          int *pi;
          pi = &i;

     * **Dereferencing**

       .. code-block:: c

          int value = *pi;
          /* value == 35129 */

More Examples
-------------

.. code-block:: c

   int x = 1, y = 2;
   int *pi; /* pointer to int */
   
   pi = &x; /* "pi points to x" */
   *pi == 1; /* true */
   x = 42;
   *pi == 42; /* true */
   pi = &y;
   *pi == 2; /* true */
   
   *pi = *pi + 1;
   *pi += 1;
   y == 4; /* true */
   
   pi = 0; /* null pointer */
