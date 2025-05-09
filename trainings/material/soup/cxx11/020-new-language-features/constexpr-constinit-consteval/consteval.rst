.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.const_expr_init_eval.consteval
   :dependencies: cxx11.new_language_features.const_expr_init_eval.constexpr


``consteval``
=============

.. contents::
   :local:

Why?
----

* ``constexpr`` has a "maybe" attached to it
* Evaluation in ``constexpr`` context can be forced

  .. code-block:: c++

     constexpr int i = f();     // <-- force compiletime evaluation of f

* Something stronger is needed: a function that *always* evaluates at
  compiletime
* |longrightarrow| ``consteval``
* Only allowed in function (and function template) declarations

Usage: At Compiletime *Only*
----------------------------

* Can *only* be used with parameters that are known at compiletime

.. literalinclude:: code/consteval-function-ok.cpp
   :caption: :download:`code/consteval-function-ok.cpp`
   :language: c++

* Not ok: mutable parameters

.. literalinclude:: code/consteval-function-error.cpp
   :caption: :download:`code/consteval-function-error.cpp`
   :language: c++

And ``constexpr``?
------------------

* ``consteval`` function can use ``constexpr`` functions
* Reason: ``consteval`` runs at compiletime *only*, so it uses the
  compiletime version of the called ``constexpr`` functions

.. literalinclude:: code/consteval-function-uses-constexpr-function.cpp
   :caption: :download:`code/consteval-function-uses-constexpr-function.cpp`
   :language: c++
