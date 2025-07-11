.. include:: <mmlalias.txt>


``const``, And What Compilers Can Do With It
============================================

Facts
-----

* No data race - obviously, because it cannot be modified
* Beware of ``const_cast<>`` though: modifying a variable *after*
  removing ``const`` is **undefined behavior**
* Can be used in ``constexpr`` (but see :doc:`constexpr`)
* *Might* be evaluated at compile time
* *No guarantee though* |longrightarrow| that is the point in
  ``constexpr``

``const`` Variables *Might* Disappear Entirely
----------------------------------------------

.. literalinclude:: code/const-global-variable.cpp
   :language: c++
   :caption: :download:`const-global-variable.cpp
	     <code/const-global-variable.cpp>`

* Optimization off |longrightarrow| ``answer`` in ``rodata``

.. code-block:: console

   $ g++ -O0 const-global-variable.cpp
   $ nm --demangle a.out | grep answer
   0000000000402010 r answer

* ``-O3`` (at least) |longrightarrow| optimized out entirely

.. code-block:: console

   $ g++ -O3 const-global-variable.cpp
   $ nm --demangle a.out | grep answer

``const`` *Might* Generally Disappear: ``std::map<>``?
------------------------------------------------------

.. literalinclude:: code/const-used-in-const-map.cpp
   :language: c++
   :caption: :download:`const-used-in-const-map.cpp
	     <code/const-used-in-const-map.cpp>`

.. code-block:: console

   $ g++ -O3 const-used-in-const-map.cpp
   $ nm --demangle a.out | grep the_map
   00000000004041a0 b the_map

* As of GCC 13.3.1, the map object is not optimized away. 
* It has a non-trivial destructor. But see
  https://en.cppreference.com/w/cpp/language/constexpr, where the
  restriction is valid *until C++20*

``const`` *Might* Generally Disappear: ``std::array<>``?
--------------------------------------------------------

.. sidebar:: See also

   * `Constant expressions / Literal type
     <https://en.cppreference.com/w/cpp/language/constant_expression#Literal_type>`__

``std::array<>`` *has* a trivial destructor, so a compiler *could*
optimize ``const`` objects out.

.. literalinclude:: code/const-used-in-const-array.cpp
   :language: c++
   :caption: :download:`const-used-in-const-array.cpp
	     <code/const-used-in-const-array.cpp>`

* *Does not* disappear by default (GCC 13)

.. code-block:: console

   $ g++ const-used-in-const-array.cpp
   $ nm --demangle a.out | grep the_array
   0000000000402020 r the_array

* *Does* disappear with ``-O3``

.. code-block:: console

   $ g++ -O3 const-used-in-const-array.cpp
   $ nm --demangle a.out | grep the_array
