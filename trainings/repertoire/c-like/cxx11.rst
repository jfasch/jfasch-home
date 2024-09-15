.. meta::
   :description: Modern C++: a new language starting in 2011
   :keywords: schulung, training, programming, c++, c++ 11

An Introduction to Modern C++, In Three Days
============================================

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 3 days
      * * **Language**
	* Trainer language is English or German
      * * **Material**
	* * :doc:`/trainings/material/soup/cxx03/group`
	  * :doc:`/trainings/material/soup/cxx11/group`
	  * :doc:`/trainings/material/soup/cxx/group`
      * * **Related**
	* * :doc:`cxx`
	  * :doc:`design-patterns/design-patterns`
	  * :doc:`../misc/unittests`
      * * **Booking**
	* :doc:`/trainings/booking`


Goal
----

C++, as of its standard revision in 2003, has been the worst language
in the world [#mother-tongue]_. Programmers were forced to write
repetitive, clumsy, and error prone code - programming in it was far
less than enjoyable.

That situation changed completely when the C++11 standard came
out. Writing code is definitely fun again! 

Contents
--------

With many practical exercises and a great deal of trainer live
hacking, this course gives a broad overview of the key language
features.

* **Introductory Live Hacking** A tour through many of the features that
  the new C++ brings.
* **Pythonicity Features** Much of the new language looks like it has
  been greatly influenced by Python.

  * Range based ``for`` loops
  * ``auto``: *duck typing*, only without ducks
  * Structured binding: the *tuple unpacking* in C++

* **Uniform Initialization**

  * User's view
  
    * Real *initialization* of STL containers
    * Many other consequences of the new initialization syntax
    * Not without pitfalls (this is C++)
  
  * Implementor's view

* **New OO Features**

  * ``overrride``
  * ``final``
  * ``= delete``
  * ``= default``

* **Smart Pointers**

  Previously either self hacked (who ever wrote a refcounting pointer
  class?) or via the now-deprecated ``std::auto_ptr<>``, C++ now
  contains two real first-class *managing pointer* implementations.

  * ``std::unique_ptr<>``. Typically frowned upon because of the long
    and incomprehensible compiler errors that bad usage brings, this
    pointer class is definitely worth a look. Based upon the new *move
    semantics*, it defines *compiler-checked ownership transfer*.
  * ``std::shared_ptr<>``. A reference-counting pointer class that is
    easier to use, but more expensive.

* **Moving, RValue References, And Perfect Forwarding**

  Definitely the coolest C++ feature, albeit a bit hard to
  understand. With a great deal of live hacking and exercises, the
  audience *will* understand. 

  In short: ownership transfer and cheap object copy, but not without
  its pitfalls.

* **Functions:** ``std::function<>``, **And Lambda Expressions**

  The second-coolest feature. Lambdas save you tons of writing (its
  capture syntax is a bit hard though), and ``std::function<>`` lets
  you use a polymorphism that is much more lightweight than pure
  OO. Both combined let you write very expressive code. If not
  overused, as always.

* **Multithreading**

  Not cool, but rather dangerous, and everybody does it - so the
  language could not keep out of it any longer. Threads can now be
  started far too easily (in my optinion).

  On the other hand, the language now brings with it many cool
  multithreading tools like

  * Mutexes in varying forms (error checking, recursive, ...),
    together with scoped locking in many forms
  * Oneshot communication primitives like ``std::future<>``,
    ``std::promise<>``
  * A communication swiss army knife, ``std::condition_variable``,
    which allows to build any communiction mechanism you want on top
    of it
  * ``std::atomic<>``, not to forget

* **Miscellaneous**

  * ``constexpr``
  * Strongly typed ``enum``
  * Delegating constructor
  * ``nullptr``
  * ...


.. rubric:: Footnotes
.. [#mother-tongue] It is my mother tongue, though. Tried to unlearn
                    it in favor of :doc:`Python
                    </trainings/material/soup/python/group>`, that did
                    not work.

