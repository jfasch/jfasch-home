.. include:: <mmlalias.txt>


Live Hacking: Handwritten Functors, And Capturing By Reference (Pitfalls)
=========================================================================

.. contents::
   :local:

Original, Handwritten Functor (By Copy)
---------------------------------------

.. literalinclude:: ../code/c++11-lambda-capture-handwritten.cpp
   :caption: :download:`../code/c++11-lambda-capture-handwritten.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture-handwritten
   howdy

Possible Pitfall: Capturing A Reference
---------------------------------------

.. literalinclude:: ../code/c++11-lambda-capture-handwritten-reference.cpp
   :caption: :download:`../code/c++11-lambda-capture-handwritten-reference.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture-handwritten-reference
   howdy

* Program creates a temporary ``std::string`` object (``"howdy"``)
* Functor stores a reference to it, and uses it later
* |longrightarrow| *Attentive programmer jumps up and shouts!*

.. attention::

   Nothing happens though (pity!)

   |longrightarrow| lets dissect this for a moment ...

Lifetime Of Temporary, Made Explicit
------------------------------------

.. sidebar::

   **Documentation**

   * `Lifetime of temporaries (not very comprehensible though)
     <https://en.cppreference.com/w/cpp/language/lifetime>`__

* Replace ``std::string`` with custom class

  * Debug output in ctor and dtor
  * Stores only pointer to ``"howdy"``

.. literalinclude:: ../code/c++11-lambda-capture-handwritten-reference-gosh.cpp
   :caption: :download:`../code/c++11-lambda-capture-handwritten-reference-gosh.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture-handwritten-reference-gosh 
   ctor
   dtor
   howdy

.. danger::

   Obviously ``String`` instance destroyed *before* use!

Lifetime Of Temporary, Made Explicit |longrightarrow| |:ambulance:|
-------------------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

* Modify custom ``String``

  * Allocate and deallocate memory to hold string
  * Talk about :doc:`resource management, object copy, and self
    assignment
    </trainings/material/soup/cxx03/020-data-encapsulation/object-copy>`
    (gosh!)

.. literalinclude:: ../code/c++11-lambda-capture-handwritten-reference-gosh-boom.cpp
   :caption: :download:`../code/c++11-lambda-capture-handwritten-reference-gosh-boom.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture-handwritten-reference-gosh-boom 
   ctor
   dtor
   �
   
.. code-block:: console

   $ valgrind code/c++11-lambda-capture-handwritten-reference-gosh-boom 
   ... hell ...
