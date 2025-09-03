.. include:: <mmlalias.txt>


C++ "Interfaces"
================

.. contents:: 
   :local:

Bringing It All Together
------------------------

.. sidebar::

   **See also**

   * :doc:`basics`
   * :doc:`virtual-method`
   * :doc:`pure-virtual`
   * :doc:`destructor`
   
* C++ has a toolset for 

  * Inheritance
  * Dynamic dispatch

* Does not make any policies
* Java does

  * ``interface``, ``implements``: interfaces (C++: pure virtual) and
    their implementation
  
* Programmer's choice how to use tools
* |longrightarrow| very easily incomprehensible code is created
* |longrightarrow| best practices!

Interfaces
----------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/override`
   * :doc:`/trainings/material/soup/cxx/cxx11/oo/default`
   * :doc:`/trainings/material/soup/cxx/cxx11/oo/final`

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
* |longrightarrow| Personal taste, combined with *respect for
  colleagues*

.. note::

   C++11 brings features for derived classes:

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/override`
   * :doc:`/trainings/material/soup/cxx/cxx11/oo/final`
