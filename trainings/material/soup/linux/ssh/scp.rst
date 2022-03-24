.. ot-topic:: linux.ssh.scp
   :dependencies: linux.ssh.basics

.. meta::
   :description: Slide material: scp (secure copy)
   :keywords: linux, ssh, scp, secure copy, training

.. include:: <mmlalias.txt>


SSH: Secure Copy
================

.. contents::
   :local:

.. sidebar:: Documentation

   * man -s 1 scp
     <https://man7.org/linux/man-pages/man1/scp.1.html>`__

``scp``: Secure Copy
--------------------

.. sidebar::

   If the SSH daemon runs on a non-default (22) port, you use the ``-P
   <portno>`` (uppercase "P") option. For example:

   .. code-block:: console

      $ scp -P 2020 ~/.bashrc jfasch@home.com:

* Conceptually like ``cp``
* *Remote* copy
* Via SSH protocol |longrightarrow| encrypted

**Copying a single file into remote** ``$HOME``

.. code-block:: console

   $ scp ~/.bashrc jfasch@home.com:

.. code-block:: console

   $ scp ~/.bashrc jfasch@home.com:~

**Copying a single file from remote to local**

.. code-block:: console

   $ scp jfasch@home.com:.bashrc ~/.bashrc

**Recursive copy** (just like ``cp -r``)

.. code-block:: console

   $ scp -r ~/Downloads jfasch@home.com:

