.. ot-topic:: linux.toolchain.separate_compilation

.. include:: <mmlalias.txt>


Zooming In: Separate Compilation
================================

.. contents::
   :local:

Remember: All-In-One Build ...
------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Main
     * "Modularized" out
   * * .. literalinclude:: hello-first.c
          :caption: :download:`hello-first.c`
          :language: c
     * .. literalinclude:: hello.h
          :caption: :download:`hello.h`
	  :language: c

       .. literalinclude:: hello.c
          :caption: :download:`hello.c`
          :language: c

Would be built like so,

.. code-block:: console
  
   $ gcc -o hello-first hello-first.c hello.c

Adding Another ``main()``: What About Shared Code?
--------------------------------------------------

* Lets say ``hello()`` is a popular thing
* |longrightarrow| more code will want to use it

**So here's another user ...**

.. literalinclude:: hello-second.c
   :language: c
   :caption: :download:`hello-second.c`

.. code-block:: console
  
   $ gcc -o hello-second hello-second.c hello.c

**This is bad!**

* Code is reused, *but* ...
* Compiled twice
* |longrightarrow| Build time increases as more code uses ``hello()``
* |longrightarrow| This does not scale!

Solution: Separate Compilation And Linking Steps
------------------------------------------------

**Goal**

* Only a single compilation step of ``hello.c``

  * This cannot produce an executable, obviousl
  * Compilation only |longrightarrow| ``hello.o``

  .. code-block:: console

     $ gcc -c -o hello.o hello.c

* Separate compilation steps of each user

  * ``hello-first.c`` |longrightarrow| ``hello-first.o``

    .. code-block:: console

       $ gcc -c -o hello-first.o hello-first.c 

  * ``hello-second.c`` |longrightarrow| ``hello-second.o``

    .. code-block:: console

       $ gcc -c -o hello-second.o hello-second.c 

* Linking existing object files into executables

  * ``hello-first`` needs ``hello-first.o`` and ``hello.o``

    .. code-block:: console

       $ gcc -o hello-first hello-first.o hello.o

  * ``hello-second`` needs ``hello-second.o`` and ``hello.o``

    .. code-block:: console

       $ gcc -o hello-second hello-second.o hello.o
