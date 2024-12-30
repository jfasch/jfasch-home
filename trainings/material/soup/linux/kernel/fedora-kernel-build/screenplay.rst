Building a Fedora Kernel (Screenplay)
=====================================

This is a transcript of what I did to get to a running custom-built
kernel.

* `https://fedoraproject.org/wiki/Building_a_custom_kernel
  <https://fedoraproject.org/wiki/Building_a_custom_kernel>`__

.. contents::
   :local:

Why Build the Entire Kernel When I Only Want to Build a Module
--------------------------------------------------------------

To build only kernel modules, they say, it is sufficient to install
the ``kernel-devel`` package. However, that package tends to not be
available in the version that you need it for (usually you build
against a kernel that runs on a different system, in a different
version).

Building from "Exploded Git Tree"
---------------------------------

(`Documentation on Fedora Wiki
<https://fedoraproject.org/wiki/Building_a_custom_kernel#Building_a_kernel_from_the_exploded_git_trees>`__)

The "Exploded Git Tree" is Fedorish for "a kernel tree that is less
integrated with the Fedora workflow, and thus more suitable for
developers who refuse to integrate with any workflow". This is me.

See :ref:`below <fedora_rpm_build>` if you like workflows and RPMs.

.. code-block:: console

   $ uname -r
   5.8.18-300.fc33.x86_64

Clone tree, and checkout the target system kernel version. Create a
branch for it; read on for why changes need to be committed.

.. code-block:: console

   $ git clone git://git.kernel.org/pub/scm/linux/kernel/git/jwboyer/fedora.git kernel-exploded-git-tree
   $ cd kernel-exploded-git-tree
   $ git checkout kernel-5.8.18-300.fc33

Edit the toplevel ``Makefile`` to fix the ``EXTRAVERSION``. External
modules built against that kernel need to have the exact same version
built-in. I'd have expected the exploded tree to already contain a
suitable ``EXTRAVERSION``, but this is not the case.

Our target kernel is ``5.8.18-300.fc33.x86_64``, so we edit the
toplevel ``Makefile`` to have

.. code-block:: console

   EXTRAVERSION = -300.fc33.x86_64

The kernel build system checks for version control cleanliness, and
adds a "+" sign if something's wrong, such as

* There are uncommitted changes
* The tree is past a tagged commit

These checks are not applied if there is no version control at all, so
let's do this simple workaround.

.. code-block:: console

   $ mv .git .git-hidden

Configure kernel, using the target system config. 

.. code-block:: console

   $ scp 192.168.1.130:/boot/config-5.8.18-300.fc33.x86_64 .config
   $ make oldconfig

Build kernel. If you only want to build external modules against some
specific kernel version, you *do* have to build the entire kernel -
not just modules as it used to be in old times. See :doc:`here
</trainings/material/soup/linux/kernel/fedora-module-build/screenplay>` for
more.

.. code-block:: console

   $ make -j6

Restore version control,

.. code-block:: console

   $ mv .git-hidden .git


.. _fedora_rpm_build:

Building from the RPM Source
----------------------------

(`Documentation on Fedora Wiki
<https://fedoraproject.org/wiki/Building_a_custom_kernel#Building_a_Kernel_from_the_Fedora_source_tree>`__)

.. code-block:: console
   :caption: Prerequisites

   # dnf install fedpkg fedora-packager rpmdevtools ncurses-devel pesign grubby 

* Clone Fedora's kernel RPM. (``-a`` is *anonymous*, as I don't have a
  developer account and don't intent to write back into their repo.)
* As of this writing Fedora is at its 33rd release. We intend to make
  modifications, so we dont just checkout that branch, but rather
  create a tracking branch for it.

  .. code-block:: console

     $ fedpkg clone -a kernel
     $ cd kernel/
     $ git checkout --track remotes/origin/f33

* Modify kernel version, append ``.local``. In ``kernel.spec``, modify
  the line

  .. code-block:: console

     # define buildid .local

  to

  .. code-block:: console

     %define buildid .local

* Pull in more packages, based upon what's in the kernel specs.

  .. code-block:: console

     # dnf builddep kernel.spec

* Add myself to ``/etc/pesign/users``

  .. code-block:: console

     # sh -c 'echo jfasch >> /etc/pesign/users'
     # /usr/libexec/pesign/pesign-authorize 

* Build

.. code-block:: console

   $ fedpkg local
