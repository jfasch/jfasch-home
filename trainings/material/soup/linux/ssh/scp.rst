.. ot-topic:: linux.ssh.scp
   :dependencies: linux.ssh.basics

.. meta::
   :description: Slide material: scp (secure copy)
   :keywords: linux, ssh, scp, secure copy, training

.. include:: <mmlalias.txt>


SSH: Secure Copy (``scp``)
==========================

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 1 scp <https://man7.org/linux/man-pages/man1/scp.1.html>`__

What Is That?
-------------

* Conceptually like ``cp``
* *Remote* copy
* Via SSH protocol |longrightarrow| encrypted

Copy Single File From Local To Remote
-------------------------------------

Copy ``/etc/passwd`` to ``jfasch``'s home directory on ``home.com``
(non-interactively logged in as ``jfasch``). This results in a file
``~jfasch/passwd`` on the remote machine.

.. code-block:: console

   $ scp /etc/passwd jfasch@home.com:

Same, but changing the name to ``my-passwd`` (effectively using a
destination path *relative* to ``jfasch``'s home directory). This
results in a file ``~jfasch/my-passwd`` on the remote machine.

.. code-block:: console

   $ scp /etc/passwd jfasch@home.com:my-passwd
   
Same, but changing the destination to ``/tmp/my-passwd`` (an *absolute
path* on the remote machine). This results in a file
``/tmp/my-passwd`` on the remote machine.

.. code-block:: console

   $ scp /etc/passwd jfasch@home.com:/tmp/my-passwd
   
Copy Single File from Remote To Local
-------------------------------------

Likewise, ``scp`` can copy files from remote to local. (Again, using
the ``/etc/passwd`` file, but this time the *remote* one.) This will
result in a file ``~jfasch/passwd`` on the local machine.

.. code-block:: console

   $ scp jfasch@home.com:/etc/passwd .

Same, but changing the name.

.. code-block:: console

   $ scp jfasch@home.com:/etc/passwd /tmp/my-passwd

(You get the point)

Copy An Entire Directory Tree (``-r``)
--------------------------------------

Like its ancestor, ``cp``, ``scp`` supports the ``-r`` option to copy
directories *recursively*.

Copy all my documents (in ``~/Documents``) to the remote machine,
under the remote name ``~/MyDocuments``.

.. code-block:: console

   $ scp -r ~/Documents jfasch@home.com:MyDocuments

Copy Multiple File From Here To There
-------------------------------------

Like ``cp``, ``scp`` can copy multiple files. In this case the
*single* destination must be a directory, obviously.

.. code-block:: console

   $ scp /etc/passwd /etc/group ~/.bashrc jfasch@home.com:MyDocuments

Also recusively,

.. code-block:: console

   $ scp -r ~/Downloads ~/Pictures ~/.bashrc jfasch@home.com:MyDocuments

Copy From One Remote To A Different Remote
------------------------------------------

``scp`` is not restricted to copying to or from the local machine. You
can use the local machine to copy from one remote machine to another
remote machine.

Here, I use my laptop on the train to copy a project tree from home to
a customer.

.. code-block:: console

   $ scp -r jfasch@home.com:project joerg.faschingbauer@customer.com:

.. note::

   To save mobile bandwidth though, it would be more appropriate to
   not use the laptop as a mediator. Realistically, one would use
   remote command execution on ``home.com``. For example, to transfer
   the ``project`` to ``customer.com`` directly,

   .. code-block:: console

      $ ssh jfasch@home.com "scp project joerg.faschingbauer@customer.com:"

More Options
------------

.. list-table::
   :align: left
   :header-rows: 1

   * * Option
     * Descriptiotn
   * * ``-r``
     * Recursive copy
   * * ``-p``
     * Preserve access timestamps and permissions
   * * ``-P``
     * Use a port number other than the default, 22. For example,
       ``scp -P 2020 ...``

