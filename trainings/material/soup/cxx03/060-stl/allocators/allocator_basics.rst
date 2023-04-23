.. ot-topic:: cxx03.stl.allocator.basics

.. include:: <mmlalias.txt>


Allocator Basics
================

.. contents::
   :local:

.. raw:: html

   <iframe width="560" height="315" 
           src="https://www.youtube.com/embed/0MdSJsCTRkY" 
	   title="YouTube video player" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	   allowfullscreen>
   </iframe>

* allocators are handles to heaps (memory_resource?)
* handle can be copied
* heaps may not
* somebody (screwed standard implementation maybe?) does move a
  heap. standard says that in this case move semantics must do a
  copy. gosh this is crap.
