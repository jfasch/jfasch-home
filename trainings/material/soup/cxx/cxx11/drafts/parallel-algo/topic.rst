.. include:: <mmlalias.txt>


Execution Policies And Parallel Algorithms (Incomplete Draft)
=============================================================

.. contents::
   :local:

.. sidebar:: Documentation

   * `Algorithms library
     <https://en.cppreference.com/w/cpp/algorithm.html>`__
   * `Execution Policies
     <https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t.html>`__

Execution Policies
------------------

* ``std::execution::seq``: sequential execution as if not specified at
  all
* ``std::execution::par``: in parallel, multiple threads. Might fall
  back to ``std::execution::seq`` though.
* ``std::execution::par_unseq``: use vectorization. Might fall back to
  ``std::execution::seq`` though.

And Exceptions?
---------------

* Parallel execution (``std::execution::par`` and
  ``std::execution::par_unseq``) does not like exceptions
* Process is terminated by default (``std::abort()``)
* |longrightarrow| You data should not throw on access

Examples
--------

.. literalinclude:: code/parallel-sort.cpp
   :caption: :download:`code/parallel-sort.cpp`
   :language: c++

.. literalinclude:: code/parallel-foreach.cpp
   :caption: :download:`code/parallel-foreach.cpp`
   :language: c++
