C/C++ Build Using CMake
=======================

.. sidebar:: Contents

   .. contents::
      :local:

As this site is heavily into C and C++ (it is into Python too, but
that's another story), it has lots of code in its many subdirectories
and areas. This site is also into build and project management
[#project_management]_, so we do not let code bitrot.

This site has a :doc:`CMake </trainings/repertoire/cmake>` build
associated with it, starting at the root directory of the checkout. It
works as follows.

Getting the Source
------------------

The ``jfasch-home`` project is maintained on `Github
<https://github.com/jfasch/jfasch-home>`__. Clone that. (I use to
store project clones in ``~/work/``).

.. code-block:: shell

   $ cd ~/work/
   $ git clone https://github.com/jfasch/jfasch-home.git

Create Build Directory
----------------------

Technically, this is not necessary; you can always use the source tree
to compile your artifacts into. However, this would clutter the source
directory with many many files that the version control system knows
nothing about. It would complain about all these files, and you would
have to tell it to ignore them.

So, create a build directory. I use to create one in ``/var/jfasch``
(which belongs to me, in a Unix sense). (``jfasch-home`` is the name
of the project, and I like to name build roots after their sources.)

.. code-block:: shell

   $ mkdir /var/jfasch/jfasch-home

Generate ``Makefile`` Build from CMake Sources
----------------------------------------------

Use ``cmake`` to massage the many ``CMakeLists.txt`` files in the
source tree, and generate a parallel build tree in
``/var/jfasch/jfasch-home``.

.. code-block:: shell

   $ cd /var/jfasch/jfasch-home/
   $ cmake ~/work/jfasch-home
   
When successful (the project has a number of dependencies to external
libraries, and ``cmake`` complains loudly when it cannot find them),
start the build.

.. code-block:: shell

   $ make

.. todo::

   Move that out of here, into a place which is central to the entire
   site. There's going to come more.

.. todo::

   Give a list of dependencies, and how to install them.

.. rubric:: Footnotes

.. [#project_management] From a technical perspective, like build
                         management, unittesting, and such. Definitely
                         *not* from a Controller's perspective.
