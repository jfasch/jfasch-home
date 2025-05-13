.. include:: <mmlalias.txt>


Exercise: Algorithms
====================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/060-stl/015-vector-copy-etc/topic`
   * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/copy`
   * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find`
   * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`


Copy Into ``std::vector``
-------------------------

* Source C-array is best passed as ``const char**``
* Use ``std::copy`` (:doc:`here
  </trainings/material/soup/cxx03/060-stl/020-algorithm/copy>`)

.. literalinclude:: /trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-copy_into_vector.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-copy_into_vector.cpp`
   :language: c++

Find Element In ``std::vector``
-------------------------------

.. literalinclude:: /trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-find_in_vector.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-find_in_vector.cpp`
   :language: c++

Sort In-Place
-------------

.. literalinclude:: /trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-sort-in-place.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-sort-in-place.cpp`
   :language: c++

Sort Into A Copy
----------------

.. literalinclude:: /trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-sorted.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/stl-exercises/tests/test-algo-sorted.cpp`
   :language: c++

