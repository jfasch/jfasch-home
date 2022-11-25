.. ot-exercise:: cxx_design_patterns.singleton_flexible_strict
   :dependencies: cxx_design_patterns.singleton_inflexible,
		  cxx_design_patterns.singleton_flexible,
		  cxx_design_patterns.singleton,
		  cxx_design_patterns.uml


Exercise: Singleton (Flexible *And* Strict)
===========================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`singleton-inflexible`
   * :doc:`singleton-flexible`

Complications
-------------

In :doc:`singleton-flexible`, we showed a more flexible way to
instantiate the instance at runtime.

Unfortunately, that implementation has the its own shortcomings:

* Overwriting the instance can only result in a runtime error
* Program startup has to be crafted carefully
* Users are now explicitly enabled to instantiate either of the two
  implementation (alas, it's the user who writes startup code)
* All in all: users *see* that there are concrete implementations, and
  *must be told* rules:

  * *Only instantiate concrete implementation at startup*
  * *After startup, only access interface via*
    ``SocialInsurance::instance()``

Quick fix: re-instantiate the requirements from
:doc:`singleton-inflexible`:

* Eliminate the offending ``SocialInsurance::set_instance()`` method.
* Introduce an environment variable ``SOCINSUR`` that is set to either
  ``name()`` of the available implementations (i.e., ``SVS`` or
  ``OEGK``).
* Modify ``SocialInsurance::instance()`` to read the ``SOCINSUR``
  environment variable, and to instantiate the respective inisurance
  implementation.

Reimplement the class hierarchy such that the following program can
run. Take special care:

* Uncomment the commented-out lines and make sure that they emit
  compiler errors.
* There must not be a memory leak at program end.

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/singleton-social-insurance-flexible-strict-main.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/singleton-social-insurance-flexible-strict-main.cpp`
   :language: c++

Tests
-----

* ``SOCINSUR=OEGK``

  .. code-block:: console

     $ SOCINSUR=OEGK ./singleton-social-insurance-flexible-strict-main 
     1037190666 owes "OEGK" 1485.94 Euros

* ``SOCINSUR=SVS``

  .. code-block:: console

     $ SOCINSUR=SVS ./singleton-social-insurance-flexible-strict-main 
     1037190666 owes "SVS" 1634.53 Euros

* ``SOCINSUR`` unset

  .. code-block:: console

     $ ./singleton-social-insurance-flexible-strict-main 
     terminate called after throwing an instance of 'std::runtime_error'
       what():  Environment variable "SOCINSUR" is not set
     Aborted (core dumped)

* ``SOCINSUR`` invalid

  .. code-block:: console

     $ SOCINSUR=xxx ./singleton-social-insurance-flexible-strict-main 
     terminate called after throwing an instance of 'std::runtime_error'
       what():  Environment variable "SOCINSUR" has invalid value
     Aborted (core dumped)

