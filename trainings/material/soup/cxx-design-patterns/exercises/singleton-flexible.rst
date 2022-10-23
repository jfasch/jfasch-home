.. ot-exercise:: cxx_design_patterns.exercises.singleton_flexible
   :dependencies: cxx_design_patterns.exercises.singleton_inflexible,
		  cxx_design_patterns.singleton,
		  cxx_design_patterns.uml


Exercise: Singleton (Flexible)
==============================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`singleton-inflexible`

In certain scenarios, it might be advisable to be more flexible. In
our hypothetic *single social insurance* world, this could for example
mean that we might want to exchange the implementation of *the*
insurance with one that adds a fee of 10% to every charge.

Modify your solution to :doc:`singleton-inflexible`:

* Create a social insurance interface ``SocialInsurance``
* Create a ``SVS`` implementation of that interface. That particular
  implementation is the one that adds a 10% fee.
* Create an ``OEGK`` implementation that does not add a fee.

Add the following program to your build system. The program uses the
two implementations.

.. literalinclude:: code/singleton/singleton-social-insurance-flexible-main.cpp
   :caption: :download:`code/singleton/singleton-social-insurance-flexible-main.cpp`
   :language: c++

When run, the program outputs the following (and crashes):

.. code-block:: console

   $ ./singleton-social-insurance-flexible-main 
   1037190666 owes "SVS" 1634.53 Euros
   terminate called after throwing an instance of 'std::runtime_error'
     what():  SocialInsurance singleton already in place
   Aborted (core dumped)
