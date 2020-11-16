Building a Fedora Kernel (Screenplay)
=====================================

This is a writeuptranscript of what I did to get to a running
custom-built kernel.

See `this document
<https://fedoraproject.org/wiki/Building_a_custom_kernel>`__ for more.

Prerequisites
-------------

.. code-block:: console

   # dnf install fedpkg fedora-packager rpmdevtools ncurses-devel pesign grubby 

Kernel Sources, and more Prerequisites and Preparation
------------------------------------------------------

* Clone Fedora's kernel. (``-a`` is *anonymous*, as I don't have a
  developer account and don't intent to write back into their repo.)
* As of this writing Fedora is at it 33rd release. We intend to make
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

     $ sudo dnf builddep kernel.spec

* Add myself to ``/etc/pesign/users``

  .. code-block:: console

     $ sudo sh -c 'echo jfasch >> /etc/pesign/users'
     $ sudo /usr/libexec/pesign/pesign-authorize 

Initial Build
-------------

.. code-block:: console

   $ fedpkg local
