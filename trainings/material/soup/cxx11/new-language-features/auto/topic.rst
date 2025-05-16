.. include:: <mmlalias.txt>


Duck Typing (Err, ``auto``) Without A Duck
==========================================

.. contents::
   :local:

.. sidebar:: 

   **Documentation**

   * `Placeholder type specifiers
     <https://en.cppreference.com/w/cpp/language/auto>`__

Motivation
----------
  
.. list-table::
   :align: left

   * * .. code-block:: c++
          :caption: Much ado about nothing ...

          vector<MyType>::iterator 
            iter = v.begin();

       .. code-block:: c++
	  :caption: Compiler knows anyway |longrightarrow|
                    ``iterator``

	  auto iter = v.begin();

       .. code-block:: c++
	  :caption: Compiler knows anyway |longrightarrow|
                    ``const_iterator``

	  auto iter = v.cbegin();

       .. code-block:: c++
	  :caption: Lambdas have no spellable type, intentionally

	  auto func = [](){};

     * * *Type Deduction*
       * Compiler knows anyway
       * He always knew |longrightarrow| lookup of template
         specializations
       * |longrightarrow| Same rules apply

Most Basic Usage
----------------

* No reference (``&``)
* |longrightarrow| all fine, nobody is confused

.. literalinclude:: code/c++11-auto-most-basic.cpp
   :caption: :download:`code/c++11-auto-most-basic.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-most-basic 
   i: 42, &i: 0x7ffcd604846c
   j: 42, &j: 0x7ffcd6048468

``auto`` Is Only The Basic Type
-------------------------------

* Ignores References
* Ignores ``const``

.. literalinclude:: code/c++11-auto-ref-pitfall.cpp
   :caption: :download:`code/c++11-auto-ref-pitfall.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-ref-pitfall 
   i: 42, &i: 0x7ffffefe2b54
   iref: 42, &iref: 0x7ffffefe2b54
   j: 666, &j: 0x7ffffefe2b50

If You Want Reference, Say So!
------------------------------

.. literalinclude:: code/c++11-auto-ref.cpp
   :caption: :download:`code/c++11-auto-ref.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-ref
   i: 666, &i: 0x7ffc59ebd7bc
   iref: 666, &iref: 0x7ffc59ebd7bc
   j: 666, &j: 0x7ffc59ebd7bc

If You Want Const-Reference, Say So!
------------------------------------

.. literalinclude:: code/c++11-auto-const-ref.cpp
   :caption: :download:`code/c++11-auto-const-ref.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-const-ref 
   i: 42, &i: 0x7ffc23e46284
   ciref: 42, &ciref: 0x7ffc23e46284

If You Want Pointer, Say So!
----------------------------

.. literalinclude:: code/c++11-auto-pointer.cpp
   :caption: :download:`code/c++11-auto-pointer.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-pointer 
   i: 666, &i: 0x7ffe4a148064
   pi: 0x7ffe4a148064

And Arrays? Decay To Pointers!
------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`

.. literalinclude:: code/c++11-auto-array.cpp
   :caption: :download:`code/c++11-auto-array.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-auto-array
   array: 0x7ffc528e013c, &array: 0x7ffc528e013c
   p: 0x7ffc528e013c
