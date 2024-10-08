.. ot-topic:: linux.basics.shell.special_paths
   :dependencies: linux.basics.shell.paths

.. include:: <mmlalias.txt>


Special Paths
=============

* ``/``: root directory - **where it all begins**
* ``~``: home directory of the user

  .. code-block:: console

     $ id -u
     1000
     $ id -un
     jfasch
     $ pwd
     /etc
     $ cd ~
     $ pwd
     /home/jfasch

* ``~someone-else``: home directory of someone else
* ``.``: current working directory

  .. code-block:: console

     $ pwd
     /home/jfasch
     $ cd .
     $ pwd
     /home/jfasch

* ``..``: parent directory of CWD

  .. code-block:: console

     $ cd ..
     $ pwd
     /home

  .. code-block:: console

     $ ls -l
     total 0
     drwx------. 1 jfasch       jfasch       554 Mar  8 10:51 jfasch
     drwx------. 1 someone-else someone-else  92 Mar  3 14:12 someone-else

  ``.`` and ``..`` are regular path components ...

  .. code-block:: console

     $ cd ~jfasch/../someone-else
     $ pwd
     /home/someone-else
