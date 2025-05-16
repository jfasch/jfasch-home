.. include:: <mmlalias.txt>


``std::vector`` (And ``std::copy()``)
=====================================

.. contents::
   :local:

.. toctree::
   :hidden:

   vector-basic
   vector-pointer-arith
   vector-and-copy

Basics
------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/new-language-features/brace-initialization/index`

   **Documentation**

   * `std::vector
     <https://en.cppreference.com/w/cpp/container/vector>`__

   * **Live Hacking**

     :doc:`vector-basic`

* C array drawbacks

  * C arrays are fixed-size
  * Once allocated, they cannot change size
  * |longrightarrow| rather unflexible
  * ``std::vector<>`` to the rescue

* ``std::vector``: Commonalities with C arrays

  * Lies in contiguous memory |longrightarrow| efficient CPU cache
    usage
  * Index based access (``a[2]``)
  * Pointer arithmetics via STL *iterators*

* ``std::vector``: Differences from C arrays

  * Can grow dynamically (``push_back()``, ``emplace_back()``, ...)
  * All sorts of manipulation; e.g. inserting and removing elements at
    any position
  * Can also shrink if you tell it to (``shrink_to_fit()``)

Dynamicity Details
------------------

.. sidebar::

   **See also**

   * :doc:`../040-sequential-containers/vector`

STL Iterators: Pointer Arithmetic On A ``std::vector<>``
--------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`C++11 range based for
     </trainings/material/soup/cxx11/new-language-features/range-for/range-based-for>`
   * :doc:`C++11 auto
     </trainings/material/soup/cxx11/new-language-features/auto/topic>`

   **Live Hacking**

   * :doc:`vector-pointer-arith`

* *Index based iteration* is cumbersome/loud
* Remember *the beauty*?

  .. image:: 40-10-00-pointer-begin-end.dia
     :scale: 40%

  .. code-block:: c++

     while (begin != end) *begin++;    // <--- beauty!

* Difference: ``begin`` and ``end`` pointers are STL iterators

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * C array
       * ``std::vector``
     * * .. code-block:: c++

	    int a[] = {100, 200, 300};
	    int *begin = a;
	    int *end = a + 3;
     
       * .. code-block:: c++

	    std::vector<int> a = {100, 200, 300};
	    std::vector<int>::iterator begin = a.begin();
	    std::vector<int>::iterator end = a.end();

	 Much typing |longrightarrow| see :doc:`C++11 auto keyword
	 </trainings/material/soup/cxx11/new-language-features/auto/topic>`

* Alternative to pointer-loops (but not always applicable):
  :doc:`range based for
  </trainings/material/soup/cxx11/new-language-features/range-for/range-based-for>`

Algorithms And Containers : ``std::copy``
-----------------------------------------

.. sidebar::

   **Documentation**

   * `std::copy <https://en.cppreference.com/w/cpp/algorithm/copy>`__
   * `std::back_insert_iterator
     <https://en.cppreference.com/w/cpp/iterator/back_insert_iterator>`__

   **Live Hacking**

   * :doc:`vector-and-copy`

* ``std::vector<>`` is a generalized array
* Why not use ``std::copy()`` on it?
* Copy ``std::vector`` to C array
* Copy C array to ``std::vector``
* Any mixture possible
* *A number of pitfalls though* 
* |longrightarrow| *allocation!* For example ...

  * Preallocate destination vector
  * Use ``std::back_insert_iterator``
