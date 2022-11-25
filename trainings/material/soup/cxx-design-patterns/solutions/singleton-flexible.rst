.. ot-exercise:: cxx_design_patterns.solutions.singleton_flexible
   :dependencies: cxx_design_patterns.singleton_flexible

Solution: Singleton (Flexible)
==============================

.. contents::
   :local:

Main Program
------------

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/singleton-social-insurance-flexible-main.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/singleton-social-insurance-flexible-main.cpp`
   :language: c++

``SocialInsurance`` Interface
-----------------------------

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-flexible.h
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-flexible.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-flexible.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-flexible.cpp`
   :language: c++

Two Concrete Implementations
----------------------------

OEGK
....

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-oegk.h
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-oegk.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-oegk.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-oegk.cpp`
   :language: c++

SVS
...

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-svs.h
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-svs.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-svs.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-singleton/social-insurance-svs.cpp`
   :language: c++
