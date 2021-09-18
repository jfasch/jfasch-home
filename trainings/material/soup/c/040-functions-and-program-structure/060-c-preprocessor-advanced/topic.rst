.. include:: <mmlalias.txt>

.. ot-topic:: c.functions_and_program_structure.c_preprocessor_advanced
   :dependencies: c.functions_and_program_structure.c_preprocessor


C Preprocessor: More
====================

Conditional Compilation: Rules
------------------------------

**Directives**

.. list-table::
   :align: left
   :header-rows: 1

   * * Directive
     * Meaning
   * * ``#if``
     * Preprocessor condition (simple arithmetic, at most)
   * * ``#ifdef``
     * Definedness of a macro (regardless of its value)
   * * ``#ifndef``
     * Not-definedness of a macro
   * * ``#else``
     * (no comment)
   * * ``#elif``
     * as opposed to C's ``else if``
   * * ``#endif``
     * (no comment)
  
*Operators for use with** ``if`` **and** ``elif``

.. list-table::
   :align: left
   :header-rows: 1

   * * Operator
     * Meaning
   * * ``defined``
     * Definedness of a macro
   * * ``!``
     * Boolean NOT
   * * ``&&``
     * Boolean AND
   * * ``||``
     * Boolean OR
   * * ``==``
     * Equal
   * * ``!=``
     * Unequal

Conditional Compilation: Examples
---------------------------------

**Commenting out lines**

.. code-block:: c

   #if 0 /* argh, there's a bug somewhere */
        int i;
        for (i=0; i<2; i--)
            do_something();
   #else
        do_something();
        do_something();
   #endif

**Multiple Conditions Combined**

.. code-block:: c

   #if defined DEBUG && NUMBER == 3
       fprintf(stderr, "NUMBER equals 3\n");
   #endif

Conditional Compilation: Last Words
-----------------------------------

**Conditional compilation ...**

* Doesn't make code more readable
* Begs for errors
* Is quite tempting to use in a hurry

**Typical uses**
  
* Same code on multiple OS's

  * Better to extract OS-specific concepts
  * Define clear separation between OS independent and OS dependent
    code
  * Avoid inline ``#ifdef``'s (maintenance horror)

* "Release" and "Debug" versions of the same code base

  * Again: avoid inline ``#ifdef``'s
  * Define macros that expand appropriately

Macros: Spanning Multiple Lines
-------------------------------

**Macro definition can only span one line** |longrightarrow| line
continuation

**(Extremely Nonsensical) Multiline Macro**

.. code-block:: c

   #define forever(body) \
       for (;;) { \
           body; \
       }
   
   ...
   int x = 1;
   forever(printf("%d\n", x); ++x;);
   ...

Macros: Multiple Statements as One Statement (1)
------------------------------------------------

**A Block Is Not a Statement**

.. code-block:: c

   #define do_much() \
       { \
           do_this(); \
           do_that(); \
       }
   
   ...
   if (42)
       do_much(); /* ERROR! */
   else
       do_less();

Macros: Multiple Statements as One Statement (2)
------------------------------------------------

Employ a little trick ...

**Making A Block Into A Statement**

.. code-block:: c

   #define do_much() \
       do { \
           do_this(); \
           do_that(); \
       } while (0)

**Silence Warnings of Microsoft's C Implementation**

.. code-block:: c

   __pragma(warning(push))
   __pragma(warning(disable:4127))
   ...
   __pragma(warning(pop))

Stringification (1)
-------------------

**Commmon problem**: output a C expression

**Macro Usage in Code**

.. code-block:: c

   ...
   WARN_IF(i>10);
   ...
  
Should yield on ``stderr``

**Appearance on** ``stderr``

.. code-block:: console

   WARNING: i>10

Stringification (2)
-------------------

**Solution**: *Stringification*

.. code-block:: c

   #define WARN_IF(expr) \
       do { \
           if (expr) \
               fprintf(stderr, "WARNING: " #expr "\n"); \
       } while (0)

Macro argument is used twice ...
  
* evaluated as C in the ``if`` statemant
* converted into a C string using ``#``

Token Pasting (1)
-----------------

**Common Problem**: construct C identifiers from macro parameters

**Redundant Code**

.. code-block:: c

   struct command
   {
       char *name;
       void (*function) (void);
   };
   
   struct command commands[] =
   {
       { "help", function_help },
       { "quit", function_quit }
   };

Token Pasting (2)
-----------------

**Solution**: *Token Pasting*

.. code-block:: c

   #define COMMAND(name) { #name, function_ ## name }
   
   struct command commands[] =
   {
       COMMAND(help),
       COMMAND(quit)
   };

Warnings and Errors
-------------------

.. code-block:: c

   void inject_virus(HANDLE doomed_process)
   {
   #ifdef WIN32
       void *foreign_mem = VirtualAllocEx(
           doomed_process,
           0,
           8192,
           MEM_COMMIT,
           PAGE_EXECUTE|PAGE_READWRITE);
       ...
   #else
   #   error cannot infect foreign processes
   #endif
   }

Predefined Macros (1)
---------------------

.. list-table::
   :align: left
   :header-rows: 1

   * * Macro
     * Meaning
   * * ``__FILE__``
     * Name of current input file (C string)
   * * ``__LINE__``
     * Current line current input file (integer)

.. code-block:: c

   #define WARN_IF(expr) \
       do { \
           if (expr) \
               fprintf(stderr, "%s:%d: WARNING: " #expr "\n", \
                   __FILE__, __LINE__); \
       } while (0)

* Gives the position where ``WARN_IF`` was expanded, *not* where
  ``WARN_IF`` was defined

The C Preprocessor: Last Words
------------------------------

**Always think twice!** First thought is likely wrong.

* Inline preprocessorisms *pollute code*
* Code should be kept readable and obvious
* Push down preprocessorisms into (architecture) specific places

  * Well defined *selection macros*
  * Forwarding-Headers
  * Common abstractions

.. attention::

   * Refactor immediately when smell detected!
   * It is like the pest!
