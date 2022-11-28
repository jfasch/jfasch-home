.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.constexpr


``constexpr``
=============

.. contents::
   :local:

Basic Usage: Expressions
------------------------

* Requesting ``i`` to be calculated by compiler
* |longrightarrow| Input to calculation has to ``constexpr`` just as
  well

.. literalinclude:: code/basic.cpp
   :caption: :download:`code/basic.cpp`
   :language: c++

* ``const`` is ``constexpr``, clearly

.. literalinclude:: code/basic_const_is_constexpr.cpp
   :caption: :download:`code/basic_const_is_constexpr.cpp`
   :language: c++

``constexpr`` Functions
-----------------------

* Must be able, given only ``constexpr`` inputs, to be evaluated at
  compile time
* |longrightarrow| Can in turn only use ``constexpr`` functions

.. literalinclude:: code/constexpr_function_requested.cpp
   :caption: :download:`code/constexpr_function_requested.cpp`
   :language: c++

* ``constexpr`` function can be used with non-const inputs
* |longrightarrow| not done at compile time
* |longrightarrow| cannot *request* ``constexpr`` calculation

.. literalinclude:: code/constexpr_function_not_requested.cpp
   :caption: :download:`code/constexpr_function_not_requested.cpp`
   :language: c++

Recursive ``constexpr``
-----------------------

.. literalinclude:: code/constexpr_recursive_function.cpp
   :caption: :download:`code/constexpr_recursive_function.cpp`
   :language: c++

``constexpr`` Objects
---------------------

.. literalinclude:: code/constexpr_ctor.cpp
   :caption: :download:`code/constexpr_ctor.cpp`
   :language: c++

Links
-----

* `CppCon 2015: Scott Schurr "constexpr: Applications" <https://www.youtube.com/watch?v=qO-9yiAOQqc>`__

   .. raw:: html

      <iframe 
          width="560" height="315" 
	  src="https://www.youtube.com/embed/qO-9yiAOQqc" 
	  title="YouTube video player" 
	  frameborder="0" 
	  allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	  allowfullscreen>
      </iframe>
