Embedded Problems? Code Bloat? Type Erasure? Solutions?
=======================================================

.. contents::
   :local:

``virtual`` Is Bad. Is ``virtual`` Bad? (Type Erasure)
------------------------------------------------------

Type erasure appears to be a C++ hype currently. Speakers on C++
conferences beat each others in creating incomprehensible crap that
solves no obvious problem. This is my personal attempt to create
another solution to an unknown problem.

Showing options to eliminate ``virtual``, landing in
:doc:`type-erasure`

.. toctree::
   :maxdepth: 1

   why-replace-virtual
   classic-virtual
   related-no-virtual
   unrelated
   variant-manual-if
   variant-manual-visit
   variant-automatic-visit
   type-erasure

See that livehacked 

.. toctree::
   :maxdepth: 1

   virtual-vs-nonvirtual

Another attempt is that one:

* `Breaking Dependencies: Type Erasure - A Design Analysis - Klaus
  Iglberger - CppCon 2021
  <https://youtu.be/4eeESJQk-mw?si=x5_QWmSDBeepnerX>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/4eeESJQk-mw?si=AjBbIpDFeuvuPGN5" 
  	   title="YouTube video player" 
  	   frameborder="0" 
  	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
  	   allowfullscreen>
     </iframe>

.. note::

   **TODO**

   * Strip down the hacking story to a minimum. It is sufficient to

     * Show that a ``std::vector`` of (smart) pointers to polymorphic
       object is sub-optimal, memory-wise (and cache-performance-wise)
     * Show the final version where a ``std::variant`` holds unrelated
       types, and ``std::visit`` is used for dynamic dispatch.

And CRTP?
.........

Show that CRTP creates *unrelated* types that cannot be held in a
container.

Allocators
----------

.. toctree::
   :maxdepth: 1

   allocator

* Arena allocators

  `Modern C++: C++ Patterns to Make Embedded Programming More
  Productive - Steve Bush - CppCon 2022
  <https://youtu.be/6pXhQ28FVlU?si=RMEFz1OxPSPkyGlP>`__ (44:30)

std::string_view
----------------

* Use as parameters instead of ``std::string``
* Never as member (obviously)

More
----

* `Modern C++: C++ Patterns to Make Embedded Programming More Productive - Steve Bush - CppCon 2022 <https://youtu.be/6pXhQ28FVlU?si=RMEFz1OxPSPkyGlP>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/6pXhQ28FVlU?si=RMEFz1OxPSPkyGlP" 
  	   title="YouTube video player" 
  	   frameborder="0" 
  	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
  	   allowfullscreen>
     </iframe>

* `The Most Important Optimizations to Apply in Your C++ Programs - Jan Bielak - CppCon 2022  <https://youtu.be/qCjEN5XRzHc?si=EJEtQ6Py0O2r7WEG>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/qCjEN5XRzHc?si=EJEtQ6Py0O2r7WEG" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `C++ in Constrained Environments - Bjarne Stroustrup - CppCon 2022  <https://youtu.be/2BuJjaGuInI?si=oECDiESeoJWVWIfl>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/2BuJjaGuInI?si=oECDiESeoJWVWIfl" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Using Modern C++ to Eliminate Virtual Functions - Jonathan Gopel - CppCon 2022  <https://youtu.be/gTNJXVmuRRA?si=2gWfQo4uuBMvVFtP>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/gTNJXVmuRRA?si=2gWfQo4uuBMvVFtP" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
