.. include:: <mmlalias.txt>


Execution Policies (Incomplete Draft)
=====================================

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

Example
-------

.. literalinclude:: code/parallel-algo.cpp
   :caption: :download:`code/parallel-algo.cpp`
   :language: c++
