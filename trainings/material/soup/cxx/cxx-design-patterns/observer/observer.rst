.. include:: <mmlalias.txt>


Observer
========

.. contents::
   :local:

Exercise
--------

Now that we have implemented several iterations of, for example,
:doc:`../adapter/adapter`, :doc:`/trainings/material/soup/cxx/cxx-exercises/design-patterns/proxy-round`, etc., driven by tests, lets
implement yet another pattern in the same way.

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-one.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-one.cpp`
   :language: c++
 
.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-many.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-many.cpp`
   :language: c++
 
.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-duplicate.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-register-duplicate.cpp`
   :language: c++
 
.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-unregister.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-unregister.cpp`
   :language: c++
 
.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-unregister-not-registered.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-observer/tests/observer-suite-unregister-not-registered.cpp`
   :language: c++
