.. include:: <mmlalias.txt>


Perfect Forwarding
==================

.. contents::
   :local:

Universal References? Forwarding References? **REALLY?**
--------------------------------------------------------

This is a good ol' function that takes an :doc:`rvalue reference
<../020-new-language-features/060-move/group>` (to a
``std::string`` for that matter):

.. code-block:: c++

   void function(std::string&& s) { ... }

This is a *function template*, parameterized with type ``T``, that
takes a *universal reference* - a.k.a. *forwarding reference*:

.. code-block:: c++

   template <typename T>
   void function(T&& param) { ... }

Universal Reference? Binds To *Lvalues*?
----------------------------------------

**RValue references** 

* A *function* taking an *rvalue reference* cannot take an *lvalue*
* Reason: if it did, it could do harm to something the caller might
  still want to use
* See :doc:`../020-new-language-features/060-move/group`

.. literalinclude:: code/c++11-rvalue-reference.cpp
   :caption: :download:`code/c++11-rvalue-reference.cpp`
   :language: c++

.. code-block:: console

   c++11-rvalue-reference.cpp:10:14: error: cannot bind rvalue reference of type ‘std::string&&’ {aka ‘std::__cxx11::basic_string<char>&&’} to lvalue of type ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
      10 |     function(lvalue);
         |              ^~~~~~
   c++11-rvalue-reference.cpp:3:29: note:   initializing argument 1 of ‘void function(std::string&&)’
       3 | void function(std::string&& rvref)
         |               ~~~~~~~~~~~~~~^~~~~

**But:** function templates share the same syntax to mean something
completely different |longrightarrow| **UNIVERSAL REFERENCES**

.. literalinclude:: code/c++11-universal-reference.cpp
   :caption: :download:`code/c++11-universal-reference.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-universal-reference 
   passing lvalue
     accepted
   passing rvalue reference
     accepted

Enter Forwarding
----------------

* Universal references accept many variations (sigh)
* |longrightarrow| how can those be differentiated? *Forwarded* to
  other functions?

.. literalinclude:: code/c++11-universal-reference-forward.cpp
   :caption: :download:`code/c++11-universal-reference-forward.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-universal-reference-forward 
   passing lvalue
     lo_function(const std::string&)
   passing rvalue reference
     lo_function(std::string&&)

Exercise: Dual ``insert()`` Method In :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`
------------------------------------------------------------------------------------------------

Modify the implementation of
:doc:`/trainings/material/soup/cxx11/exercises/bag-shared` to
implement two ``insert()`` methods with *just one* template method:

* ``insert(const std::shared_ptr<Item>&)``
* ``insert(std::shared_ptr<Item>&&)``

Further Information
--------------------

* `Scott Meyers: Adventures in Perfect Forwarding Pt. 1/2 <https://fb.watch/eukOP7RhJy/>`__

  .. raw:: html

     <iframe 
         src="https://www.facebook.com/plugins/video.php?height=313&href=https%3A%2F%2Fwww.facebook.com%2FEngineering%2Fvideos%2F10151094464083109%2F&show_text=false&width=560&t=0" 
	 width="560" height="313" 
	 style="border:none;overflow:hidden" 
	 scrolling="no" 
	 frameborder="0" 
	 allowfullscreen="true" 
	 allow="autoplay; clipboard-write; encrypted-media; picture-in-picture; web-share" 
	 allowFullScreen="true">
     </iframe>

* https://www.grimm-jaud.de/index.php/blog/perfect-forwarding
* https://medium.com/factset/modern-c-in-depth-perfect-forwarding-570f242261f8: very good reading
