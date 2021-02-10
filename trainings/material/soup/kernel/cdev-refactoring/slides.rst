.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how to maintain
		 multiple devices (and get rid of global variable)
   :keywords: schulung, training, linux, kernel, module, container_of

Refactoring (Slideshow)
=======================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_refactoring/_morph>`__

What's Bad?
-----------

* Factor ``my_event`` and ``my_event_list`` out into separate file

  * Drawing: module *frontend* has the "event engine" as *backend*
  * split apart, and show how to build a driver from multiple sources

* Factor macros out into ``misc.h`` (and include that in the userspace
  programs)
* ``-Wswitch-enum``

Device?
-------

* Our device is made up of multiple distinct entities

  * ``struct my_event_list``
  * ``struct cdev``
  * ``struct device*``
  * ...

* Move those into ``struct my_device`` methods:

  * ``my_device_init()``
  * ``my_device_destroy()``
  * ``my_device_go_public()``

* Move all these into ``device.{h,c}``

Multiple Devices? (Preparation)
-------------------------------

**Motivation**: PCI and USB drivers can maintain *multiple devices*
(one driver for all devices of the same kind) |longrightarrow| *list*
of devices.

* Convert global *device* variable to a list. Initially having only
  one element.
* That one element is an *object* that is set into the *open file*
  (``struct file``) in ``open()``
* ... accessed by further calls through that structure.

**jjjjj drawing**: 

* how does the cdev come in in open?
* ``container_of()``, link to it.

**jjjjj more**:

* bring in ``cdev`` section from :download:`Kernel
  </trainings/material/pdf/400-kernel.pdf>`
* bring in ``open()`` section from :download:`Kernel
  </trainings/material/pdf/400-kernel.pdf>`
  
