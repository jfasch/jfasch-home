.. ot-topic:: linux.basics.text_tools.find
   :dependencies: linux.basics.text_tools.grep

.. include:: <mmlalias.txt>


``find``
========

.. contents::
   :local:

Directories durchsuchen mit ``find``
------------------------------------

.. sidebar::

   **Documentation**

   * `man -s 1 find
     <https://man7.org/linux/man-pages/man1/find.1.html>`__

``find`` geht ein Directory rekursiv durch und schreibt (ohne
Optionen) alle Einträge auf ``stdout``.

**Alle Einträge unterhalb des CWD**

.. code-block:: console

   $ find

**Alle Einträge unterhalb eines beliebigen Directorys**

.. code-block:: console

   $ find /etc/init.d

**Alle Einträge unterhalb einer Liste von Directories**

.. code-block:: console

   $ find /etc/init.d /tmp

``find``: Optionen
------------------

* Durch Optionen werden gefundene Einträge gefiltert
* Unübliche Syntax: *Optionen kommen am Ende!*

**Gebräuchliche Optionen:**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Beschreibung
   * * ``-name name``
     * Einträge mit Namen ``name``
   * * ``-type typ``
     * Einträge mit Typ ``typ`` (``f``, ``d``, ``c``, ``b``, ...)
   * * ``-user user``
     * Einträge, die User ``user`` gehören
   * * ``-group group``
     * Einträge, die Gruppe ``group`` gehören
   * * ``-mmin num``
     * Einträge, die *genau* ``num`` Minuten alt sind
   * * ``-mmin -num``
     * Einträge, die *höchstens* ``num`` Minuten alt sind
   * * ``-exec``
     * Aufrufen eines Commands pro gefundenem Eintrag

``find``: Beispiele
-------------------

**Alle Einträge unter ``/etc``, die ``net`` heissen**

.. code-block:: console

   $ find /etc -name net

**Alle Einträge unter ``/etc``, die mit ``net`` beginnen. ``find``
versteht Shell-Globs, aber Vorsicht: Quoting nicht vergessen!**

.. code-block:: console

   $ find /etc -name 'net*'
   $ find /etc -name net\*

**Alle Subdirectories in meinem Homedirectory:**

.. code-block:: console

   $ find ~ -type d

**Alle Entries in ``/var``, die jünger als 10 Minuten sind:**

.. code-block:: console

   $ find /var -mmin -10

**Alle Headerfiles des Kernels in einer Wurscht:**

.. code-block:: console

   $ find /usr/src/linux/ -name \*.h -exec cat {} \;

``find``: Verknüpfungen
-----------------------

Kriterien können mit folgenden Operatoren verknüpft werden

* ``-a``: AND
* ``-o``: OR
* ``!``: NOT; *Vorsicht, Quoting*: History Expansion
* ``(`` und ``)``: Klammerung; *Vorsicht*, das sind
  Shell-Metacharacters |longrightarrow| Quoting

``find``: Verknüpfungen: Beispiele
----------------------------------

**Alle Einträge unter ``/var``, die ``root`` gehören und jünger als 30 Minuten sind:**

.. code-block:: console

   $ find /var -user root -a -mmin -30

**Alle Files in meinem Homedirectory, die jünger als 30 Minuten oder größer als 50K sind:**

.. code-block:: console

   $ find ~ -type f -a \( -mmin -30 -o -size +50k \)
   
1001 weitere Optionen |longrightarrow| `man -s 1 find
<https://man7.org/linux/man-pages/man1/find.1.html>`__
