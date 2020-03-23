Qualivision, Zürich, 1.10.2013
==============================

Fragen und Antworten
--------------------

* **SysV init: Wie kann man die Grace Period zwischen SIGTERM und
  SIGKILL beeinflussen?**

  `man shutdown
  <http://man7.org/linux/man-pages/man8/shutdown.8.html>`__:
  ``shutdown -t 42``

  (Herausgefunden durch lesen des `Sourcecodes
  <http://svn.savannah.nongnu.org/viewvc/sysvinit/trunk/src/init.c?root=sysvinit&view=markup>`__,
  und nachfolgendes Lesen der Manpage :-) )

* **Wie kann man shutdown verhindern bzw. eine Applikation fragen, ob's
  genehm wäre?**

  * `SysV init <http://savannah.nongnu.org/projects/sysvinit>`__
    bietet diese Möglichkeit
    nicht.
  * `systemd <http://www.freedesktop.org/wiki/Software/systemd/>`__
    scheint es zu können --- siehe `systemd-inhibit
    <http://www.freedesktop.org/software/systemd/man/systemd-inhibit.html>`__

* **Wird der Nice-Value an Children vererbt? Wie ist das mit
  Realtime-Attributen?**

  * `man -s 2 setpriority
    <http://man7.org/linux/man-pages/man2/setpriority.2.html>`__
    (setzt den Nice-Value):

        A child created by fork(2) inherits its parent's nice value.
        The nice value is preserved across execve(2).

  * `man -s 2 sched_setscheduler
    <http://man7.org/linux/man-pages/man2/sched_setscheduler.2.html>`__
    (setzt Realtime Policy und Priority)

        Child processes inherit the scheduling policy and parameters
        across a fork(2).  The scheduling policy and parameters are
        preserved across execve(2).

    ... aber ...

        Since Linux 2.6.32, the SCHED_RESET_ON_FORK flag can be ORed
        in policy when calling sched_setscheduler().  As a result of
        including this flag, children created by fork(2) do not
        inherit privileged scheduling policies.  This feature is
        intended for media-playback applications, and can be used to
        prevent applications evading the RLIMIT_RTTIME resource limit
        (see getr- limit(2)) by creating multiple child processes.

* **Wie geht das mit Threads anstelle von Prozessen?**

  * Threads teilen sich den Nice-Value des Prozesses (`man -s 7
    pthreads
    <http://man7.org/linux/man-pages/man7/pthreads.7.html>`__).
  * Realtime Attribute werden by Default vom startenden an den
    gestarteten Thread weitergegeben --- ausser dies wird explizit
    unterbunden. Siehe dazu `man -s 3 pthread_attr_setinheritsched
    <http://man7.org/linux/man-pages/man3/pthread_attr_setinheritsched.3.html>`__.

        PTHREAD_INHERIT_SCHED
           Threads that are created using attr inherit scheduling
           attributes from the creating thread; the scheduling attributes
           in attr are ignored.
        
        PTHREAD_EXPLICIT_SCHED
           Threads that are created using attr take their scheduling
           attributes from the values specified by the attributes object.
        
           The default setting of the inherit scheduler attribute in a
           newly initialized thread attributes object is
           PTHREAD_INHERIT_SCHED.

* **Gibt es unter Linux sowas ähnliches wie `Filter-Driver
  <http://en.wikipedia.org/wiki/Filter_driver>`__ unter Windows?**

  (Wird offenbar genutzt, um die miserable Performance von
  Netzwerkdrivern unter hoher Interruptlast zu verbessern)

  Unter Linux sollte das nicht nötig sein. Man hat sich dort
  diesbezüglich was überlegt: unter eben solcher Last schaltet das
  Netzwerkdriver-Framework um auf *Polling Mode*.
  
  * `http://lwn.net/Articles/30107/
    <http://lwn.net/Articles/30107/>`__
  *
    `http://www.linuxfoundation.org/collaborate/workgroups/networking/napi
    <http://www.linuxfoundation.org/collaborate/workgroups/networking/napi>`__

* **Gibt es Open-Source Modbus Implementationen?**

  * `http://libmodbus.org/ <http://libmodbus.org/>`__
  * `http://www.freemodbus.org/ <http://www.freemodbus.org/>`__

* **Wie konfiguriert man `Jumbo Frames
  <http://en.wikipedia.org/wiki/Jumbo_frame>`__**

  Man setzt die MTU auf mehr als 1500 Bytes,

  .. code-block:: console

     # ip link set dev eth0 mtu 9000

  oder 

  .. code-block:: console

     # ifconfig eth0 mtu 9000
  
  Persistent abgelegt wird die Konfiguration auf Debian
  in ``/etc/network/interfaces``:

  .. code-block:: console

     auto eth0
     iface eth0 inet static
        ...
        mtu 9000
        ...

  Vorsicht mit Routern, die die Pakete fragmentieren,

  .. code-block:: console

     # traceroute --mtu ...

* **Wie monitore ich eine Netzwerkverbindung bzw. deren Güte?**

  Ohne es genau zu wissen glaube ich, dass SAR ("System Activity
  Reporter") aus dem `sysstat
  <http://sebastien.godard.pagesperso-orange.fr/>`__ Paket das macht
  (Vorsicht, das Layout der Homepage ist schmerzvoll).

  `Hier
  <http://bencane.com/2012/07/07/sar-sysstat-linux-performance-statistics-with-ease/>`__
  ein netter Artikel.

