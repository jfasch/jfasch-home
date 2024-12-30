.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck showing basic linux kernel module
   :keywords: schulung, training, linux, kernel, module, load, unload,
              initialization, build

Module Loading, Hello World (Slideshow)
=======================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_hello/_morph>`__

Kernel Driver Anatomy
---------------------

* Built-in vs. loadable module

  * Built-in driver is statically linked into the kernel (part of the
    kernel image itself)
  * Loadable module is much like a shared library in userspace

* Initialization on module load
* Deinitialization on module unload
* Usually used to 

  * (Un)register the module in its subsystem
  * Create/delete device nodes
  * Depends on subsystem initialization policy though: for example,
    PCI and USB have a ``probe()`` driver method.

Built-In vs. Loadable Module
----------------------------

* Detail: huge difference, binary-code-wise
* Conceptually:

  * Built-in drivers initialized at kernel boot (deinitialized at
    shutdown)
  * Loadable modules initialized at load time (deinitialized at
    unload)

Minimum Module Source
---------------------

.. code-block:: c
   :caption: ``hello.c``

   #include <linux/printk.h>
   #include <linux/module.h>

   
   static int hello_init(void)
   {
       printk(KERN_DEBUG "hello init\n");
       return 0;
   }
   static void hello_exit(void)
   {
       printk(KERN_DEBUG "hello exit\n");
   }
   
   module_init(hello_init);
   module_exit(hello_exit);

Gotchas: ``init()`` and ``exit()``
----------------------------------

* ``init()`` returns 0 on success
* On error, returns negative value of userspace's ``errno``

  * E.g., ``return -EINVAL``
  * ``EINVAL`` is the most unspecific, one for all, errors

* Careful when ``init()`` fails *in the middle*

  * |longrightarrow| *partial initialization*
  * |longrightarrow| before returning, ``init()`` must revert what is
    did so far

* If ``init()`` succeeds, then ``exit()`` is supposed to revert
  everything that ``init()`` did
* If ``init()`` fails, the module is *not* loaded (and thus ``exit()``
  is not called)

Module Build
------------

Fundamentally different ways to build a module:

* *In tree*: part of the kernel source tree

  * Maintained as part of the kernel
  * Kernel's *internal* API/ABI is by definition *not stable*
    |longrightarrow| all drivers should ideally be part of the kernel
  * Not always possible: commercial, exotic, simply unwanted upstream,
    ...

* *Out of tree*: not part of the kernel tree

  * Maintained by third parties
  * **The remainder assumes we are building an external module**

* Whole story `here
  <https://www.kernel.org/doc/html/latest/kbuild/makefiles.html>`__

Minimum ``Makefile``, Building
------------------------------

.. code-block:: Makefile
   :caption: ``Makefile``

   obj-m += hello.o

**How to build**

* ``Makefile`` and ``hello.c`` in the same directory
* ... which is the currect working directory

.. code-block:: console

   $ make -C /path/to/kernel/tree M=$(pwd) modules
   make: Entering directory '/path/to/kernel/tree'
     CC [M]  /tmp/hello.o
     MODPOST /tmp/Module.symvers
   WARNING: modpost: missing MODULE_LICENSE() in /tmp/hello.o
     CC [M]  /tmp/hello.mod.o
     LD [M]  /tmp/hello.ko
   make: Leaving directory '/path/to/kernel/tree'



Modules: Load/Unload Commands
-----------------------------

.. list-table::
   :widths: auto
   :align: left

   * - ``lsmod``
     - Lists all loaded modules
     - `man page <https://man7.org/linux/man-pages/man8/lsmod.8.html>`__
   * - ``insmod``
     - Inserts module by *file name* (e.g. ``insmod
       ../path/to/hello.ko``)
       
       * No path search
       * No dependency resolution (does fail if there are unresolved
	 symbols)
       * No nothing

     - `man page <https://man7.org/linux/man-pages/man8/insmod.8.html>`__
   * - ``modprobe``
     - Inserts module by *module name* (e.g. ``modprobe hello``)
       
       * Searches for ``hello.ko`` in ``/lib/modules/$(uname -r)``
       * Loads all dependencies
       * Variant: ``modprobe -r hello`` *unloads* including
         dependencies
       
     - `man page <https://man7.org/linux/man-pages/man8/modprobe.8.html>`__
   * - ``rmmod``
     - * Removes/unloads module by *module name* (e.g. ``rmmod hello``)
       * Leaves now-unused dependencies in place (use ``modprobe -r``
	 instead)
     - `man page <https://man7.org/linux/man-pages/man8/rmmod.8.html>`__

Modules: Dependency (and other) Databases
-----------------------------------------

**Question**: How does ``modprobe`` know?

.. code-block:: console

   $ ls -1 /lib/modules/$(uname -r)/modules.*
   /lib/modules/5.9.16-200.fc33.x86_64/modules.dep
   /lib/modules/5.9.16-200.fc33.x86_64/modules.dep.bin
   /lib/modules/5.9.16-200.fc33.x86_64/modules.softdep
   /lib/modules/5.9.16-200.fc33.x86_64/modules.symbols
   /lib/modules/5.9.16-200.fc33.x86_64/modules.symbols.bin
   ... many more omitted ...

|longrightarrow| Databases must be rebuilt after changes to
``/lib/modules/$(uname -r)``

.. code-block:: console

   # depmod -a
