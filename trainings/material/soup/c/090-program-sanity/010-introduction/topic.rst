.. include:: <mmlalias.txt>

.. jf-topic:: c.program_sanity.introduction
   :dependencies: c.advanced_language_features.alignment


Sanity and Readabilty
=====================

Shooting Offense: Unobvious Solution
------------------------------------

.. image:: 91-01-00-sanity-electrical.jpg

Shooting Offense: Unobvious Problem
-----------------------------------

.. image:: 91-01-00-sanity-gsellmanns-weltmaschine.jpg

Shooting Offenses
-----------------

**We are all mature programmers**, and we all know that some oddities
are best rectified by firing the programmer

* Unexpected side effects
* Wrong documentation (none is far better)
* Nested loops to a depth of 10

  * With loop variables taken from somewhere in the middle of the
    alphabet (Fortran?)

* Obvious lazyness
* Obvious lack of respect for colleagues

Ambiguity
---------

**Ambiguity** is the root of all evil. Imagine ...

* You have to take over maintenance of a large piece of code
* |longrightarrow| you have to understand it
* You cannot guess from its name what a function does
* Same with variables
* Same with parameters
* Return values have no obvious meaning
* There are comments all over, obviously meant to overcome those shortcomings
* Comments are mostly out-of-sync with the code

|longrightarrow| *This will drive you mad!*

* (... especially if it's your own code)*

Readability
-----------

**Simple recipe for writing good code**: you are able to understand
what you did, even after three weeks of holiday/beer

* Chances are others will understand the code too
* Requires some discipline
* |longrightarrow| Handcraft?

Code Smells
-----------

**Code smells** for the following reasons

* Comments that explain how the code works
* Long parameter lists
* Long nested ``if``/``else`` chains
* Hungarian notation
* ... and many more

We won't elaborate on that - this is not a programming course

Following a series of easy techniques to make C code readable/correct

**Good reading**: `here <http://blog.codinghorror.com/code-smells/>`__

