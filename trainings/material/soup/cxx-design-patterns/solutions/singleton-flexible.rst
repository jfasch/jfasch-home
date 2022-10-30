.. ot-exercise:: cxx_design_patterns.solutions.singleton_flexible
   :dependencies: cxx_design_patterns.singleton_flexible

Solution: Singleton (Flexible)
==============================

.. contents::
   :local:

Main Program
------------

.. literalinclude:: ../code/singleton/singleton-social-insurance-flexible-main.cpp
   :caption: :download:`../code/singleton/singleton-social-insurance-flexible-main.cpp`
   :language: c++

``SocialInsurance`` Interface
-----------------------------

.. literalinclude:: ../code/singleton/social-insurance-flexible.h
   :caption: :download:`../code/singleton/social-insurance-flexible.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-flexible.cpp
   :caption: :download:`../code/singleton/social-insurance-flexible.cpp`
   :language: c++

Two Concrete Implementations
----------------------------

OEGK
....

.. literalinclude:: ../code/singleton/social-insurance-oegk.h
   :caption: :download:`../code/singleton/social-insurance-oegk.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-oegk.cpp
   :caption: :download:`../code/singleton/social-insurance-oegk.cpp`
   :language: c++

SVS
...

.. literalinclude:: ../code/singleton/social-insurance-svs.h
   :caption: :download:`../code/singleton/social-insurance-svs.h`
   :language: c++

.. literalinclude:: ../code/singleton/social-insurance-svs.cpp
   :caption: :download:`../code/singleton/social-insurance-svs.cpp`
   :language: c++
