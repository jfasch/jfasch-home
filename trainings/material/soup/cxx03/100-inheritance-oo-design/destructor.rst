.. ot-topic:: cxx03.inheritance_oo.destructor
   :dependencies: cxx03.inheritance_oo.basics,
		  cxx03.data_encapsulation.ctor_dtor

.. include:: <mmlalias.txt>


Destructors And Inheritance
===========================

.. contents:: 
   :local:

Plain (Base) Class
------------------

.. sidebar::

   **See also**

   * :doc:`basics`
   * :doc:`../020-data-encapsulation/ctor-dtor`

* Destructors are *almost* ordinary methods
* Except: they cannot be overridden
* This just would not make sense |longrightarrow| resource leaks in
  base class
* But wait ... lets start with a plain base class

.. literalinclude:: code/inher-oo-dtor-base.cpp
   :caption: :download:`code/inher-oo-dtor-base.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-dtor-base 
   Base::~Base()

Derived Class, And Destructor
-----------------------------

* Destroying derived class calls *all* destructors up to the innermost
  base class

.. literalinclude:: code/inher-oo-dtor-derived-novirtual.cpp
   :caption: :download:`code/inher-oo-dtor-derived-novirtual.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-dtor-derived-novirtual 
   Derived::~Derived()
   Base::~Base()

And Base Class Conversion?
--------------------------

.. sidebar::

   **See also**

   * :doc:`basics`

* **C++ mantra: unless you know a lot you cannot write bug-free code**
* Problem: just like *base class conversion* with ordinary
  (non-virtual) methods
* Which destructor is called when ``Derived`` is destroyed through a
  ``Base*``?
* *Spoiler*: only ``Base::~Base()``
* (Obviously only apparent when objects are allocated from dynamic
  memory)

.. literalinclude:: code/inher-oo-dtor-derived-novirtual-base-conversion.cpp
   :caption: :download:`code/inher-oo-dtor-derived-novirtual-base-conversion.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-dtor-derived-novirtual-base-conversion 
   Base::~Base()
