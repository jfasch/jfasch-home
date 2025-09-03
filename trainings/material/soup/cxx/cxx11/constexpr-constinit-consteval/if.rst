.. include:: <mmlalias.txt>


``if constexpr``: Metaprogramming Made Easy
===========================================

Problem
-------

.. sidebar:: Documentation

   * `constexpr if <https://en.cppreference.com/w/cpp/language/if>`__

* ``is_even()`` evaluation in ``constexpr`` context is only guaranteed
  when assigning to a ``constexpr`` variable
* How to use in ``if``?

.. literalinclude:: code/constexpr-if-problem.cpp
   :caption: :download:`code/constexpr-if-problem.cpp`
   :language: c++

* This is clumsy
* Still no guarantee because compilers are not *required* to treat
  constant conditions specially

Solution
--------

.. literalinclude:: code/constexpr-if-solution.cpp
   :caption: :download:`code/constexpr-if-solution.cpp`
   :language: c++
