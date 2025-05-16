.. include:: <mmlalias.txt>


Modules
=======

.. contents::
   :local:

* ODR by design
* module name: ``export module MODULE-NAME;``
* export ... symbols
* import MODULE-NAME;
* macros defined in a module do not leak to the importer
* macros defined before import do not leak into the imported module
* can be 

  * separated in two files (just like .h and .cpp)

    ``export void foo();`` .mpp

    ``void foo() { return; }``

  * or put in the same file (just like everything inline in .h)

    ``export void foo() { return; }``

* *Module interface unit*

  * Compilation gives (compiler specific) internal representation
  * Much like the venerable "precompiled headers"
  * Large speedup
  * Compiler not anymore needed for traversal
  * Can be done by any script
  * |longrightarrow| tooling
  * |longrightarrow| interfacing with other languages, without having
    to do ``extern "C"`` hacks

Links
-----

* `C++ Modules: Year 2021 (Gabriel Dos Reis)
  <https://youtu.be/YcZntyWpqVQ>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/YcZntyWpqVQ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Practical C++ Modules - Boris Kolpackov - CppCon 2019
  <https://youtu.be/szHV6RdQdg8>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/szHV6RdQdg8" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Implementing C++ Modules: Lessons Learned, Lessons Abandoned - (Old
  Version) <https://youtu.be/9OWGgkuyFV8>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/9OWGgkuyFV8" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

