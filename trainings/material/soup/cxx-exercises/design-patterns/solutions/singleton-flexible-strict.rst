.. ot-exercise:: cxx.exercises.design_patterns.solutions.singleton_flexible_strict
   :dependencies: cxx.exercises.design_patterns.singleton_flexible_strict


Solution: Singleton (Flexible *And* Strict)
===========================================

.. contents::
   :local:

Main Program
------------

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/singleton-social-insurance-flexible-strict-main.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/singleton-social-insurance-flexible-strict-main.cpp`
   :language: c++

``SocialInsurance`` Interface
-----------------------------

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-flexible-strict.h
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-flexible-strict.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-flexible-strict.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-flexible-strict.cpp`
   :language: c++

Two Concrete Implementations
----------------------------

OEGK
....

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-oegk-strict.h
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-oegk-strict.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-oegk-strict.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-oegk-strict.cpp`
   :language: c++

SVS
...

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-svs-strict.h
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-svs-strict.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-svs-strict.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-singleton/social-insurance-svs-strict.cpp`
   :language: c++
