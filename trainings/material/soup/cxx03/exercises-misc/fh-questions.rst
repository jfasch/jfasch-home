FH/Moodle Quiz: C++
===================

.. contents::
   :local:

Questions
---------

* C/C++: Undefined behavior

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * When an action is said to lead to *undefined behavior*, this
         means that the program *will* crash
       *
       * n
     * * When an action is said to lead to *undefined behavior*, this
         means that the program *could* crash
       * y
       *
     * * When an action is said to lead to *undefined behavior*, this
         means that the program *will* continue but *will* wreak havoc on
         its data
       *
       * n
     * * When an action is said to lead to *undefined behavior*, this
         means that the program *could* continue but *could* wreak
         havoc on its data
       * y
       *

* C++: ``const``: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A variable declared ``const`` can only be initialized and
         never modified.
       * y
       *
     * * A variable of type ``int`` which is declared ``const`` is
         initialized to 0 if no initializer is given.
       *
       * n
     * * Class members cannot be declared ``const``
       *
       * n
     * * ``const`` class member variables can be initialized in the
         constructor body
       *
       * n
     * * A *method* declared ``const`` promises to the compiler (and
         the caller) that a call to it does not modify the object it
         is called on
       * y
       *
     * * Declaring a class constructor ``const`` leads to undefined
         behavior
       *
       * n

* C++ references: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A reference variable can be left uninitialized
       *
       * n
     * * A caller that passes a variable to a function/method as a
         reference must take into account that the variable could be
         modified
       * y
       *
     * * A caller that passes a variable to a function/method as a
         ``const`` reference must take into account that the variable
         could be modified
       *
       * n

* C++ Overloading: which of the followings statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * In C++, there cannot be multiple definitions of a function
         with the same name
       *
       * n
     * * In C++, there can be multiple definitions of a function, just
         with different parameters
       * y
       *
     * * The term overloading refers to a technique where one can have
         multiple definitions of a class, and use them interchangeably
       *
       * n

* C++ Constructors: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A default constructor initializes an object when no
         initialization parameters are given
       * y
       *
     * * A copy constructor need only be implemented when member-wise
         copy is not sufficient
       * y
       *
     * * A copy constructor must be implemented in any case
       *
       * n

* STL: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * ``std::vector<>`` guarantees that it keeps elements in
         contiguous memory
       * y
       *
     * * In a ``std::vector<>`` instance that contains three elements,
         accessing index 3 (``vec[3]``) leads to undefined behavior
       * y
       *
     * * In a ``std::vector<>`` instance that contains three elements,
         accessing index 0 (``vec[0]``) leads to undefined behavior
       *
       * n
