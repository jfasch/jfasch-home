.. include:: <mmlalias.txt>


``cat``
=======

.. contents::
   :local:

``cat``
-------

.. sidebar::

   **Documentation**

   * `man -s 1 cat
     <https://man7.org/linux/man-pages/man1/cat.1.html>`__

* ``cat``: short for con- *cat* -enate
* Concatenate a number of files onto ``stdout``

  .. code-block:: console

     $ cat file1 file2 ...

* Frequently used to show content of a single short file (rather than
  opening the file with an editor)

  .. code-block:: console

     $ cat /etc/passwd
     root:x:0:0:root:/root:/bin/bash
     bin:x:1:1:bin:/bin:/sbin/nologin
     daemon:x:2:2:daemon:/sbin:/sbin/nologin
     ...
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash
     ...
