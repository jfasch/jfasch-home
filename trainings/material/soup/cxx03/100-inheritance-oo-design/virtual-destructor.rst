.. ot-topic:: cxx03.inheritance_oo.virtual_destructor
   :dependencies: cxx03.inheritance_oo.virtual_method,
		  cxx03.inheritance_oo.destructor,
		  cxx03.inheritance_oo.polymorphism

.. include:: <mmlalias.txt>


Virtual Destructors
===================

.. contents:: 
   :local:

*Is-A* Relationships And Destructors
------------------------------------

* From :doc:`destructor`: simple/naive destructors are not enough when
  using object polymorpically
* Much like simple/naive methods vs. *virtual* methods
* |longrightarrow| *virtual destructors*, starting at the root of
  inheritance
* |longrightarrow| *dynamic dispatch* to destructor of concrete
  object's class
* |longrightarrow| correct cleanup

.. literalinclude:: code/inher-oo-dtor-derived-virtual.cpp
   :caption: :download:`code/inher-oo-dtor-derived-virtual.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-dtor-derived-virtual 
   Derived::~Derived()
   Base::~Base()

Pure Virtual Destructor?
------------------------

* Object destruction calls *every* destructor up to the innermost base
  class
* |longrightarrow| Destructors cannot be pure virtual

.. literalinclude:: code/inher-oo-dtor-pure-virtual.cpp
   :caption: :download:`code/inher-oo-dtor-pure-virtual.cpp`
   :language: c++

.. code-block:: console

   inher-oo-dtor-pure-virtual.cpp:15: undefined reference to `Base::~Base()'
   collect2: error: ld returned 1 exit status
   
