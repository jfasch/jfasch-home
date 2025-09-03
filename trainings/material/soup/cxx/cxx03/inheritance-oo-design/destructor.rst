.. include:: <mmlalias.txt>


Destructors And Interfaces
==========================

.. contents:: 
   :local:

.. sidebar::

   **See also**

   * :doc:`basics`
   * :doc:`../020-data-encapsulation/ctor-dtor`

Destructor, Straightforward Usage
---------------------------------

* Lets say one of our sensor implementations allocates resources
  (e.g. by using ``new``)
* |longrightarrow| Destructor needed!
* Called at exit from function

.. literalinclude:: code/destructor-nonvirtual/sensors.h
   :caption: :download:`code/destructor-nonvirtual/sensors.h`
   :language: c++

.. literalinclude:: code/destructor-nonvirtual/main.cpp
   :caption: :download:`code/destructor-nonvirtual/main.cpp`
   :language: c++

.. code-block:: console

  $ ./code/destructor-nonvirtual/cxx-inher-oo-destructor-straightforward 
  MySensor::~MySensor()

Calling Destructor Through Base Class Pointer
---------------------------------------------

* What if ``MySensor`` object is

  * allocated on the heap?
  * only a ``Sensor*`` is used to represent it? (Polymorphic usage)
  * freed using a ``Sensor*``?

.. literalinclude:: code/destructor-nonvirtual/base-delete.cpp
   :caption: :download:`code/destructor-nonvirtual/base-delete.cpp`
   :language: c++

.. code-block:: console

  $ ./code/destructor-nonvirtual/cxx-inher-oo-destructor-base-delete
  ... remains silent ...

Virtual Destructor (Destructors Are Special)
--------------------------------------------

* Obviously, *dynamic dispatch* is needed for destructor too
* Compiler inserts code to call all destructors along the inheritance
  chain, up to the very base
* |longrightarrow| Cannot be ``virtual``
* |longrightarrow| Empty ``virtual`` 

Solution: Empty Virtual Destructor
----------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/default`

.. literalinclude:: code/destructor-virtual-nonempty/sensors.h
   :caption: :download:`code/destructor-virtual-nonempty/sensors.h`
   :language: c++

.. literalinclude:: code/destructor-virtual-nonempty/main.cpp
   :caption: :download:`code/destructor-virtual-nonempty/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/destructor-virtual-nonempty/cxx-inher-oo-destructor-virtual-nonempty 
   MySensor::~MySensor()
