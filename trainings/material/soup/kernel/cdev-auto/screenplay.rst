.. include:: <mmlalias.txt>

Character Devices (Automatic Node Creation) (Screenplay)
========================================================

.. contents::
   :local:

* ``device_create()`` between ``cdev_init()`` and ``cdev_add()``
  
  * |longrightarrow| chances are that kernel is unhappy with
    uninitialized data.
  * Nobody knows though

* ``device_destroy()``, emphasize on reverse order from ``init()``
