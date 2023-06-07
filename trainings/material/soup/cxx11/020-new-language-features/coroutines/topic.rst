.. ot-topic:: cxx11.new_language_features.coroutines

.. include:: <mmlalias.txt>


Coroutines
==========

.. contents::
   :local:

Overview
--------

* blah re-enter/pause/suspend/resume
* ``#include <coroutine>``
* New keywords

  * ``co_yield``
  * ``co_return``
  * ``co_await``

* *"Stackless"* (whatever that means)

Pitfalls
--------

* In a coroutine, don't operate on parameters that are passed by-reference
  
  .. code-block:: c++

     Cycle cycle(const std::vector<int>& elems)
     {
         while (true) {
             for (const auto& e: elems)
                 co_yield e;             // <--- not reached as cycle() is called
         }
     }

  and 

  .. code-block:: c++

     auto c = cycle({1,2,3,4});          // <--- temporary, passed as reference!


Oasch
-----

* 19:00 glue; bidirectional communication in and out of a coroutine
* 32:00 simpler generator
      

* `C++20’s Coroutines for Beginners - Andreas Fertig - CppCon 2022
  <https://youtu.be/8sEe-4tig_A>`__

.. raw:: html

   <iframe width="560" height="315" 
           src="https://www.youtube.com/embed/8sEe-4tig_A" 
	   title="YouTube video player" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	   allowfullscreen>
   </iframe>

Further Topics
--------------

* Ranges 
* and together: https://en.cppreference.com/w/cpp/coroutine/generator
