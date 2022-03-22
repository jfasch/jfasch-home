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

``scp``: Secure Copy
--------------------

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
