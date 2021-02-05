.. include:: <mmlalias.txt>

Character Device Basics (Livehacking Screenplay)
================================================

.. contents::
   :local:

Major and Minor Numbers
-----------------------

* ``register_chrdev_region()`` in ``init()``, and
  ``unregister_chrdev_region()`` in ``exit()``

  * Caveat: kernel development just happens. The following methods
    predate the ``cdev`` API; still used by old drivers.

    * *Not* ``register_chrdev()`` - that does ``cdev_add()``
      implicitly
    * *Not* ``unregister_chrdev()`` - that leaves the major number
      registered, at least.

  * Hardcode major and minor numbers to ``(1,1)`` initially
    |longrightarrow| error in logs (``KERN_ERR``)
  * Emphasize on error handling (``return -EINVAL``)
  * Take ``(42,1)``, finally works

    * See how major shows up in ``/proc/devices``


Character Device
----------------

* ``cdev_init()``, ``cdev_add()`` (in ``init()``)
* ``cdev_del()`` (in ``exit()``)
* Empty ``file_operations`` |longrightarrow| later
* Create node ...

    .. code-block:: console
		  
       # mknod my_driver_henkel c 42 0

  * ``cat my_driver_henkel`` |longrightarrow| EINVAL
  * ``strace cat my_driver_henkel`` |longrightarrow| Aha

Source
------

jjj give source
