Fedora: Building External Kernel Modules (Screenplay)
=====================================================

Prerequisite: Build Entire Kernel
---------------------------------

* A kernel module is built against the kernel it will be loaded into
* The exact kernel version matters: there is no backward compatibility
* Kernel module uses symbols from the kernel

  * Core kernel modules
  * The kernel proper itself

This means that, as a prerequisite :doc:`the entire target kernel needs to
be built </trainings/material/soup/kernel/fedora-kernel-build/topic>`.

We used to ``make modules`` in the past, so ``Module.symvers`` was
created for the in-tree modules. However, nowadays the build
complains,

.. code-block:: console

   WARNING: modpost: Symbol info of vmlinux is missing. Unresolved symbol check will be entirely skipped.

See `this message
<https://lore.kernel.org/lkml/20200517094859.2376211-19-masahiroy@kernel.org/>`__
for background; to us this means we need to build the entire kernel.

Build Modules
-------------

(See `here
<https://www.kernel.org/doc/html/latest/kbuild/modules.html>`__ for
the whole story.)

.. code-block:: console

   $ MODULE_SRC=/home/jfasch/kernel-training/jf-kernel-course/drivers
   $ KERNEL_BUILD=/home/jfasch/kernel-training/kernel-exploded-git-tree
   $ DEPLOYMENT=/home/jfasch/kernel-training/deployment

.. code-block:: console

   $ cd $MODULE_SRC
   $ make -C $KERNEL_BUILD M=$(pwd)

Install Modules
---------------

You might want to copy the modules into one *deployment* location,
especially if your external modules tree spans subdirectories.

.. code-block:: console

   $ make -C $KERNEL_BUILD M=$(pwd) INSTALL_MOD_PATH=$DEPLOYMENT modules_install
