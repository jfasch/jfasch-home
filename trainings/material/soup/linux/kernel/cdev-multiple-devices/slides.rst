.. include:: <mmlalias.txt>

Coding: Multiple Devices (Slideshow)
====================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_multiple_devices/_morph>`__

Instantiate Multiple Devices
----------------------------

#. Add an ``int`` type module parameter, ``ndevices``

   .. code-block:: c

      int ndevices;
      ...
      module_param(ndevices, int, 0);

   Use that to instantiate ``ndevices`` instances of ``struct
   my_device``, and store those in a :doc:`doubly linked list
   <../list/topic>`.

#. In the ``open()`` implementation, use ``(major, minor)`` (stored in
   the ``struct inode`` that gets passed) to find the associated
   ``struct my_device`` in the list.  Store a pointer to it in the
   ``private_data`` member of the ``struct file*`` that is passed to
   ``open()``.

#. Use ``private_data`` in the ``ioctl()`` implementation.
