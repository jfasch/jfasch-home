.. ot-topic:: cxx03.functions_and_methods.references
   :dependencies: cxx03.functions_and_methods.this

.. include:: <mmlalias.txt>


References
==========

.. contents::
   :local:

Pass By Copy/Reference
----------------------

.. sidebar::

   **Links**

   * `Wikipedia
     <https://en.wikipedia.org/wiki/Evaluation_strategy#Strict_binding_strategies>`__
   * `Pascal
     <https://en.wikipedia.org/wiki/Pascal_(programming_language)>`__

* Computer literature has terminology for different ways of parameter
  passing
* Terms: "Pass by copy", "pass by reference"
* Terms: "input parameter", "output parameter", "input/output
  parameter"
* Pass by copy: callee receives a copy of caller's value
  (|longrightarrow| function cannot modify caller's value)
* Pass by reference: callee receives a reference to caller's value
  (|longrightarrow| callee *can* modify caller's value)

This terminology is language independent (`Pascal <https://en.wikipedia.org/wiki/Pascal_(programming_language)>`__?)

Copy? Reference? C? Pointers!
-----------------------------

* In C, parameters are passed *by copy only*

  .. literalinclude:: code/pass-by-copy.cpp
     :caption: :download:`code/pass-by-copy.cpp`
     :language: c++

* But: there are addresses (pointers) that can be passed (by copy
  |:face_with_raised_eyebrow:|)

  * Voila, done!
  * As long as one can handle those ``&`` and ``*``, everything is ok
  * A little tedious though: take address (``&``), dereference address
    (``*``)
  * |longrightarrow| error prone

  .. literalinclude:: code/pass-by-pointer.cpp
     :caption: :download:`code/pass-by-pointer.cpp`
     :language: c++

C++: True References
--------------------

* C++ adds another meaning to the ``&`` operator: *reference*
* Used in function declaration *only*
* Every use looks like regular variable/parameter access
* Internally addresses are taken, just like pointers - only easier
* Advantage: references cannot (easily) dangle, or be ``NULL``

.. literalinclude:: code/pass-by-reference.cpp
   :caption: :download:`code/pass-by-reference.cpp`
   :language: c++

And ``const``? Pointers?
------------------------

* In C, there is the ``const`` keyword which can be applied to
  pointers too
* Meaning: "this is the address of something that must not be
  modified"

.. literalinclude:: code/pass-by-const-pointer.cpp
   :caption: :download:`code/pass-by-const-pointer.cpp`
   :language: c++

.. code-block:: console

   code/pass-by-const-pointer.cpp:5:8: error: assignment of read-only location ‘* j’
       5 |     *j = 666;              // <--- error: *j is const
         |     ~~~^~~~~

``const`` References
--------------------

.. literalinclude:: code/pass-by-const-reference.cpp
   :caption: :download:`code/pass-by-const-reference.cpp`
   :language: c++

.. code-block:: console

   code/pass-by-const-reference.cpp:5:7: error: assignment of read-only reference ‘j’
       5 |     j = 666;                 // <--- error: j is const
         |     ~~^~~~~

``const`` Reference: Substitute For "Pass by Copy"
--------------------------------------------------

* Pass by copy protects from accidental modification
* Can be expensive though

  .. literalinclude:: code/pass-by-copy-expensive.cpp
     :caption: :download:`code/pass-by-copy-expensive.cpp`
     :language: c++

* ``const`` references to the rescue
* Amount of bytes copied is the size of a pointer, no matter what the
  target type is

  .. literalinclude:: code/pass-by-const-reference-cheap.cpp
     :caption: :download:`code/pass-by-const-reference-cheap.cpp`
     :language: c++

