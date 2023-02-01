.. ot-topic:: linux.sysprog.intro_hw.get
   :dependencies: linux.sysprog.intro_hw.sysfs_gpio

.. include:: <mmlalias.txt>


Get Value Of GPIO
=================

.. contents::
   :local:

Retrieving Value Manually, On The Commandline
---------------------------------------------

* Export GPIO ``26``

  .. code-block:: console

     $ echo 26 > /sys/class/gpio/export 

* Configure as input

  .. code-block:: console

     $ echo in > /sys/class/gpio/gpio26/direction

* Read Value

  .. code-block:: console

     $ cat /sys/class/gpio/gpio26/value

Shell Script
------------

.. sidebar::

   **See also**

   * :doc:`/trainings/repertoire/bash`
   * :download:`/trainings/material/pdf/100-shell-scripting.pdf`

Script usage ...

.. code-block:: console

   $ ./blink-get-sysfs 26
   0

.. literalinclude:: /trainings/material/soup/linux/sysprog/code/blink/shell/blink-get-sysfs
   :caption: :download:`/trainings/material/soup/linux/sysprog/code/blink/shell/blink-get-sysfs`
   :language: shell

C Program
---------

.. literalinclude:: /trainings/material/soup/linux/sysprog/code/blink/sysfs/blink-get-sysfs.cpp
   :caption: :download:`/trainings/material/soup/linux/sysprog/code/blink/sysfs/blink-get-sysfs.cpp`
   :language: c++
