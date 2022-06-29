.. ot-topic:: cxx03.functions_and_methods.operators
   :dependencies: cxx03.functions_and_methods.static

.. include:: <mmlalias.txt>


Operator Overloading
====================

.. contents::
   :local:

Motivation
----------

Returning back to the venerable ``class point``,

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y) : _x{x}, _y{y} {}
   
       int x() const { return _x; }
       int y() const { return _y; }

       void move(point vec);
   
   private:
       int _x;
       int _y;
   };

**Equality of two points?** I don't want to have another function (or
:doc:`static method <../060-static/topic>`) like,

.. code-block:: c++

   if (points_equal(p1, p2)) 
       ...

**Enter operators**

I want to write something like

.. code-block:: c++

   if (p1 == p2)
       ...

**What else?**

* *Arithmetic operators*: 2D space os full of arithmetic, so why not
  write for example ...

  .. code-block:: c++

     point vec{2,3}
     p += vec;

* *Stream operators*: this is rather clumsy,

  .. code-block:: c++

     std::cout << '(' << p.x() << ',' << p.y() << ')' << std::endl;

  I want to shift a point out,

  .. code-block:: c++

     std::cout << p << std::endl;

Implementing (In)Equality
-------------------------

* Operators are ordinary functions
* Only named a bit oddly: ``operator==()``
* Most operators can be defined in two way

  * As global function (equality would then take two ``point``
    parameters)
  * As object method: "hey left point, are you equal to this other
    point?"

Implementing (In)Equality: Global Function
------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../010-overloading/topic`

* Global function: a third party authority (global function, not
  belonging to a class) examines two points for equality

  * Makes use of :doc:`overloading <../010-overloading/topic>`: there
    might be other ``==`` operators defined for different types
  * *No access to private members of operands* (could use the
    ``friend`` keyword though)


* Makes sense to define equality *and* inequality together
* |longrightarrow| one can be implemented in terms of the other

.. literalinclude:: code/eq-global.cpp
   :caption: :download:`code/eq-global.cpp`
   :language: c++

Implementing (In)Equality: Object Method
----------------------------------------

* As a matter of taste: why not ask a point object if it is equal to
  another point object
* Preferred by most: does not have the difficulties from above
* Usage no different between both ways
* Equality check does not normally modify objects |longrightarrow|
  ``const``

.. literalinclude:: code/eq-object.cpp
   :caption: :download:`code/eq-object.cpp`
   :language: c++

Implementing Arithmetic: ``+`` (Vector Addition)
------------------------------------------------

* As with ``operator==()``, there are two ways

  * Global function ``operator+(point lhs, point rsh)``
  * *Preferred*: object method ``operator+(point rhs) const``

Implementing Arithmetic: ``+`` (Vector Addition): Global Function
-----------------------------------------------------------------

.. literalinclude:: code/add-global.cpp
   :caption: :download:`code/add-global.cpp`
   :language: c++

Implementing Arithmetic: ``+`` (Vector Addition): Object Method
---------------------------------------------------------------

.. literalinclude:: code/add-object.cpp
   :caption: :download:`code/add-object.cpp`
   :language: c++

Implementing Arithmetic: ``+=`` (Moving A Point)
------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../040-this/topic`

* ``+=`` can only be an object method (it is there to modify an
  object, alas)
* Things are little confusing otherwise
* |longrightarrow| Beginning in C, ``+=`` has a value

  .. literalinclude:: code/add-object.cpp
     :caption: :download:`code/add-object.cpp`
     :language: c++

* When overloading ``operator+=()``, usually (a reference to) the
  modified object is the value

  * Could be a copy just as well |longrightarrow| possibly expensive

* |longrightarrow| ``*this`` |:thinking:|

.. literalinclude:: code/plus-equal.cpp
   :caption: :download:`code/plus-equal.cpp`
   :language: c++

Implementing ``ostream`` Shift: ``std::cout << ...``
----------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../010-overloading/topic`

* Make use of :doc:`overloading <../010-overloading/topic>` again
* Overload (global) ``std::ostream& operator<<(std::ostream&, point)``

.. literalinclude:: code/c++03-ostream-shift-operator.cpp
   :caption: :download:`code/c++03-ostream-shift-operator.cpp`
   :language: c++

.. code-block:: console

   $ ./c++03-ostream-shift-operator 
   p1: (1,2), p2: (3,4)
