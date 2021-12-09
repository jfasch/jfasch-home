.. include:: <mmlalias.txt>

.. ot-topic:: c.introduction.functions
   :dependencies: c.introduction.exercise_histogram


Functions
=========

Functions
---------

**Function (subroutine, procedure): why?**

* Externalizing code |longrightarrow| multiple use
* Program structure
* Readability
* |longrightarrow| Key to modularization

*How?*

* No difference between *function* and *procedure*
* Function call can be used as value (is an expression)
* *Except* return type is ``void``

A Nonsensical Example
---------------------

.. literalinclude:: power.c
   :language: c
   :caption: :download:`power.c`

Function *Signature*
--------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          int power(int base, int n)

     * * Function name (``power``)
       * Names *and types* of parameters
       * Return type

* Parameters are *local* to function
* Parameter names only relevant inside function
* No conflicts with the outer world
* |longrightarrow| caller may use name ``base`` and ``i``

Discussion
----------

.. list-table::
   :align: left

   * * .. code-block:: c

          int p = 1;

     * Local variable

   * * .. code-block:: c

          while (n--)

     * * ``n--`` ... *Post increment*
       * Expression's value is ``n``'s value *before* increment

   * * .. code-block:: c

          p *= base;

     * Shorthand for ``p = p * base;``

   * * .. code-block:: c

          return p;

     * *Value* of the function as seen by the caller

Definition vs. Declaration (1)
------------------------------

To generate a function call, the compiler wants to know its
*prototype* |longrightarrow| error checks

* Number of parameters
* Types of parameters
* Return type

Historical baggage: implicit function declarations |longrightarrow|
best avoided using function declarations

* ``-Wimplicit``: warning issued when function called without
  declaration
* ``-Werror``: treat warnings as errors |longrightarrow| hygiene

Definition vs. Declaration (2)
------------------------------

**Declaration:** declares prototype without giving a definition

.. list-table::
   :align: left

   * * .. code-block:: c

          int power(int base, int n);

     * "Dear compiler: I promise that the function will have this
        prototype, please check"

* Definition can be given later
* ... in the same file, after the call
* ... in a different file (|longrightarrow| later)

*By Value* / *By Reference*
---------------------------

**Parameters are only passed by value**

* Function receives a *local copy* of the caller's value
* Modifications not visible to the caller
* Pass by reference |longrightarrow| pointers (later)

.. list-table::
   :align: left

   * * .. code-block:: c

          int power(int base, int n)
          {
              while (n--) ...
          }

     * Caller does not see modifications to ``n``
