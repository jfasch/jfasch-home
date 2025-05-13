.. include:: <mmlalias.txt>


``head`` And ``tail``
=====================

.. contents::
   :local:

``head``
--------

.. sidebar::

   **Documentation**

   * `man -s 1 head
     <https://man7.org/linux/man-pages/man1/head.1.html>`__

* By default, write first ten lines to ``stdout``

  .. code-block:: console

     $ head /etc/passwd
     root:x:0:0:root:/root:/bin/bash
     bin:x:1:1:bin:/bin:/sbin/nologin
     daemon:x:2:2:daemon:/sbin:/sbin/nologin
     adm:x:3:4:adm:/var/adm:/sbin/nologin
     lp:x:4:7:lp:/var/spool/lpd:/sbin/nologin
     sync:x:5:0:sync:/sbin:/bin/sync
     shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
     halt:x:7:0:halt:/sbin:/sbin/halt
     mail:x:8:12:mail:/var/spool/mail:/sbin/nologin
     operator:x:11:0:operator:/root:/sbin/nologin

* First ``N`` lines: ``-n N``, ``--lines N``

  .. code-block:: console

     $ head -n 3 /etc/passwd
     root:x:0:0:root:/root:/bin/bash
     bin:x:1:1:bin:/bin:/sbin/nologin
     daemon:x:2:2:daemon:/sbin:/sbin/nologin
  
* All but the last ``N`` lines: ``-n -N`` (negative *number*)

  .. code-block:: console

     $ head -n -43 /etc/passwd
     root:x:0:0:root:/root:/bin/bash
     bin:x:1:1:bin:/bin:/sbin/nologin
     daemon:x:2:2:daemon:/sbin:/sbin/nologin
     adm:x:3:4:adm:/var/adm:/sbin/nologin

* First ``N`` bytes: ``-c N`` (also with negative ``N``, as with
  ``-n``)

  .. code-block:: console

     $ head -c 3 /etc/passwd
     roo$

``tail``
--------

.. sidebar::

   **Documentation**

   * `man -s 1 tail
     <https://man7.org/linux/man-pages/man1/tail.1.html>`__

* By default, write last ten lines to ``stdout``

  .. code-block:: console

     $ tail /etc/passwd
     abrt:x:173:173::/etc/abrt:/sbin/nologin
     flatpak:x:986:983:User for flatpak system helper:/:/sbin/nologin
     gdm:x:42:42:GNOME Display Manager:/var/lib/gdm:/sbin/nologin
     gnome-initial-setup:x:985:982::/run/gnome-initial-setup/:/sbin/nologin
     vboxadd:x:984:1::/var/run/vboxadd:/sbin/nologin
     sshd:x:74:74:Privilege-separated SSH:/usr/share/empty.sshd:/sbin/nologin
     tcpdump:x:72:72::/:/sbin/nologin
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash
     systemd-coredump:x:978:978:systemd Core Dumper:/:/usr/sbin/nologin
     systemd-timesync:x:977:977:systemd Time Synchronization:/:/usr/sbin/nologin

* Write all but first ``N`` lines: ``-n +N``, ``--lines +N``

  .. code-block:: console

     $ tail -n +43 /etc/passwd
     sshd:x:74:74:Privilege-separated SSH:/usr/share/empty.sshd:/sbin/nologin
     tcpdump:x:72:72::/:/sbin/nologin
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash
     systemd-coredump:x:978:978:systemd Core Dumper:/:/usr/sbin/nologin
     systemd-timesync:x:977:977:systemd Time Synchronization:/:/usr/sbin/nologin

``head`` And ``tail`` In The Pipe
---------------------------------

* Lines 8-10 to ``stdout`` 

  .. code-block:: console

     $ head -n 10 /etc/passwd|tail -n 3
     halt:x:7:0:halt:/sbin:/sbin/halt
     mail:x:8:12:mail:/var/spool/mail:/sbin/nologin
     operator:x:11:0:operator:/root:/sbin/nologin

  Or, less efficient (thereby winning the `Useless Use Of Cat Award
  <https://porkmail.org/era/unix/award>`__),

  .. code-block:: console

     $ cat /etc/passwd|head -n 10|tail -n 3
     halt:x:7:0:halt:/sbin:/sbin/halt
     mail:x:8:12:mail:/var/spool/mail:/sbin/nologin
     operator:x:11:0:operator:/root:/sbin/nologin
     
