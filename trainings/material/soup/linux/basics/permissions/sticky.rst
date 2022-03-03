.. ot-topic:: linux.basics.permissions.sticky
   :dependencies: linux.basics.permissions.basics

.. include:: <mmlalias.txt>


Ugly Hack: Sticky Bit
=====================

.. contents::
   :local:

Sticky Bit
----------

**Sticky bit: motivation**

* *Ugly hack!*
* Everyone has write permissions in ``/tmp``

  * |longrightarrow| everyone can create files
  * |longrightarrow| everyone can remove files

* Chaos: everyone can remove each other's files

.. code-block:: console

   $ ls -ld /tmp
   drwxrwxrwt ... /tmp

