.. include:: <mmlalias.txt>


Copy Constructor, Assignment Operator
=====================================

.. contents::
   :local:

Compiler Generated Copy Constructor
-----------------------------------

.. admonition:: **Rule**

   Copy constructor and copy assignment operator are automatically
   generated if ...

   * there is no user defined move constructor
   * there is no user defined move assignment operator

.. sidebar::

   **See also**

   * :doc:`object-copy`
   * :doc:`/trainings/material/soup/cxx/cxx11/move/index`

The venerable ``class point`` from :doc:`cpp-introduction` is simple

* Contains only data members
* Has no user-defined copy constructor |longrightarrow|
  compiler-generated
* Does not do *resource management* in whatever way (see :doc:`here
  <object-copy>` for why this is dangerous)
* |longrightarrow| letting the compiler its way is fine

Copy constructor in action (no matter if it is generated or
hand-written) ...

.. literalinclude:: code/cpp-generated-copy.cpp
   :caption: :download:`code/cpp-generated-copy.cpp`
   :language: c++

Manually Written Copy Constructor And Assignment Operator
---------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`object-copy`

.. caution::

   **Careful**: if you find yourself writing a copy constructor ...

   * You should be writing an assignment operator just as well
   * You should probably implement :doc:`move semantics
     </trainings/material/soup/cxx/cxx11/move/index>`
     just as well
   * You should probably implement a destructor just as well
   * You should probably be careful, and read :doc:`object-copy`

   |longrightarrow| *Rule of 5/0*

For demonstration purposes: a completely nonsensical copy constructor
and assignment operator:

.. literalinclude:: code/cpp-manual-copy.cpp
   :caption: :download:`code/cpp-manual-copy.cpp`
   :language: c++
