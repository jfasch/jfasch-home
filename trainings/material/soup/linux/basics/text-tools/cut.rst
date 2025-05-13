.. include:: <mmlalias.txt>


``cut``
=======

.. contents::
   :local:


``cut``
-------

.. sidebar::

   **Documentation**

   * `man -s 1 cut
     <https://man7.org/linux/man-pages/man1/cut.1.html>`__

* All groups in the system

  .. code-block:: console

     $ cut -d : -f 1 /etc/group
     root
     bin
     daemon
     sys
     adm
     tty
     disk
     ...

* All groups in the system, together with their IDs

  .. code-block:: console

     $ cut -d : -f 1,3 --output-delimiter ' ' /etc/group|head
     root 0
     bin 1
     daemon 2
     sys 3
     adm 4
     tty 5
     disk 6
     ...
