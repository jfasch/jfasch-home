.. include:: <mmlalias.txt>


2025-06-26: Exam *Embedded Computing 1*
=======================================

**NAME:**

All of the questions below have multiple answers that might be
**True** or **False**. Multiple answers might be **True**, just as
multiple answers might be **False**. Please mark the checkbox in the
respective column, to the best of your knowledge.

Each of your correct marks adds one point to the total. **Each
incorrect mark subtracts one point!** An unchecked answer counts as
incorrect, thus subtracting one point - as does checking both boxes.

.. contents::
   :local:

Pointers Considered Harmful
---------------------------

Say you compile and run the program below, which is obviously buggy:
it accesses memory that it never allocated. How large can the
resulting suffering become?

.. literalinclude:: code/bad-pointer-access.cpp
   :language: c++

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * It could happen that address ``666`` (which is likely to
       contain OS data because that address is very low) has the
       status bits of your internal SSD, and overwriting these could
       turn your SSD into an expensive brick.
     *
     *
   * * The OS intercepts a hardware exception from the Memory
       Management Unit (MMU) which says, "At ``666`` there is no
       memory allocated for the current process". As a result the OS
       terminates the process.
     *
     *
   * * The incident is logged, you are logged out of your computer
       immediately, and you can never log in again.
     *
     *
   * * A fellow process on the system might have rightfully allocated
       memory at position ``666``, and it is that process that falls
       victim to your mistake.
     *
     *

Doing Nothing, But Loudly
-------------------------

Say you compile and run the program below, which is not exactly buggy
in the sense of the program above, but might behave in a way that is
not nice to others (you will agree that there are actually two
"mights", but there is still some room for misbehaviour).

If that program misbehaves, what is going to happen?

.. literalinclude:: code/bad-cpu-consumption.cpp
   :language: c++

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * The system will come to a halt because the process never yields
       the CPU.
     *
     *
   * * The next mouse-move or key-press interrupts the CPU (and thus
       the misbehaving process). From within the interrupt service
       routine, the OS notices that a process went nuts and kills it.
     *
     *
   * * The fan (if any) might try to cool the CPU.
     *
     *
   * * The OS tries hard to be nice to everybody and does not kill the
       offender. Rather, the offender receives a penalty - less CPU
       cake - in favor of those who behave.
     *
     *

Permissions: Device Access (For Example)
----------------------------------------

User ``jfasch`` wants to control some peripheral using an IO pin (read
and write access on ``/dev/gpiochip0`` is required to use an IO
pin). Given the following situation, what would be the options?

.. code-block:: console

   $ ls -l /dev/gpiochip0 
   crw-rw---- 1 root gpio 254, 0 Jun 15 22:52 /dev/gpiochip0

.. code-block:: console

   $ id
   uid=1001(jfasch) gid=1001(jfasch) groups=1001(jfasch)

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Simply *do* request and use the required IO.
     *
     *
   * * Become ``root``, and then request and use the required IO.
     *
     *
   * * Ask the administrator to make ``jfasch`` member of the ``sudo``
       group, and then request and use the required IO.
     *
     *
   * * Ask the administrator to make ``jfasch`` member of the ``sudo``
       group, re-login, become ``root``, and then request and use the
       required IO.
     *
     *
   * * Ask the administrator to make ``jfasch`` member of the ``gpio``
       group, re-login, and then as ``jfasch`` request and use the
       required IO.
     *
     *

Permissions: File Access (Simple)
---------------------------------

The file ``/etc/passwd`` contains user records of the form

.. code-block:: console

   jfasch:x:1001:1001::/home/jfasch:/bin/bash

, where the last field (fields are separated with ':') contains the
login shell.

Given that ``/etc/passwd`` has permissions like

.. code-block:: console

   $ ls -l /etc/passwd
   -rw-r--r-- 1 root root 1623 Dec 30  2020 /etc/passwd

And given that ``jfasch`` has credentials like

.. code-block:: console

   $ id
   uid=1001(jfasch) gid=1001(jfasch) groups=1001(jfasch)

Would user ``jfasch`` be able to determine his login shell from
reading ``/etc/passwd``?

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Yes
     *
     *

Would user ``jfasch`` be able to set his login shell to
e.g. ``/bin/zsh`` by modifying his login shell field in
``/etc/passwd``?

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Yes
     *
     *

Permissions: File Access (Involving Directory Access)
-----------------------------------------------------

Given a directory with the following permissions (and the permissions
on its contained files),

.. code-block:: console

   $ ls -dl ~/some-directory/
   drwxr-xr-x 2 jfasch jfasch 4096 Jun 25 19:26 /home/jfasch/some-directory/
   $ ls -l ~/some-directory/
   total 4
   -rw-r--r-- 1 jfasch jfasch 1623 Jun 25 19:31 my-bitcoins.money

Would anybody on the system be able to read
``/home/jfasch/some-directory/my-bitcoins.money``?

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Yes
     *
     *

What are ``jfasch``'s options to *not* disclose the contents of
``/home/jfasch/some-directory/my-bitcoins.money`` to anybody on the
system?

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * ``chmod 666 ~/some-directory``
     *
     *
   * * ``chmod 700 ~/some-directory``
     *
     *
   * * ``chmod 770 ~/some-directory`` (provided that nobody else but
       ``jfasch`` is member of group ``jfasch``)
     *
     *
   * * ``chmod go-w ~/some-directory/my-bitcoins.money``
     *
     *

Object Oriented Programming: Polymorphic Use Of Types
-----------------------------------------------------

When (and why) would you design an *interface* and provide one or more
*implementations* of it?

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Always. Even if I do not yet see that there could be an
       alternative implementation of the class that I'm about to
       write, I design an interface and make the class implement it -
       because in the future there *could* be.
     *
     *
   * * I'm about to implement code for one particular sensor device (a
       temperature sensor, say), and on top of that I intend to *use*
       that device as a basis for a data logger. To be able to unit
       test the data logger code *without* real hardware, I design an
       interface for the sensor, and provide two implementations of
       it: *real hardware* and *mockup*.
     *
     *
   * * Always. I do this for performance. Indirect function calls
       (brought about by the dynamic dispatch mechanism of ``virtual``
       methods) are way faster than direct calls.
     *
     *
   * * I implement a data logger framework - routines for CSV writing,
       cloud communication, and whatnot. That code should not depend
       on a particular sensor type (e.g. DS18B20 which is a Onewire
       device), but rather I want to sell the code to companies who
       bring their own sensor types.
     *
     *

SSH Keys, And Crypto Keys In General
------------------------------------

What could happen if I disclose my (SSH) keys - especially the private
key - to a malicious person?  (This could happen if I leave it on an
unencrypted filesystem on a laptop that I lose, or when I have it on a
system where multipe users are logged in and I don't get the access
permissions right.)

.. list-table::
   :align: left
   :header-rows: 1

   * * Answer
     * True
     * False
   * * Nothing.
     * 
     *
   * * The malicous finder could impersonate as myself on Github where
       I maintain a project that many others depend on, and inject a
       trojan horse kind of security hole.
     *
     *
   * * If I am able to use that key pair to login to my home server
       (by punching a hole like ``TCP/22`` into my firewall), the
       finder could take over my home server and attack all other
       devices in my home network.

     *
     *
