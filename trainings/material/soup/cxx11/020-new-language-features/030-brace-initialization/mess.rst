.. include:: <mmlalias.txt>


Brace Initialization: A Mess
============================

.. contents::
   :local:

Explicit Constructor And Brace Initialization
---------------------------------------------

* Any explicit constructor can be invoked the "new" brace
  initialization syntax
* ... unless there is a ``std::initializer_list`` constructor

.. literalinclude:: code/explicit-ctor.cpp
   :caption: :download:`code/explicit-ctor.cpp`
   :language: c++

Ambiguity: Explicit And ``std::initializer_list`` Constructor
-------------------------------------------------------------

* What if there are two constructors which would satisfy calling sequence?
* |longrightarrow| be explicit

.. literalinclude:: code/ambiguity.cpp
   :caption: :download:`code/ambiguity.cpp`
   :language: c++

Rule
----

* Use brace initialization, preferably
* Unless something does not work or compile |:pig:|

Realistic Example: ``std::vector``: Two ``int`` (Explicit)
----------------------------------------------------------

.. sidebar::

   * `std::vector constructors <https://en.cppreference.com/w/cpp/container/vector/vector>`__

* ``std::vector<int>`` has one explicit constructors which takes two
  ``int`` parameters

  * One is the number of elements to create, one is their value

* Using the explicit constructor, explicitly, by writing gool old
  function-call-style initialization

.. literalinclude:: code/c++11-brace-initialization-vector-explicit.cpp
   :caption: :download:`code/c++11-brace-initialization-vector-explicit.cpp`
   :language: c++

.. code-block:: console

   $ ./code/c++11-brace-initialization-vector-explicit 
   42
   42
   42

Realistic Example: ``std::vector``: Two ``int`` (``std::initializer_list``)
---------------------------------------------------------------------------

.. sidebar::

   * `std::vector constructors <https://en.cppreference.com/w/cpp/container/vector/vector>`__

* ``std::vector<int>`` has one another constructor which takes a
  ``std::initializer_list<int>``
* ... of arbitrary size - even 2 is ok 
* |longrightarrow| must use brace initialization to disabiguate

.. literalinclude:: code/c++11-brace-initialization-vector-initializer-list.cpp
   :caption: :download:`code/c++11-brace-initialization-vector-initializer-list.cpp`
   :language: c++

.. code-block:: console

   $ ./code/c++11-brace-initialization-vector-initializer-list 
   3
   42

Nicolai Josuttis, Complaining About C++
---------------------------------------

* `CppCon 2018: Nicolai Josuttis “The Nightmare of Initialization in C++” <https://youtu.be/7DTlWPgX6zs>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/7DTlWPgX6zs" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `When C++ Style Guides Contradict - Nicolai Josuttis - CppCon 2019 <https://youtu.be/WRQ1xqYBKgc>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/WRQ1xqYBKgc" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>
     </iframe>

