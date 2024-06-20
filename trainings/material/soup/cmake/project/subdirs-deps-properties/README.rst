Exercise: Straightforward Build
===============================

.. contents::
   :local:

Structure
---------

.. code-block:: console

    .
    ├── README.rst
    ├── firmware                          # <--- executables (need all the others)
    │   ├── boiling-pot.cpp
    │   └── data-logger.cpp
    └── toolcase                          # <--- descend into base, pot, logger
        ├── base                          # <--- base library
        │   ├── hysteresis.cpp
        │   ├── hysteresis.h
        │   ├── sensor-avg.cpp
        │   ├── sensor-avg.h
        │   ├── sensor-const.cpp
        │   ├── sensor-const.h
        │   ├── sensor-mock.cpp
        │   ├── sensor-mock.h
        │   ├── sensor-random.cpp
        │   ├── sensor-random.h
        │   ├── sensor-w1.h
        │   ├── sensor.h
        │   ├── switch-mock.cpp
        │   ├── switch-mock.h
        │   ├── switch.h
        │   ├── sysfs-switch.cpp
        │   └── sysfs-switch.h
        ├── boiling-pot                   # <--- boiling-pot library
        │   ├── boiling-pot.cpp
        │   └── boiling-pot.h
        └── data-logger                   # <--- data logger library
            ├── data-logger.cpp
            ├── data-logger.h
            ├── sensor-config.h
            ├── sensor-values.h
            ├── sink-file.h
            ├── sink-logger.h
            ├── sink-mock.h
            └── sink-terminal.h
    
Generate Makefile Build
-----------------------

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/2024-06-18-exercise-x86_64
   $ cmake -DCMAKE_INSTALL_PREFIX=/home/jfasch/My-Installs/2024-06-18-exercise-x86_64 ~/My-Projects/2024-06-18/exercise/
   ... roedel ...

Build It
--------

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/2024-06-18-exercise-x86_64
   $ make
   ... roedel ...

Install It
----------

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/2024-06-18-exercise-x86_64
   $ make install
   ...
   -- Installing: /home/jfasch/My-Installs/2024-06-18-exercise-x86_64/bin/app-boiling-pot
   ... roedel ...

Build Shared Libraries
----------------------

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/2024-06-18-exercise-x86_64
   $ cmake -DBUILD_SHARED_LIBS=1 -DCMAKE_INSTALL_PREFIX=/home/jfasch/My-Installs/2024-06-18-exercise-x86_64 ~/My-Projects/2024-06-18/exercise/
   ... roedel ...

* ``make && make install``, etc. as usual

