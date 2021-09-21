.. include:: <mmlalias.txt>

.. meta::
   :description: Slide material: scp (secure copy)
   :keywords: linux, ssh, scp, secure copy, training

SSH: Secure Copy
================

.. ot-topic:: devenv.ssh.scp
   :dependencies: devenv.ssh.basics

.. contents::
   :local:

``scp``
-------

``scp``: *secure copy*

* Conceptually like ``cp``
* *Remote* copy
* Via SSH protocol |longrightarrow| encrypted

**Copying a single file into remote ``$HOME``**

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
