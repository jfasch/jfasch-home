.. include:: <mmlalias.txt>

Scripts
=======

.. contents::
   :local:

A Script Ain't A Project
------------------------

* Main purpose: prototyping project work without a project
* No cache (|longrightarrow| persistent variables)
* No targets (after all, nothing is built)
* No subdirectories (nothing is built in subdirectories either)
* Invocation: ``cmake -P <script>``

.. literalinclude:: code/hello.cmake
   :caption: :download:`hello.cmake (download) <code/hello.cmake>`
   :language: cmake

.. command-output:: cmake -P hello.cmake
   :cwd: code
   :shell:

Passing Commandline Parameters
------------------------------

* ``-Dname=value`` - just like passing parameters into a project build

.. literalinclude:: code/hello-person.cmake
   :caption: :download:`hello-person.cmake (download)
             <code/hello-person.cmake>`
   :language: cmake

.. command-output:: cmake -DPERSON="Joerg Faschingbauer" -P hello-person.cmake
   :cwd: code
   :shell:
