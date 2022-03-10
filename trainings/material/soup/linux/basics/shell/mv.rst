.. ot-topic:: linux.basics.shell.mv
   :dependencies: linux.basics.shell.file_dir_create_rm,
		  linux.basics.shell.cp,
		  linux.basics.shell.paths

.. include:: <mmlalias.txt>


Moving and Renaming: ``mv``
===========================

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 1 mv <https://man7.org/linux/man-pages/man1/mv.1.html>`__

Renaming A File (or Directory)
------------------------------

.. code-block:: console

   $ mv Umsatzsteuerbescheid1.pdf Umsatzsteuerbescheid-2021.pdf 

Moving a File to Somewhere Else
-------------------------------

.. code-block:: console

   $ mv Umsatzsteuerbescheid-2021.pdf ~/Homebrain/Buchhaltung/Umsatzsteuerbescheide/

Moving a Directory to Somewhere Else
------------------------------------

.. code-block:: console

   $ mv ~/Homebrain/Buchhaltung/Umsatzsteuerbescheide ~/tmp/Finanzamt-Abgabe

