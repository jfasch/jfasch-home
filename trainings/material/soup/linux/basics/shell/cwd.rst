.. include:: <mmlalias.txt>


Current Working Directory
=========================

.. contents::
   :local:

Current Working Directory: ``pwd``
----------------------------------

.. sidebar:: Documentation

   * `man -s 1 pwd
     <https://man7.org/linux/man-pages/man1/pwd.1.html>`__

*Explaining the world:*

* Every :doc:`process <../intro/process>` has a *current working
  directory*
* |longrightarrow| CWD is a *process attribute* (see
  :doc:`../intro/process` for more about process attributes)
* Shell is just an ordinary program |longrightarrow| process

  .. code-block:: console
     :caption: A shell's process ID
  
     $ echo $$
     121751

* |longrightarrow| shell has a CWD
* Command: ``pwd`` ("print working directory")

  .. code-block:: console

     $ pwd
     /home/jfasch

Changing The Current Working Directory: ``cd``
----------------------------------------------

* Moving from where we are to there

  .. code-block:: console

     $ pwd
     /home/jfasch
     $ cd /etc/
     $ pwd
     /etc
  
* Moving into my home directory

  .. code-block:: console

     $ pwd
     /etc
     $ cd
     $ pwd
     /home/jfasch
		  
* Same, but with more typing

  .. code-block:: console

     $ cd ~

* Moving into someone else's home directory

  .. code-block:: console

     $ cd ~someone-else
     $ pwd
     /home/someone-else

* Moving back where I been last (where I came from): ``cd -``

  .. code-block:: console

     $ cd ~someone-else
     $ pwd
     /home/someone-else
     $ cd -      # <-- back where I came from
     $ pwd
     /etc

* Moving into parent directory

  .. code-block:: console

     $ cd ..

* No-op nonsense

  .. code-block:: console

     $ cd .
