.. include:: <mmlalias.txt>

File Operations on Character Devices (Screenplay)
=================================================

.. contents::
   :local:

Hooks Necessary
---------------

.. code-block:: console

   # cat /dev/my_driver-0 
   cat: /dev/my_driver-0: Invalid argument

.. code-block:: console

   # strace cat /dev/my_driver-0 
   ...
   openat(AT_FDCWD, "/dev/my_driver-0", O_RDONLY) = 3
   ...
   read(3, 0x7f3d11330000, 131072)         = -1 EINVAL (Invalid argument)
   ...

Implement ``open()``, ``read()``, ``write()``
---------------------------------------------

* Only debug output; no access to device (or any state held by it)
* ``read()`` and ``write()`` initially just like ``/dev/null``

``ioctl()``
-----------

* ``request`` parameter: like protocol identifier
* ignore data for now

**Userspace test program**

* Use ``request = 666`` as ioctl request |longrightarrow|
  *Inappropriate ioctl for device* (``ENOTTY``)
