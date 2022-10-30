.. ot-exercise:: cxx_design_patterns.solutions.singleton_flexible_strict
   :dependencies: cxx_design_patterns.singleton_flexible_strict


Solution: Singleton (Flexible *And* Strict)
===========================================

.. contents::
   :local:

Main Program
------------

.. literalinclude:: ../code/singleton/singleton-social-insurance-flexible-strict-main.cpp
   :caption: :download:`../code/singleton/singleton-social-insurance-flexible-strict-main.cpp`
   :language: c++

``SocialInsurance`` Interface
-----------------------------

.. literalinclude:: ../code/singleton/social-insurance-flexible-strict.h
   :caption: :download:`../code/singleton/social-insurance-flexible-strict.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-flexible-strict.cpp
   :caption: :download:`../code/singleton/social-insurance-flexible-strict.cpp`
   :language: c++

Two Concrete Implementations
----------------------------

OEGK
....

.. literalinclude:: ../code/singleton/social-insurance-oegk-strict.h
   :caption: :download:`../code/singleton/social-insurance-oegk-strict.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-oegk-strict.cpp
   :caption: :download:`../code/singleton/social-insurance-oegk-strict.cpp`
   :language: c++

SVS
...

.. literalinclude:: ../code/singleton/social-insurance-svs-strict.h
   :caption: :download:`../code/singleton/social-insurance-svs-strict.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-svs-strict.cpp
   :caption: :download:`../code/singleton/social-insurance-svs-strict.cpp`
   :language: c++
