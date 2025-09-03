.. include:: <mmlalias.txt>


Afterword, Further Reading
==========================

.. contents::
   :local:

Uses In The Standard Library
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
   * :doc:`/trainings/material/soup/cxx-livehacking/cxx_stl_container_intro/topic`
   
   **Documentation**

   * `Containers library
     <https://en.cppreference.com/w/cpp/container>`__
   * `std::vector
     <https://en.cppreference.com/w/cpp/container/vector>`__
   * `std::map <https://en.cppreference.com/w/cpp/container/map>`__
   * `std::auto_ptr (removed in C++17)
     <https://en.cppreference.com/w/cpp/memory/auto_ptr>`__

* Container classes (e.g. ``std::vector``, ``std::map``, ...)

  * Contain possibly many objects
  * |longrightarrow| copy is expensive
  * |longrightarrow| returning a container object is a cheap move

* Utility classes

  * :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
  * Was not possible in C++ pre 11
  * |longrightarrow| `std::auto_ptr <https://en.cppreference.com/w/cpp/memory/auto_ptr>`__ was the
     closest possible attempt (error prone though)

Other Uses
----------

* Move constructor and move assignment operator are most obvious uses
* |longrightarrow| compiler support when returning locals, for example
* Other uses: move something into a ``std::vector``
* |longrightarrow| alternative overloads for ``push_back()``

.. list-table:: 
   :align: left
   :widths: auto

   * * ``std::vector<>::push_back(const T& elem);``
     * Adds a copy of ``elem``
     * .. code-block:: c++

          String s("Hello");
	  v.push_back(s);                 // <--- copy requested (s is an lvalue)

   * * ``std::vector<>::push_back(T&& elem);``
     * Moves (and thereby invalidates) ``elem``
     * .. code-block:: c++
 
          String s("Hello");
          v.push_back(std::move(s));      // <--- request move, explicitly invalidating s
 
       .. code-block:: c++
           
          v.push_back(String("Hello"));   // <--- temporaries are rvalues -> requesting move

All Said |longrightarrow| Guidelines
------------------------------------

.. sidebar::

   **Links**

   * `C++ Core Guidelines
     <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines>`__

.. list-table::
   :align: left
   :widths: auto

   * * Understand what you are doing
     * Obvious but important
   * * No rvalue references to const type
     * Useless: rvalue references are *there* to be
       modified
   * * No rvalue reference as function return type
     * Useless: compiler does that anyway (that is the entire plan)
   * * Next operation after ``std::move`` is destruction or assignment
     * Don't trust the programmer that she left the object in a valid
       state
   * * Moved-from object must be left in a valid state
     * Respect from you co-workers
   * * Don't ``std::move`` the return of a local variable
     * Useless: compiler does that anyway (that is the entire plan)
   * * Move constructor and assignment operator should be explicitly ``noexcept``
     * Moving resources should not fail (*allocation* does, generally)
   * * Use ``=default`` whenever possible
     * Think twice though if your members' move semantics are what you
       want
   * * Make move-assignment safe for self-assignment
     * Rare but popular source of errors (``s = std::move(s)`` is
       stupid but legal C++)
   * * Either implement all of copy/move/dtor or nothing (*rule of 5/0*)
     * If you implement one, then you probably do resource management
       and you will want all

Further Reading (Well, Videos |:wink:|)
---------------------------------------

* `Back to Basics: Move Semantics - David Olsen - CppCon 2020
  <https://youtu.be/ZG59Bqo7qX4>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/ZG59Bqo7qX4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `The Hidden Secrets of Move Semantics - Nicolai Josuttis - CppCon
  2020 <https://youtu.be/TFMKjL38xAI>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/TFMKjL38xAI" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `CppCon 2017: Nicolai Josuttis “The Nightmare of Move Semantics for
  Trivial Classes” <https://youtu.be/PNRju6_yn3o>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/PNRju6_yn3o" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>
