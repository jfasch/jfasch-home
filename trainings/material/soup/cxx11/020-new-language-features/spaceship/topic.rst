.. include:: <mmlalias.txt>


The Spaceship Operator ``<=>`` (And Comparison In General)
==========================================================

.. contents::
   :local:

Problem: Comparison Operators
-----------------------------

**Each type should either overload ...**

* All 6: ``==``, ``!=``, ``<``, ``>``, ``<=``, ``>=``
* (In)equality: ``==``, ``!=``
* None

**This much writing!**

* Shortcut: only ``<`` for occasional sorted container insertion
* Though containers generally support external ordering
* But: incomplete overloading (e.g. omit ``!=``) is bad code
* With most types, ordering is natural

**Open question remain pre C++20**

* Strong vs. weak ordering? 
* When two objects of a type compare equal, can they be different?
* ...

Annoying: Occasional Container Insertion |longrightarrow| ``operator<()``
-------------------------------------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* Manually define ``operator<()``

.. literalinclude:: code/key-op-less-annoying-less-missing.cpp
   :caption: :download:`code/key-op-less-annoying-less-missing.cpp`
   :language: c++

* |longrightarrow| annoying and error-prone

.. literalinclude:: code/key-op-less-annoying.cpp
   :caption: :download:`code/key-op-less-annoying.cpp`
   :language: c++

.. _cxx_spaceship_all_six:

Annoying: Implementing All Six (``<``, ``>``, ``<=``, ``>=``, ``==``, ``!=``)
-----------------------------------------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* ``operator<()`` is rarely enough
* User expectation: *if objects are less-comparable, they should
  provide the full set*
* |longrightarrow| Implement the other five in terms of ``<``
* |longrightarrow| **Very annoying**

.. literalinclude:: code/key-op-less-all-six-annoying.cpp
   :caption: :download:`code/key-op-less-all-six-annoying.cpp`
   :language: c++

Annoying: Even Simple (In)Equality Comparison
---------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``point.cpp``

* Two-dimensional point
* Expectation: ``==``, ``!=``
* Even that is annoying

.. literalinclude:: code/point-equality-annoying.cpp
   :caption: :download:`code/point-equality-annoying.cpp`
   :language: c++

C++20 To The Rescue: (In)Equality
---------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

**Rationale**

* C++ has always generated memberwise copy-constructor and assignment
  operator
* Why not do something similar with (in)equality ``==`` and ``!=``

**Solution**

* ``==`` implemented, or simply requested ``= default``
* |longrightarrow| ``!=`` comes for free as ``!(a==b)``

.. literalinclude:: code/point-equality-default.cpp
   :caption: :download:`code/point-equality-default.cpp`
   :language: c++

Pythonicity: Comparing Compatible Types
---------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`
   * :ref:`python_oo_operator_overloading_eq_magic`

* Member ``operator==(const compatible_point& cp)`` converts ``cp`` to ``point``
* But not ``this``, as in ``cp == p``
* Pythonic goodie: reverse parameters, and try again. (This is
  Python's ``__eq__()`` method, see :ref:`here
  <python_oo_operator_overloading_eq_magic>`)

.. literalinclude:: code/point-equal-compatible-type.cpp
   :caption: :download:`code/point-equal-compatible-type.cpp`
   :language: c++

Every ``==`` Has Its ``!=``
---------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``
   * Add this to the existing six

* A type may define multiple ``operator==()`` (e.g. to compare with
  unrelated types)
* |longrightarrow| each has their ``operator!=()`` automatically
* ... with the same Pythonic semantics just described (reversing
  parameters until it sees fit)

.. literalinclude:: code/key-equality-comparison-with-unsigned.cpp
   :caption: :download:`code/key-equality-comparison-with-unsigned.cpp`
   :language: c++

Spaceship Operator ``<=>``
--------------------------

* ``a==b`` (e.g.) defines a relationship
* ``a<b`` defines another relationship
* ...
* All definitions should collaborate to implement one bigger
  relationship
* |longrightarrow| *Ordering*
* ``operator<=>()`` return the *entire* relationship
* ``==``, ``!=``, ``<``, ``>``, ``<=``, ``>=`` are then automatically
  derived
* ``strcmp()`` on steroids

Ordering Relationships
----------------------

``operator<=>()`` returns one of the following *ordering* types:

* ``std::strong_ordering``: implies that the values are
  indistinguishable (i.e. if ``a == b``, then ``f(a) == f(b)``).
* ``std::weak_ordering``: allows equal, distinguishable values, but
  doesn't permit uncomparable values.
* ``std::partial_ordering``: allows uncomparable values (i.e. ``a <
  b``, ``a > b`` and ``a == b`` all return false).

To me, ``std::strong_ordering`` seems like the one preferred
relationship to aim for.

Straightforward ``operator<=>()``
---------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* ``unsigned`` implements ``std::strong_ordering``
* |longrightarrow| can be used in ``= default`` spaceship of
  surrounding type

.. literalinclude:: code/key-spaceship-trivial-default.cpp
   :caption: :download:`code/key-spaceship-trivial-default.cpp`
   :language: c++

Compound Datatypes (Handwritten)
--------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``
   * Comment out spaceship, and temporarily resurrect code from
     :ref:`here <cxx_spaceship_all_six>`

* Typical problem: comparable type has multiple members
* |longrightarrow| E.g. composite primary key in databases
* Manual implementation follows: ``primary`` first, then ``secondary``
* (All the five others |longrightarrow| see :ref:`here
  <cxx_spaceship_all_six>`)

.. literalinclude:: code/key-spaceship-compound-handwritten.cpp
   :caption: :download:`code/key-spaceship-compound-handwritten.cpp`
   :language: c++

Compound Datatypes: ``= default`` Spaceship
-------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* ``= default``: applies requested ordering to members, *in
  declaration order*

.. literalinclude:: code/key-spaceship-compound-default.cpp
   :caption: :download:`code/key-spaceship-compound-default.cpp`
   :language: c++

Some Types Have A Weaker Ordering Than ``std::strong_ordering``
---------------------------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* ``double`` only supports ``std::partial_ordering``
* ``NaN`` does not compare well
* ``==`` comparison is not so well defined too
* Many other types too

.. literalinclude:: code/key-spaceship-compound-double.cpp
   :caption: :download:`code/key-spaceship-compound-double.cpp`
   :language: c++

Pointer Members: ``std::strong_ordering``, But Unusable
-------------------------------------------------------

.. sidebar:: Trainer's note

   * Program: ``key.cpp``

* ``secondary`` is ``const char*``
* Has ``std::strong_ordering``, but compares pointer values
* ``= default`` not correct

**Fiasco** (see `P1185R2
<https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1185r2.html#motivation>`__)

* Implement ``<=>``. This does **NOT** create ``==`` (and ``!=``)!
* Implement ``==``

.. literalinclude:: code/key-spaceship-compound-pointer.cpp
   :caption: :download:`code/key-spaceship-compound-pointer.cpp`
   :language: c++

Links
-----

* `CppCon 2019: Jonathan Müller: Using C++20's Three-way Comparison
  <https://youtu.be/8jNXy3K2Wpk?si=1gTPnnTQc4GRlna9>`__

  This is pre-standard, but *really* good. He did not know `P1185R2
  <https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1185r2.html#motivation>`__
  yet, though.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/8jNXy3K2Wpk?si=kfydzWCwXxCA99C2" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `C++ Insights - Episode 12: C++20 The Spaceship Operator (Andreas
  Fertig) <https://youtu.be/DukHRFZ9WAo?si=6I6jwPDqoYf57p2a>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/DukHRFZ9WAo?si=vpwMM5BdI3UuMZIs" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>
