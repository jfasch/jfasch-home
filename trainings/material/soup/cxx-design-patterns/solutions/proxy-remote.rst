.. ot-exercise:: cxx_design_patterns.solutions.proxy_remote
   :dependencies: cxx_design_patterns.proxy_remote


Solution: Proxy (Remote Thermometer)
====================================

.. contents::
   :local:

Client (Proxy) Thermometer
--------------------------

.. literalinclude:: ../code/library/sensor-remote.h
   :caption: :download:`../code/library/sensor-remote.h`
   :language: c++

.. literalinclude:: ../code/library/sensor-remote.cpp
   :caption: :download:`../code/library/sensor-remote.cpp`
   :language: c++

Remote Stub
-----------

.. literalinclude:: ../code/library/sensor-remote-adapter.h
   :caption: :download:`../code/library/sensor-remote-adapter.h`
   :language: c++

.. literalinclude:: ../code/library/sensor-remote-adapter.cpp
   :caption: :download:`../code/library/sensor-remote-adapter.cpp`
   :language: c++
