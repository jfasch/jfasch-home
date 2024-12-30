.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how to maintain
		 multiple devices (and get rid of global variable)
   :keywords: schulung, training, linux, kernel, module, container_of

Coding: Refactoring (Slideshow)
===============================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_refactoring/_morph>`__

What's Bad?
-----------

#. We're putting everything into a single file:

   * ``struct my_event``
   * ``struct my_event_list``

   Factor these out into separate files, ``event.{h,c}``, and *use*
   those from the main driver file, ``my_driver.c``
   [#build_conflict]_.

   By the way, the ``Makefile`` for a ``module.ko`` that is built from
   multiple files looks like so,

   .. code-block:: c

      obj-m += module.o
      module-y += file1.o file2.o file3.o

   .. todo::

      jjj draw a sketch

#. Factor macros out into ``misc.h`` (and include that in the
   userspace programs)
#. Add the warning options ``-Wswitch-enum`` and ``-Werror`` (and
   ``-Wall``) to the compiler commandline. This is done by adding the
   following line to the ``Makefile``,

   .. code-block:: c

      ccflags-y += -Werror -Wall -Wswitch-enum

#. Encapsulate global variables into ``struct my_device``

   We currently only have a single device node, implemented by
   multiple distinct entities which are global variables in the driver
   code,

   * ``struct my_event_list``
   * ``struct cdev``
   * ``struct device*``
   * ...

   Create a separate file pair ``device.{h,c}`` that contains ``struct
   my_device`` to contain these variables, and make an instance of
   that type a single global device instead.

   Lets move the build-up and tear-down code into methods

   * ``my_device_init()``
   * ``my_device_destroy()``

.. rubric:: Footnotes

.. [#build_conflict] Btw, we will have to rename ``my_driver.c`` (to
                     ``main.c`` perhaps) because ``my_driver.ko`` has
                     the same stem. Sadly, Kbuild does not warn us
                     about this conflict.
