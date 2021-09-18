.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.range_based_for
   :dependencies: cxx11.new_language_features.brace_initialization


Range Based ``for`` Loops
=========================

Range Based ``for`` Loops: Motivation (1)
-----------------------------------------

``for`` **looping over containers is very loud ...**

* Iterators are cumbersome
* ... albeit necessary
* ``for_each`` not always applicable
* |longrightarrow| Why not building it into the language itself?

Range Based ``for`` Loops: Motivation (2)
-----------------------------------------

**Iteration, the cumbersome way**

.. code-block:: c++

   vector<int> v{1,2,3};
   for (vector<int>::const_iterator it=v.begin();
        it!=v.end();
        ++it)
     cout << *it << endl;

**This is cumbersome indeed ...**

* ``typedef`` does not exactly help
* Iterators dereferenced by hand
* Much too loud

Range Based ``for`` Loops (1)
-----------------------------

**Solution:** coupling the language with its standard library

.. code-block:: c++

   vector<int> v{1,2,3};
   for (int i: v)
       cout << i << endl;

.. note::

   Almost like Python, isn't it?

Range Based ``for`` Loops (2)
-----------------------------

* Works with the usual ``auto`` incarnations ...
* Valid for all C++ container types, arrays, initializer lists, etc.

.. code-block:: c++
   :caption: ``auto`` Variants

   vector<int> v{1,2,3};
   for (auto& i: v) i = -i;
   for (const auto& i: v) 
       cout << i << endl;
