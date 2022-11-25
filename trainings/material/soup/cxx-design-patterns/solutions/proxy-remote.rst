.. ot-exercise:: cxx_design_patterns.solutions.proxy_remote
   :dependencies: cxx_design_patterns.proxy_remote


Solution: Proxy (Remote Thermometer)
====================================

.. contents::
   :local:

Client (Proxy) Thermometer
--------------------------

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote.h
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote.cpp`
   :language: c++

Remote Stub
-----------

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote-adapter.h
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote-adapter.h`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote-adapter.cpp
   :caption: :download:`/trainings/material/soup/cxx-exercises/design-patterns-proxy/sensors/sensor-remote-adapter.cpp`
   :language: c++
