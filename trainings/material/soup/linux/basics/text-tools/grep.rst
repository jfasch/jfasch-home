.. ot-topic:: linux.basics.text_tools.grep
   :dependencies: linux.basics.text_tools.less

.. include:: <mmlalias.txt>


``grep``
========

.. contents::
   :local:

Searching With ``grep``
-----------------------

.. sidebar::

   **Documentation**

   * `man -s 1 grep
     <https://man7.org/linux/man-pages/man1/grep.1.html>`__

* *G* lobal *R* egular *E* xpression *P* rint

  * ``sed`` (*S* tream *ED* itor) terminology

* Its usage has become a verb: *to grep* (predates *to google*)
* Simplest usage: all occurences of ``jfasch`` in ``/etc/group``

  .. code-block:: console

     $ grep jfasch /etc/group
     adm::4:root,adm,daemon,jfasch
     portage::250:portage,jfasch
     jfasch:x:1000:

Regular Expressions
-------------------

* More capable search than a simple word
* Shell quoting in order, to avoid shell expansion
* Example: ``jfasch``, as a member of a group (and not the group
  itself)

  .. code-block:: console

     $ grep '^.*[:,]jfasch' /etc/group
     adm::4:root,adm,daemon,jfasch
     portage::250:portage,jfasch

Options
-------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-i``
     * Case insensitive pattern
   * * ``-l``
     * Show only filename where pattern was found, not the hit itself
   * * ``-n``
     * Show line numbers
   * * ``-r``
     * Search entore directory tree(s), recursively
   * * ``-v``
     * Negation: show only lines where pattern is *not* found

More About Regular Expressions
------------------------------

* Pattern language |longrightarrow| finite state machine
* Much like programming
* Deserves a course of it own
* `man -s 1 grep
  <https://man7.org/linux/man-pages/man1/grep.1.html>`__
* Perl Regular Expressions

  * `perlre <https://perldoc.perl.org/perlre>`__
  * `perlretut <https://perldoc.perl.org/perlretut>`__
  * `perlrequick <https://perldoc.perl.org/perlrequick>`__
  * `Jeffrey E.F. Friedl: Mastering Regular Expressions (O'Reilly)
    <http://regex.info/>`__

