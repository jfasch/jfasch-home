.. ot-exercise:: cxx_design_patterns.singleton_inflexible
   :dependencies: cxx_design_patterns.singleton,
		  cxx_design_patterns.uml


Exercise: Singleton (Inflexible)
================================

.. contents::
   :local:

Let's say that there is only one social insurance institution for all
people in the world [#unrealistic]_.

Programmatically, *"only one"* is typically expressed with a
*Singleton* instance:

* There can only one instance of the type exist. That instance is
  created invisible to the user, somewhere during program startup.
* The instance is made available to users through a static method
  (usually called ``instance()``).
* Users cannot instantiate its type.
* Users cannot copy/assign objects of its type.

Implement a ``SocialInsurance`` class such that the following program
can run. Take special care:

* Uncomment the commented-out lines and make sure that they emit
  compiler errors.
* There must not be a memory leak at program end.

.. literalinclude:: ../exercises/code/singleton/singleton-social-insurance-inflexible-main.cpp
   :caption: :download:`../exercises/code/singleton/singleton-social-insurance-inflexible-main.cpp`
   :language: c++

When run, the program outputs the following:

.. code-block:: console

   $ ./singleton-social-insurance-inflexible-main
   1037190666 owes "Die einzige Sozialversicherung" 1485.94 Euros


.. rubric:: Footnotes

.. [#unrealistic] While this is unrealistic, let's take this as a
                  placeholder for similar problems.
