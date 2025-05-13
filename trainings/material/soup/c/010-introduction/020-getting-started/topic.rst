.. include:: <mmlalias.txt>


Hello World
===========

My First Program (1)
--------------------

.. list-table::

   * * .. literalinclude:: hello.c
          :language: c
	  :caption: :download:`hello.c`

       .. code-block:: console
          :caption: Build and execute

	  $ gcc hello.c
	  $ ./a.out
	  hello, world

     * **What we see ...**

       * A program consists of *functions* and *variables*
       * Functions consist of *statements*
       * Function call (``printf()``) is a statement
       * ``main()`` is special (``int`` return value |longrightarrow|
         *OS Exit Status*)
       * Building appears simple but isn't
       * ``stdio.h``??

My First Program (2)
--------------------

.. list-table::

   * * .. code-block:: c

          #include <stdio.h>

     * * *Declarations* from the *Standard IO Library*
       * Here: for ``printf()``

   * * .. code-block:: c

          int main(void)

     * * *Definition* of ``main()``
       * Required for a program
       * Entry point from the *C runtime*

   * * .. code-block:: c

          {
              printf("hello, world\n");
          }

     * * *Body* of ``main()``
       * *Calling* ``printf()`` with a *string*
         parameter/argument.
       * ``\n`` is the *newline* character

Character Arrays - Strings
--------------------------

**Strings** are special in C


* *Character*: ...
* *String*: zero terminated character array
* Escape sequences, e.g. ``\n`` (newline), ``\t`` (tabulator), ``\"``, ``\0`` (*null*)

The *string* ``"hello,world\n"`` corresponds to ...

.. image:: 01-01-string.dia
