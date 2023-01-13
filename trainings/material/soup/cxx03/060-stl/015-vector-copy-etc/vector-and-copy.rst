.. include:: <mmlalias.txt>

Screenplay: ``std::vector`` And ``std::copy()``
===============================================

.. contents::
   :local:

``std::vector<>`` Into C Array
------------------------------

.. literalinclude:: code/copy-vector-to-array.cpp
   :language: c++
   :caption: :download:`code/copy-vector-to-array.cpp`

* The code above allocates a C array on the stack, of sufficient size
* |longrightarrow| *this is crucial!*

Copying Into ``std::vector`` (Without Allocation)
-------------------------------------------------

* Remember, ``std::vector<>`` is empty by default
* This code will crash:

.. literalinclude:: code/copy-vector-to-vector-crash.cpp
   :language: c++
   :caption: :download:`code/copy-vector-to-vector-crash.cpp`

Solution 1: Pre-allocate Destination
------------------------------------

* Using ``src.size()``
* Pre-initialization, allocating the destination just as big as needed

.. literalinclude:: code/copy-vector-to-vector-preallocate.cpp
   :language: c++
   :caption: :download:`code/copy-vector-to-vector-preallocate.cpp`

* Using ``.reserve()`` if destination's memory is not known to be
  pre-allocated

.. literalinclude:: code/copy-vector-to-vector-reserve.cpp
   :language: c++
   :caption: :download:`code/copy-vector-to-vector-preallocate.cpp`

Solution 2: ``std::back_insert_iterator``
-----------------------------------------

* Acts as if copied elements were appended with ``.push_back()``

.. literalinclude:: code/copy-vector-to-vector-back-insert-iterator.cpp
   :language: c++
   :caption: :download:`code/copy-vector-to-vector-back-insert-iterator.cpp`
