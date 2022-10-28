.. ot-exercise:: cxx_design_patterns.exercises.observer
   :dependencies: cxx_design_patterns.observer,
		  cxx_design_patterns.uml,
		  cxx_design_patterns.adapter,
		  cxx_design_patterns.proxy_round

Exercise: Observer (``SocialDB``)
=================================

.. contents::
   :local:

Now that we have implemented several iterations of, for example,
:doc:`../adapter/adapter`, :doc:`../proxy/proxy-round`, etc., driven by tests, lets
implement yet another pattern in the same way.

.. literalinclude:: code/tests/observer-suite-register-one.cpp
   :caption: :download:`code/tests/observer-suite-register-one.cpp`
   :language: c++
 
.. literalinclude:: code/tests/observer-suite-register-many.cpp
   :caption: :download:`code/tests/observer-suite-register-many.cpp`
   :language: c++
 
.. literalinclude:: code/tests/observer-suite-register-duplicate.cpp
   :caption: :download:`code/tests/observer-suite-register-duplicate.cpp`
   :language: c++
 
.. literalinclude:: code/tests/observer-suite-unregister.cpp
   :caption: :download:`code/tests/observer-suite-unregister.cpp`
   :language: c++
 
.. literalinclude:: code/tests/observer-suite-unregister-not-registered.cpp
   :caption: :download:`code/tests/observer-suite-unregister-not-registered.cpp`
   :language: c++
