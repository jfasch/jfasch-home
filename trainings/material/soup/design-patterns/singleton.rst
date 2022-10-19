.. ot-topic:: design_patterns.singleton
   :dependencies: design_patterns.interfaces

.. include:: <mmlalias.txt>


Singleton
=========

.. contents::
   :local:

Description
-----------

* Provide single entry point to global variable
* It *is* a global variable
* Only more engineered

**Drawbacks**

* Hidden dependencies
* Instantiation should be automatic
* ... and this is where the problems arise

Simplest: Concrete Class
------------------------

:doc:`exercises/singleton-inflexible`

Deriving From Singleton "Interface" - Explicit Instantiation
------------------------------------------------------------

:doc:`exercises/singleton-flexible`

Hidden Instantiation Via Environment Variable
---------------------------------------------

:doc:`exercises/singleton-flexible-strict`
