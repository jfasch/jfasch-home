.. include:: <mmlalias.txt>

Coding: Refactoring (Screenplay)
================================

.. contents::
   :local:

Build Module From Multiple Files
--------------------------------

* Factor ``my_event`` and ``my_event_list`` out into separate files,
  ``event.{h,c}``.
* Wonder why loading does not call ``init()``, and why nothing works.
* Kbuild apparently won't accept a source file with the same name as
  the module (see `here
  <https://stackoverflow.com/questions/7490070/missing-component-in-a-kernel-module-with-several-source-files>`__)
* |longrightarrow| rename ``my_driver.c`` to ``main.c``

.. code-block:: Makefile
   :caption: Makefile

   obj-m += my_driver.o
   my_driver-y += main.o event.o

Per-Device Structure
--------------------

* Straightforward: cram all device related stuff into one ``struct
  my_device``
* Leave ``init()`` and ``exit()`` as-is, mostly (except to access
  members of ``my_device`` instead).

Want My Hair Pretty
-------------------

**What's still bad?**

* Style-wise, if we have a struct (``my_device``) that is setup and
  torn down, we want to have dedicated methods.
* Add a *go public* method, for no apparent reason (and come back to
  it later when we add multiple devices).

``Makefile``: ``-Wswitch-enum``
-------------------------------

* Add a number of compiler flags

  .. code-block:: makefile
  
     ccflags-y += -Werror -Wall -Wswitch-enum -Wimplicit

* Add a ``ioctl``, and don't make use of it
* Fix until shuts up
