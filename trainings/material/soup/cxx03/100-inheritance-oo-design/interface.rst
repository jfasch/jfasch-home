.. ot-topic:: cxx03.inheritance_oo.interface
   :dependencies: cxx03.inheritance_oo.virtual_method,
		  cxx03.inheritance_oo.polymorphism,
		  cxx03.inheritance_oo.virtual_destructor

.. include:: <mmlalias.txt>


Interfaces
==========

.. contents:: 
   :local:

Bringing It All Together
------------------------

* C++ has a toolset for 

  * Inheritance
  * Dynamic dispatch

* Does not make any policies
* Java does

  * ``interface``, ``implements``: interfaces (C++: pure virtual) and
    their implementation
  * ``extends``: implementation inheritance (see
    :doc:`private-protected`)

* Programmer's choice how to use tools
* |longrightarrow| very easily incomprehensible code is created
* |longrightarrow| best practices!

Interfaces
----------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`

**Bringing it all together**: an interface is defined like so ...

* Virtual destructor, with an empty implementation (remember,
  destructors cannot be abstract/pure virtual)
* Only abstract/pure virtual methods

.. code-block:: c++

   class Interface
   {
   public:
       virtual ~Interface() {}
       virtual void method() const = 0;
   };
  
* *Ideally* nothing else
* Programmers are invited to break the rules!
* |longrightarrow| Hybrid forms, e.g. providing little helper methods
  in the interface's :doc:`protected interface <private-protected>`
* |longrightarrow| Personal taste, combined with *respect for
  colleagues*

.. note::

   C++11 brings features for derived classes:

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
