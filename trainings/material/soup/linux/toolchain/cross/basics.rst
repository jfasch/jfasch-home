.. ot-topic:: linux.toolchain.cross.basics
   :dependencies: linux.toolchain.basics

.. include:: <mmlalias.txt>


Cross Development
=================

.. contents::
   :local:


Native Compilation
------------------

* Compiler runs on a machine, say ``x86_64``
* Produces code *for that machine*
* Uses header files and libraries from that machine
* Default paths for headers and libraries

  * ``/usr/include``: e.g. ``#include <stdio.h>`` is found as
    ``/usr/include/stdio.h``
  * ``/usr/lib``, ``/lib64``, ...: e.g. ``-lpthread`` ("linker, please
    go find me the ``pthread`` library") is resolved to
    ``/lib64/libpthread.so``

Cross?
------

* Compiler runs on *host* machine (e.g. ``x86_64``)
* Produces code for the *target* machine (e.g. ``armv7l``)

**Simple?** |longrightarrow| No

* Code must be built against *target situation*
* Header files and libraries
* |longrightarrow| must be available on *host*

  * |longrightarrow| ``sysroot``

* Must match the target situation |longrightarrow| binary
  compatibility
* Statically linked cross build generally ok
* *But:* shared libraries are a continuous source of pain

**Challenges**

* Cross compiler: finding or building one that works

  * Trial and error, mostly
  * Building one: `crosstool-ng <https://crosstool-ng.github.io/>`__
  * Using a metadistribution like `Yocto
    <https://www.yoctoproject.org/>`__: give you a cross toolchain as
    by-product of creating the *target rootfilesystem*

* ``sysroot``

  * Target root filesystem, in principle
  * Ideally stripped down to a miniumum

    * Don't need target *executables* on the host, for example (they
      won't run)

  * Ideally a by-product of root filesystem creation

The ``sysroot``
---------------

* The situation on the target, made available on the host
* Usually a single tree, containing a subset of the target's *root
  filesystem*

.. code-block:: console
   :caption: One of a number of sysroots; on the *host*

   $ ls -l ~/cross/sysroots/raspberry/
   total 0
   drwxrwxr-x. 1 jfasch jfasch 38 Mar 29 19:00 lib
   drwxrwxr-x. 1 jfasch jfasch 20 Mar 29 18:59 usr

