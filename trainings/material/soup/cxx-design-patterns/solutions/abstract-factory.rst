.. ot-topic:: cxx_design_patterns.solutions.abstract_factory
   :dependencies: cxx_design_patterns.abstract_factory

.. include:: <mmlalias.txt>


Solution: Abstract Factory
==========================

.. contents::
   :local:

``I2CSensorFactory`` Abstract Factory
-------------------------------------

.. literalinclude:: ../code/libtrainee/sensor-i2c-factory.h
   :caption: :download:`../code/libtrainee/sensor-i2c-factory.h`
   :language: c++

Concrete Factory Implementations
--------------------------------

``I2CSensorFactory_Vendor1``
............................

.. literalinclude:: ../code/libtrainee/sensor-i2c-factory-vendor1.h
   :caption: :download:`../code/libtrainee/sensor-i2c-factory-vendor1.h`
   :language: c++

.. literalinclude:: ../code/libtrainee/sensor-i2c-factory-vendor1.cpp
   :caption: :download:`../code/libtrainee/sensor-i2c-factory-vendor1.cpp`
   :language: c++

``I2CSensorFactory_Vendor1``
............................

.. literalinclude:: ../code/libtrainee/sensor-i2c-factory-vendor2.h
   :caption: :download:`../code/libtrainee/sensor-i2c-factory-vendor2.h`
   :language: c++

.. literalinclude:: ../code/libtrainee/sensor-i2c-factory-vendor2.cpp
   :caption: :download:`../code/libtrainee/sensor-i2c-factory-vendor2.cpp`
   :language: c++
