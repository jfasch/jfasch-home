.. ot-topic:: cxx_design_patterns.observer
   :dependencies: cxx03.inheritance_oo.interface,
		  cxx_design_patterns.uml

.. include:: <mmlalias.txt>


Observer
========

.. contents::
   :local:

Exercise
--------

Now that we have implemented several iterations of, for example,
:doc:`../adapter/adapter`, :doc:`../proxy/proxy-round`, etc., driven by tests, lets
implement yet another pattern in the same way.

.. literalinclude:: ../code/tests-trainee/observer-suite-register-one.cpp
   :caption: :download:`../code/tests-trainee/observer-suite-register-one.cpp`
   :language: c++
 
.. literalinclude:: ../code/tests-trainee/observer-suite-register-many.cpp
   :caption: :download:`../code/tests-trainee/observer-suite-register-many.cpp`
   :language: c++
 
.. literalinclude:: ../code/tests-trainee/observer-suite-register-duplicate.cpp
   :caption: :download:`../code/tests-trainee/observer-suite-register-duplicate.cpp`
   :language: c++
 
.. literalinclude:: ../code/tests-trainee/observer-suite-unregister.cpp
   :caption: :download:`../code/tests-trainee/observer-suite-unregister.cpp`
   :language: c++
 
.. literalinclude:: ../code/tests-trainee/observer-suite-unregister-not-registered.cpp
   :caption: :download:`../code/tests-trainee/observer-suite-unregister-not-registered.cpp`
   :language: c++
