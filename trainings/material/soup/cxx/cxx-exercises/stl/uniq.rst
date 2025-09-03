.. include:: <mmlalias.txt>


Exercise: Uniquify A Sequence
=============================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `std::set <https://en.cppreference.com/w/cpp/container/set>`__

Transform an input sequence (in the form of a ``std::vector``) into an
output sequence such that

* duplicate elements are removed
* the remaining elements in the output sequence appear in the same
  order as in the input sequence

**Hint:** the data structure that is used to decide if an element has
already occurred would be a ``std::set``. Documentation see `here
<https://en.cppreference.com/w/cpp/container/set>`__

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/stl-exercises/tests/test-uniq.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/stl-exercises/tests/test-uniq.cpp`
   :language: c++
