.. include:: <mmlalias.txt>

Character Device Basics (Livehacking Screenplay)
================================================

.. contents::
   :local:

Major and Minor Numbers
-----------------------

In the ``init()`` method ...

* Hardcode major and minor numbers to ``(1,1)`` initially
  |longrightarrow| error in logs (``KERN_ERR``)
* Emphasize on error handling (``return -EINVAL``)
* ``register_chrdev_region()``. *Not* ``register_chrdev()``, that does
  ``cdev_add()`` implicitly |longrightarrow| kernel development just
  happens.
* ``unregister_chrdev_region()``. *Not* ``unregister_chrdev()`` - that
  leaves the major number registered, at least. Predates ``cdev`` API;
  still used by old drivers.

Character Device
----------------

* Empty ``ops``, no oops (no methods too, though)
* ``(42,1)`` succeeds

  * See how major shows up in ``/proc/devices``
  * Create node ...

    .. code-block:: console
		  
       # mknod my_driver_henkel c 42 0

  * cat/open() -> EINVAL

Source
------

jjj give source
