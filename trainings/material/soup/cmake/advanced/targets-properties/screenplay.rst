.. ot-topic:: cmake.advanced.targets_properties_pub_priv_inc
   :dependencies: cmake.advanced.targets_properties
.. include:: <mmlalias.txt>


Screenplay: Public And Private Include Directories
==================================================

.. contents::
   :local:

Motivation
----------

* ``file-util.h`` and ``file-util.cpp``
* Used only in ``base/``
* |longrightarrow| asymmetry: not all files installed (``file-util.h``
  isn't)
* |longrightarrow| ``file-util.h`` is *visible*
* Modifications

  * ``sensor-w1.cpp``
  * ``sysfs-switch.cpp``




$ mkdir include/{public,private}

