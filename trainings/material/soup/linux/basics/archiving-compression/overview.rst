.. include:: <mmlalias.txt>


Archiving and Compression
=========================

.. contents::
   :local:

Overview
--------

* UNIX mantra: every tool should do one thing well
* |longrightarrow| Compression is one thing, archiving is a different
  thing
* Archive tools

  * ``tar`` - most popular (but "ugly as hell", `Quote from Al Viro
    <https://www.kernel.org/doc/Documentation/filesystems/ramfs-rootfs-initramfs.rst>`__)
  * ``cpio`` - older but cleaner - Archivformat von Linux's ``initramfs``
    
* Compression tools. Good as filters in a pipeline.

  * ``gzip``, common extension ``.gz``
  * ``bzip2``, common extension ``.bz2``
  * ``lzma``, common extension ``.lzma``

Compression Tools: Comparison
-----------------------------

Compressing a ``.tar`` file of the Linux kernel tree (roughly 430MB):

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Tool
     * Time consumed
     * Size
   * * ``gzip``
     * 20s
     * 95MB
   * * ``bzip2``
     * 1m 11s
     * 74MB
   * * ``lzma``
     * 5m 32s
     * 64MB

.. note::

   The numbers have been taken ages ago, so they should be seen only
   in relation
