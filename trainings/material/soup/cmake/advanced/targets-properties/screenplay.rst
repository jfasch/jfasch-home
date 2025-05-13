.. include:: <mmlalias.txt>


Screenplay: Public And Private Include Directories
==================================================

.. contents::
   :local:

.. sidebar:: Complete source code

   * https://github.com/jfasch/cmake-public-private-src

.. sidebar:: Trainer's note

   * Finally, don't forget to discuss :doc:`global-incdir`

.. sidebar:: Documentation

   * `Transitive Usage Requirements
     <https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#target-usage-requirements>`__

Motivation
----------

.. sidebar:: New files

   * :download:`file-util.h
     </foreign/cmake-public-private-src/toolcase/base/include/private/file-util.h>`
   * :download:`file-util.cpp
     </foreign/cmake-public-private-src/toolcase/base/src/file-util.cpp>`

* ``file-util.h`` and ``file-util.cpp``
* Used only in ``base/``
* |longrightarrow| asymmetry: not all files installed (``file-util.h``
  isn't)
* |longrightarrow| ``file-util.h`` is *visible*
* Modifications

  * ``sensor-w1.cpp``
  * ``sysfs-switch.cpp``

Move Code Around: ``toolcase/base/``
------------------------------------

.. code-block:: console

   $ mkdir -p include/{public,private} src
   $ git mv file-util.h  include/private/
   $ git mv *.h include/public/
   $ git mv *.cpp src/
   $ tree
   .
   ├── CMakeLists.txt
   ├── include
   │   ├── private
   │   │   └── file-util.h
   │   └── public
   │       ├── hysteresis.h
   │       ├── sensor-avg.h
   │       ├── sensor-const.h
   │       ├── sensor.h
   │       ├── sensor-random.h
   │       ├── sensor-w1.h
   │       ├── switch.h
   │       └── sysfs-switch.h
   └── src
       ├── file-util.cpp
       ├── hysteresis.cpp
       ├── sensor-avg.cpp
       ├── sensor-const.cpp
       ├── sensor-random.cpp
       ├── sensor-w1.cpp
       └── sysfs-switch.cpp

Adjust ``CMakeLists.txt``
-------------------------

* Much typing
* |longrightarrow| variables for ``include/public/*.h``,
  ``include/private/*.h``, ``src/*.cpp``
* *Note*: variables are inherited into subdirectories
  (``add_subdirectory()``)

*Won't compile!* |longrightarrow| Fix errors one by one ...

Local Compilation In ``toolcase/base/``
---------------------------------------

* ``include/public`` not seen by local compilation

  .. code-block:: console
  
     .../src/sensor-const.cpp:1:10: fatal error: sensor-const.h: No such file or directory
         1 | #include "sensor-const.h"
           |          ^~~~~~~~~~~~~~~~

  Solution:

  .. code-block:: cmake
  
     target_include_directories(base PRIVATE ./include/public)

* ``include/private`` not seen by local compilation

  .. code-block:: console
  
     .../src/sensor-w1.cpp:3:10: fatal error: file-util.h: No such file or directory
         3 | #include "file-util.h"
           |          ^~~~~~~~~~~~~

  Solution:

  .. code-block:: cmake
  
     target_include_directories(base PRIVATE ./include/private)

Dependent Nodes: ``toolcase/boiling-pot/`` And ``toolcase/data-logger/``
------------------------------------------------------------------------

* ``toolcase/base/include/public/`` not seen from using nodes; e.g.

  .. code-block:: console
  
     .../toolcase/boiling-pot/boiling-pot.h:3:10: fatal error: sensor.h: No such file or directory
         3 | #include "sensor.h"
           |          ^~~~~~~~~~

  Solution: in ``toolcase/base/CMakeLists.txt``, 

  .. code-block:: cmake
  
     target_include_directories(base INTERFACE ./include/public)

Final Note: And ``PUBLIC``?
---------------------------

In ``toolcase/base/CMakeLists.txt``, we have

  .. code-block:: cmake
  
     target_include_directories(base PRIVATE ./include/public)
     target_include_directories(base INTERFACE ./include/public)

That is the same as

  .. code-block:: cmake
  
     target_include_directories(base PUBLIC ./include/public)

Final Final Note: ``include_directories()``
-------------------------------------------

:doc:`global-incdir`
