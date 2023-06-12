.. ot-topic:: cxx11.new_language_features.ranges.intro

.. include:: <mmlalias.txt>


Ranges: Overview
================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `Ranges
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

Views As Parameters: Good Old Template
--------------------------------------

.. sidebar::

   **Documentation**

   * `(Abbreviated) function templates
     <https://en.cppreference.com/w/cpp/language/function_template>`__

   **See also**

   * :doc:`../concepts/group`

   **Trainer's Note**

   * Start with ``intro/print-oldstyle.cpp``, and morph

* As an old-style template

  .. literalinclude:: intro/print-oldstyle.cpp
     :language: c++
     :caption: :download:`Download print-oldstyle.cpp
               <intro/print-oldstyle.cpp>`

Views As Parameters: Abbreviated Function Template
--------------------------------------------------

* `Abbreviated function templates
  <https://en.cppreference.com/w/cpp/language/function_template>`__.

This is new in C++20. The feature is inspired by generic lambda (new
in C++14, and refined from then on; see `here
<https://en.cppreference.com/w/cpp/language/lambda>`__).

.. literalinclude:: intro/print-auto-template.cpp
   :language: c++
   :caption: :download:`Download print-auto-template.cpp
             <intro/print-auto-template.cpp>`

Views As Parameters: Concepts
-----------------------------

* Abbreviated function templates are best combined with :doc:`concepts
  <../concepts/group>`
* |longrightarrow| Better compiler errors

.. literalinclude:: intro/print-concept.cpp
   :language: c++
   :caption: :download:`Download print-concept.cpp
             <intro/print-concept.cpp>`

Available ``<ranges>`` Concepts
-------------------------------

.. list-table::
   :widths: auto
   :header-rows: 1

   * * Concept name
     * Description
   * * ``std::ranges::input_range``
     * Can be iterated from beginning to end at least once
   * * ``std::ranges::forward_range``
     * Can be iterated from beginning to end multiple times
   * * ``std::ranges::bidirectional_range``
     * Iterator can also move backwards with ``operator--()``
   * * ``std::ranges::random_access_range``
     * You can jump to elements in constant-time with ``operator[]()``
   * * ``std::ranges::contiguous_range``
     * Elements are always stored consecutively in memory
