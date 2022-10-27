.. ot-topic:: cxx_design_patterns.oo_principles
   :dependencies: cxx_design_patterns.uml,
		  cxx03.inheritance_oo.interface

.. include:: <mmlalias.txt>


OO Design Principles
====================

.. contents::
   :local:

Principles: Why? Which?
-----------------------

* Every handcraft has rules, on every single level, which everybody
  agrees upon
* Our handcraft is no exception
* On the *design level*: **Design Principles**

  * **S**: Single Responsibility
  * **O**: Open/Closed
  * **L**: Liskov Substitution
  * **I**: Interface Segregation
  * **D**: Dependency Inversion

* |longrightarrow| SOLID (for people who find it hard to remember rules)
* **Antipattern**: a pattern that violates any of these principles

Single Responsibility
---------------------

  | **Every class must have responsibility over a single part of the program.**
  |
  |   (Robert C. Martin, at around 2000)


  | **Every class must do one thing and should do that well.**
  |
  |   (Jörg Faschingbauer (Unix addict), all the time)

**Consequences:**

* Understanding is easier
* Documenting is easier
* Defining/writing tests is easier

Open/Closed
-----------

  | **Software entities must be open for extension, but closed for modification.**
  |
  |   (Bertrand Meyer, 1988)

**Interpretations/consequences:**

* Adding functionality not by modifying but by adding (e.g. *plugins*)
* Heavy use of *interfaces*

Liskov Substitution
-------------------

  | **It must be possible in a program to exchange two implementations of**
  | **an interface without compromising the correctness of the program.**
  | 
  |   (Barbara Liskov, 1995)

**Classical violation of Liskow's principle:** square/rectangle

* A rectangle is defined as a pair (width, height), each of which is
  modifiable separately
* Can a square be seen as a rectangle then?

**Consequences:**

* No special cases in user code
* Polished interfaces

Interface Segregation
---------------------

  | **No client of an interface should be forced to depend on methods it does not use.**
  | 
  |   (Robert C. Martin (again), at around 2000)

Dependency Inversion
--------------------

  | * **High-level modules should not depend on low-level modules. Both should depend on abstractions.**
  | * **Abstractions should not depend upon details. Details should depend upon abstractions.**
  |     
  |   (Robert C. Martin (again), at around 2000)
