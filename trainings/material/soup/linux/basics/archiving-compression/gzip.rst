.. ot-topic:: linux.basics.archiving_compression.gzip
   :dependencies: linux.basics.shell.commandline,
		  linux.basics.archiving_compression.overview

.. include:: <mmlalias.txt>


``gzip``
========

.. contents::
   :local:

Functionality
-------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-d``
     * *De* - compression (default: compression)
   * * ``-c``
     * Send output to ``stdout``

**Associated Tools**
  
* ``gunzip``. Equivalent of ``gzip -d``.
* ``zgrep``. Grepping in ``gzip``-compressed files.
* ``zcat``. Equivalent of ``gzip -cd``.
* ``zless``. Paging a compressed file.

Examples
--------

* Compressing the file ``cd.iso``. ``cd.iso`` appears to be *moved*
  to ``cd.iso.gz``.

  .. code-block:: console

     $ gzip cd.iso

* Compressing ``cd.iso``, but keeping the original intact.

  .. code-block:: console

     $ gzip -c cd.iso > cd.iso.gz

* *De* compressing the file ``cd.iso.gz``. ``cd.iso.gz`` appears to be
  *moved* to ``cd.iso``.

  .. code-block:: console

     $ gzip -d cd.iso.gz

* *De* compressing ``cd.iso.gz``, but keeping the original intact.

  .. code-block:: console

     $ gzip -cd cd.iso.gz > cd.iso

