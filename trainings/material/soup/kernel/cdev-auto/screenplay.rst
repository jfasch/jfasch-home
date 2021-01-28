.. include:: <mmlalias.txt>

Character Devices (Automatic Node Creation) (Screenplay)
========================================================

.. contents::
   :local:

jjj

* ``device_create()`` between ``cdev_init()`` and ``cdev_add()``
  
  * |longrightarrow| chances are that kernel is unhappy with
    uninitialized data.
  * Nobody knows though

* ``device_destroy()``, emphasize on reverse order from ``init()``

* Effect:

  * ``/sys/class/my_class``
  * ``/dev/my_driver-0`` |longrightarrow| *no* manual ``mknod``!
