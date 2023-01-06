Installing Prerequisites
========================

.. contents::
   :local:

``libgpiod``
------------

Clone, and Massage
..................

``autogen.sh`` does a ``configure`` step (in the source directory!) by
default; using ``NOCONFIGURE=yes`` to suppress it.

.. code-block:: console

   $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git

First try, naively ...

.. code-block:: console

   $ NOCONFIGURE=yes ./autogen.sh
   autoreconf: export WARNINGS=
   autoreconf: Entering directory '.'
   autoreconf: configure.ac: not using Gettext
   autoreconf: running: aclocal --force -I m4
   aclocal: warning: couldn't open directory 'm4': No such file or directory
   autoreconf: configure.ac: tracing
   autoreconf: configure.ac: creating directory autostuff
   autoreconf: running: libtoolize --copy --force
   libtoolize: putting auxiliary files in AC_CONFIG_AUX_DIR, 'autostuff'.
   libtoolize: copying file 'autostuff/ltmain.sh'
   libtoolize: putting macros in AC_CONFIG_MACRO_DIRS, 'm4'.
   libtoolize: copying file 'm4/libtool.m4'
   libtoolize: copying file 'm4/ltoptions.m4'
   libtoolize: copying file 'm4/ltsugar.m4'
   libtoolize: copying file 'm4/ltversion.m4'
   libtoolize: copying file 'm4/lt~obsolete.m4'
   autoreconf: configure.ac: not using Intltool
   autoreconf: configure.ac: not using Gtkdoc
   autoreconf: running: aclocal --force -I m4
   autoreconf: running: /usr/bin/autoconf --force
   configure.ac:204: error: Unexpanded AX_ macro found. Please install GNU autoconf-archive.
         If this token and others are legitimate, please use m4_pattern_allow.
         See the Autoconf documentation.
   autoreconf: error: /usr/bin/autoconf failed with exit status: 1

Ah yes, ``autoconf-archive`` ...

.. code-block:: console

   $ sudo dnf install autoconf-archive
   ... works ...

.. code-block:: console

   $ NOCONFIGURE=yes ./autogen.sh
   ... better now ...

Build
-----

.. code-block:: console

   $ mkdir ~/tmp/libgpiod-build/
   $ cd ~/tmp/libgpiod-build/

.. code-block:: console

   $ pwd         # <--- in the build directory
   /home/jfasch/tmp/libgpiod-build
   $ /home/jfasch/work/libgpiod/configure --enable-bindings-cxx --enable-bindings-python  --enable-tools --prefix=/home/jfasch/install/libgpiod
   $ make
   $ make install
