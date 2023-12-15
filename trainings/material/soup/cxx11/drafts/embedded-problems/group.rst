.. ot-group:: cxx11.embedded_problems


Embedded Problems? Code Bloat? Type Erasure? Solutions?
=======================================================

.. contents::
   :local:

Type Erasure (Was: Eliminating ``virtual``)
-------------------------------------------

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

Allocators
----------

.. toctree::
   :maxdepth: 1

   allocator

Dependencies
------------
	      
.. ot-graph::
   :entries: cxx11.embedded_problems
