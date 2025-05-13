.. include:: <mmlalias.txt>


``oprofile``
============

``oprofile`` - How it Works
---------------------------

**How does it work?**

* Hardware based: CPUs have performance counters/events
* NMI, trapped by Linux kernel
* Samples sent to userspace

**Compared to other tools ...**

* Hardware $\to$ low overhead

  * 1-3% they say

* Support for wide variety of performance events

  * Cache miss
  * Branch prediction failure
  * Lots of others I don't understand (|longrightarrow| ``ophelp``)

* *Just works!*

``oprofile`` - Basic Usage (1)
------------------------------

**Profiling a single executable**

.. code-block:: console

   $ operf ./program

* Creates output directory ``oprofile_data``
* Used by reporting tools

  * ``opreport``
  * ``opannotate``
  * ``oparchive``
  * ``opgprof``

``oprofile`` - Basic Usage (2)
------------------------------

.. code-block:: console
   :caption: Report Everything

   $ opreport
   ... long list of processes, library and kernel symbols ...
  
.. code-block:: console
   :caption: Report Symbols and Their Counters

   $ opreport --symbols

.. code-block:: console
   :caption: Take Debug Information Into Account

   $ opreport --debug-info

``oprofile`` - Too Much Information
-----------------------------------

* ``oprofile`` takes samples no matter what
* |longrightarrow| too much information

  * Used shared libraries
  * Kernel

.. code-block:: console
   :caption: Exclude Shared Libraries and Kernel |longrightarrow| ``gprof`` *Flat Profile*

   $ opreport --symbols --exclude-dependent
   ...
   samples  %        symbol name
   2828     88.5410  contains
   358      11.2085  find_duplicates
   8         0.2505  main

``oprofile`` - Call Graph
-------------------------

* ``oprofile`` collects samples in non-maskable interrupt
* |longrightarrow| time critical
* does not (by default) record *caller* information with every sample

.. code-block:: console
   :caption: Have ``operf`` Record Caller On Every Sample

   $ operf --callgraph ./program

.. code-block:: console
   :caption: Report Callers and Callees

   $ opreport --callgraph
   ... no easy reading here ...

``oprofile`` - Kernel Symbols (1)
---------------------------------

**Symbols** come from files |longrightarrow| file mappings

* Executables
* Shared libraries
* Kernel modules

**Kernel** itself is not a file!

* Bootloader loads kernel image into memory
* Kernel not necessarily contained in the file system
* |longrightarrow| Flash memory, network (PXE boot), ...

.. code-block:: console

   $ operf ./program
   $ opreport --symbols
   ...
   8         0.4630  no-vmlinux               /no-vmlinux
   ...

``oprofile`` - Kernel Symbols (2)
---------------------------------

``operf`` **needs some help ...**

.. code-block:: console
   :caption: Helping ``operf`` With Kernel Samples

   $ operf --vmlinux=/root/linux-3.16.5-gentoo/vmlinux ./program

* ``vmlinux`` is not usually an artifact of the kernel build process
* |longrightarrow| ``make vmlinux``
* Redhat: ``kernel-debuginfo``

``oprofile`` - Kernel Modules
-----------------------------

**Samples from kernel modules ...**

* Attributed to *module name* in ``operf`` output
* ... not a file
* ... but can be found in a file
* |longrightarrow| ``opreport`` (and friends) need to look it up

.. code-block:: console
   :caption: Directing ``opreport`` To Module Tree

   $ opreport \
       --image-path=/lib64/modules/3.16.5-gentoo/kernel \
       --symbols
   ...

``oprofile`` - System-Wide Profiling
------------------------------------

**System-Wide Profiling: Why?**

* Application ("appliance'?) consists of multiple processes
* One or more kernel drivers play a role
* |longrightarrow| one wants to know more about the big picture

.. code-block:: console
   :caption: System Wide Profiling (have to be root for that)

   # operf --system-wide
   # operf --system-wide --vmlinux=/path/to/vmlinux

|longrightarrow| Samples from *everywhere* ...

* Userland processes
* Kernel code used by system calls
* Kernel code from interrupt service routines
* Kernel code from kernel threads

``oprofile`` - Offline Profiling
--------------------------------

**Absolutely cool:** ``oparchive``

* Samples gathered on production system
* Analyzed on development system
* |longrightarrow| Transfer of every file involved

.. code-block:: console
   :caption: Archiving on Production Machine

   $ operf ./program   # or whatever ...
   $ oparchive --output-directory=$HOME/operf-output
   $ tar -C $HOME -jcf operf-output.tar.bz2 operf-output

.. code-block:: console
   :caption: Later, at Home

   $ tar jxf operf-output.tar.bz2
   $ opreport archive:./operf-output

``oprofile`` - Graphical Beauty
-------------------------------

**Real men don't need no graphics** - but anyway, here it is ...

.. code-block:: console
   :caption: Converting ``oprofile_data/`` into ``callgrind`` Stuff

   $ opreport -gdf|op2calltree
   $ ls oprof.out.*
   oprof.out.firefox                oprof.out.NetworkManager
   oprof.out.gnome-settings-daemon  oprof.out.nm-applet
   oprof.out.gnome-shell            oprof.out.operf
   oprof.out.gnome-terminal-server  

* One ``callgrind`` file for each process ``oprofile_data/`` has
  samples from
* Nicely viewable with ``kcachegrind``
