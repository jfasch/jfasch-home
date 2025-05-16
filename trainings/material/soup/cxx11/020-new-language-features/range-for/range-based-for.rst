.. include:: <mmlalias.txt>


Range Based ``for`` Loops: Introduction
=======================================

.. contents::
   :local:

Motivation
----------

``for`` **looping over containers is very loud ...**

* Iterators are cumbersome
* ... albeit necessary
* ``for_each`` not always applicable
* |longrightarrow| Why not building it into the language itself?

**Iteration, the cumbersome way**

.. code-block:: c++

   std::vector<int> v{1,2,3};
   for (std::vector<int>::const_iterator it=v.begin();
        it!=v.end();
        ++it)
     std::cout << *it << std::endl;

**This is cumbersome indeed ...**

* ``typedef`` does not exactly help
* Iterators dereferenced by hand
* |longrightarrow| Much too loud!

Enter Range Based ``for`` Loops
-------------------------------

**Solution:** coupling the language with its standard library

.. code-block:: c++

   std::vector<int> v{1,2,3};
   for (int i: v)
       std::cout << i << std::endl;

.. note::

   Almost like Python, isn't it?

Range Based ``for`` Loops, And ``auto``
---------------------------------------

.. sidebar::

   **See also**

   * :doc:`../auto`

* Works with the usual ``auto`` incarnations ...
* Valid for all C++ container types, arrays, initializer lists, etc.

.. code-block:: c++
   :caption: ``auto`` Variants

   std::vector<int> v{1,2,3};
   for (auto& i: v) i = -i;
   for (const auto& i: v) 
       std::cout << i << std::endl;

Case Study: ``std::map`` Iteration
----------------------------------

See :doc:`range-based-for-map`
