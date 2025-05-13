Quiz: Toolchain (Solutions)
===========================

.. contents::
   :local:

Native
------

* Compiler: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The compiler combines multiple object files together into one
         executable
       * 
       * n
     * * The compiler turns a single source file into an object
         (``.o``) file
       * y
       *
     * * Object files are not executable
       * y
       *
     * * Object files are executable
       *
       * n

* Linker: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The linker combines multiple object files together into one
         executable
       * y
       *
     * * The linker combines multiple object files together into a
         static library
       * 
       * n

Cross
-----

* Cross: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The cross compiler is an executable that runs on the build
         machine
       * y
       *
     * * The cross compiler is an executable that runs on the target
         machine
       * y
       *
     * * The cross compiler is linked against the C runtime
         (``libc.so``). That file is contained in the *sysroot*.
       * 
       * n
     * * The output that is produced by a cross toolchain runs on the
         target machine.
       * y
       * 
     * * The output that is produced by a cross toolchain is linked
         against the C runtime (``libc.so``). That file is contained
         in the *sysroot*.
       * y
       * 
