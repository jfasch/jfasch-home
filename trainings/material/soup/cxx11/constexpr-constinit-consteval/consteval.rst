.. include:: <mmlalias.txt>


``consteval``
=============

.. contents::
   :local:

Why?
----

* ``constexpr`` has a "maybe" attached to it
* Evaluation in ``constexpr`` context must be forced (see :ref:`for
  example here <cxx11-constexpr-force-necessary>`)

  .. code-block:: c++

     constexpr int i = f();     // <-- force compiletime evaluation of f

* Something stronger is needed: a function that *always* evaluates at
  compiletime (|longrightarrow| no forcing needed)
* |longrightarrow| ``consteval``
* *Only available at compiletime*
* Same as ``constexpr`` otherwise

Usage: At Compiletime *Only*
----------------------------

* Can *only* be used in ``constexpr`` context
* |longrightarrow| parameters *must be* known at compiletime

.. literalinclude:: code/consteval-add-function.cpp
   :caption: :download:`code/consteval-add-function.cpp`
   :language: c++

* Not ok: mutable parameters

.. literalinclude:: code/consteval-add-function-error.cpp
   :caption: :download:`code/consteval-add-function-error.cpp`
   :language: c++

No Forcing Needed |longrightarrow| Can Assign To Mutable Variables
------------------------------------------------------------------

.. sidebar:: See also

   * :ref:`cxx11-constexpr-uncool`

* Always runs in ``constexpr`` context
* |longrightarrow| no forcing needed
* |longrightarrow| assigned-to variable can be mutable

And ``constexpr``?
------------------

* ``consteval`` function can use ``constexpr`` functions
* Reason: ``consteval`` runs at compiletime *only*, so it uses the
  compiletime version of the called ``constexpr`` functions

.. literalinclude:: code/consteval-constexpr-callchain.cpp
   :caption: :download:`code/consteval-constexpr-callchain.cpp`
   :language: c++
