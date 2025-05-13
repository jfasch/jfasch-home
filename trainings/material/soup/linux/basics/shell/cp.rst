.. include:: <mmlalias.txt>


Copying: ``cp``
===============

.. contents::
   :local:

Option Overview
---------------

.. sidebar:: Documentation

   * `man -s 1 cp <https://man7.org/linux/man-pages/man1/cp.1.html>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-r``
     * Recursive (to copy entire directories)
   * * ``-p``
     * Preserve timestamps and permissions
   * * ``-v``
     * Verbose (print progress as you go; most commonly used together
       with ``-r``)
   * * ``-i``
     * Don't let me shoot myself in the foot: prompt before overwrite

Creating backup copy of, say, ``.bashrc`` in the home directory
---------------------------------------------------------------

.. code-block:: console

   $ cp .bashrc .bashrc.save

.. danger::

   ``cp`` (and no other command like it) doesn't keep you from shooting yourself in the foot

   .. code-block:: console
      :caption: Overwriting existing file
 
      $ cp .bashrc .bashrc.save

   Solution: ``-i``

.. code-block:: console

   $ cp -i .bashrc .bashrc.save
   cp: overwrite '.bashrc.save'? y

Similar: copy a file into a different directory, under a different name
-----------------------------------------------------------------------

.. code-block:: console

   $ cp .bashrc /tmp/jfaschs-bashrc

Similar: copy a file into a different directory, keeping its name
-----------------------------------------------------------------

.. code-block:: console

   $ cp .bashrc /tmp

Copy multiple files into a directory
------------------------------------

(The target directory must exist!)

.. code-block:: console

   $ cp ~/Downloads/IMG_*.jpg ~/Pictures/Fotos\ für\ Bilder/

Copying a directory, together with its contents |longrightarrow| recursive copy
-------------------------------------------------------------------------------

.. code-block:: console

   $ cp -r .thunderbird /var/backup/jfasch/thunderbird-backup-2022-03-10
