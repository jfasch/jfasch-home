.. ot-topic:: cxx11.new_language_features.ranges.intro

.. include:: <mmlalias.txt>


Ranges: An Overview
===================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `ranges (cppreference.com)
     <https://en.cppreference.com/w/cpp/ranges>`__

Ranges?
-------

* *Range*: abstraction of "something that contains elements"
* Inevitably a range must have ``begin()`` and ``end()`` iterators
  |longrightarrow| *Range-based-for*
* Most standard algorithms come with a *range* variant
* Less error prone
* More comfortable

Containers And Views (Storage Behavior)
---------------------------------------

* *Containers* are ranges that *own* their elements
* *Views* do not *own* data

  * Refer to another range to draw elements from
  * Transformation done *lazily* during iteration/dereferencing

Examples
--------

* Dropping first two elements of a sequence, and printing the rest
* |longrightarrow| *no copy*

.. literalinclude:: intro/drop-procedural.cpp
   :language: c++
   :caption: :download:`Download drop-procedural.cpp
             <intro/drop-procedural.cpp>`

* Dropping first two, taking next two

.. literalinclude:: intro/drop-take-procedural.cpp
   :language: c++
   :caption: :download:`Download drop-take-procedural.cpp
             <intro/drop-take-procedural.cpp>`

Pipe Syntax
-----------

* Syntactic sugar
* Extremely readable
* Example: dropping first two, taking next two

.. literalinclude:: intro/drop-take-pipe.cpp
   :language: c++
   :caption: :download:`Download drop-take-pipe.cpp
             <intro/drop-take-pipe.cpp>`

Dangling Iterator Protection
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`

* A *range* is one object describing a ... well ... a range of
  elements
* Traditionally (pre-20), described by a pair of *iterators* ``[begin,
  end)``

  .. literalinclude:: intro/dangling-protection-1.cpp
     :language: c++
     :caption: :download:`Download dangling-protection-1.cpp
               <intro/dangling-protection-1.cpp>`

* *Ranges* do the same, using one object of range (or view) type

  .. literalinclude:: intro/dangling-protection-2.cpp
     :language: c++
     :caption: :download:`Download dangling-protection-2.cpp
               <intro/dangling-protection-2.cpp>`

* |longrightarrow| much more possibilities

*For example ...* 

* Passing temporaries adds to readability
* ... but often also to bugginess

  .. literalinclude:: intro/dangling-protection-3.cpp
     :language: c++
     :caption: :download:`Download dangling-protection-3.cpp
               <intro/dangling-protection-3.cpp>`

* ``std::ranges::dangling`` when passing an :doc:`RValue
  </trainings/material/soup/cxx11/020-new-language-features/060-move/overview>`
* |longrightarrow| *compiler error*

Range Views, And Piping 
-----------------------

.. https://youtu.be/sZy9XcGHmI4 (Jason Turner)

.. sidebar::

   **Documentation**

   * `std::ranges::views::drop
     <https://en.cppreference.com/w/cpp/ranges/drop_view>`__

* 

  .. literalinclude:: intro/view-procedural.cpp
     :language: c++
     :caption: :download:`Download view-procedural.cpp
               <intro/view-procedural.cpp>`



jjj
---

https://youtu.be/L0bhZp6HMDM 25:00



Links
-----

* ` C++20 Ranges in Practice - Tristan Brindle - CppNorth 2022
  <https://youtu.be/L0bhZp6HMDM>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/L0bhZp6HMDM" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
