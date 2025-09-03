.. include:: <mmlalias.txt>


``std::atomic``
===============

.. contents::
   :local:

Atomic Instructions (1)
-----------------------

Simple integers don't need a mutex |longrightarrow| *atomic
instructions*

.. code-block:: c++
   :caption: GCC: atomic built-ins

   static int global;
   void inc() {
     __sync_fetch_and_add(&global, 1);
   }

.. code-block:: c++
   :caption: Windows

   static LONG global;
   void inc() {
     InterlockedIncrement(&global);   
   }

Atomic Instructions (2)
-----------------------

.. code-block:: c++

   #include <atomic>
   std::atomic<int> global(0);
   void inc() {
     global++;
   }
  
* Specializations for all types that are capable

Links
-----

* `CppCon 2017: Fedor Pikus “C++ atomics, from basic to advanced. What
  do they really do?”
  <https://youtu.be/ZQFzMfHIxng?si=bcdnaG5mJxVdKLgz>`__

.. raw:: html

   <iframe width="560" height="315" 
           src="https://www.youtube.com/embed/ZQFzMfHIxng?si=t4lbHMHKhvnGpeE4" 
	   title="YouTube video player" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	   referrerpolicy="strict-origin-when-cross-origin" 
	   allowfullscreen>
   </iframe>
