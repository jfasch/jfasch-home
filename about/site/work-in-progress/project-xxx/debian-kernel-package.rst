.. ot-task:: project_xxx.debian_kernel_package
   :dependencies: project_xxx.audio_chip, project_xxx.dirty_upgrade,
                  project_xxx.hardware_bringup
   :initial-estimate: 24
   :percent-done: 0

Finish: Debian Kernel Package etc.
==================================

.. contents::
   :local:

Goal
----

When all is done, packaging is in order. Delivery of a Debian Kernel
package is not appropriate for some reasons, so a different delivery
mechanism has to be found. Possibilities are,

* A simple ``.tar`` file
* A Git repository of some sort
