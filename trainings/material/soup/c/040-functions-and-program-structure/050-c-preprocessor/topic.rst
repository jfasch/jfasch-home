.. include:: <mmlalias.txt>


C Preprocessor: Basics
======================

The C Preprocessor: *Why*!

**Dirty Hack!**

* Has nothing to do with the language itself
* Invented to quickly solve problems in an *ad hoc* manner -
  completely ignoring the language
* Brutal and stupid text replacement
* |longrightarrow| Please use cautiously!

.. contents::
   :local:

``#include``
------------

**Include the content of a file** at the point in the source file
where ``#include`` is written

**Two incarnations**, with a subtle difference

* ``#include "file.h"``: search first in the directory where the
  "includer" is, and then along the search path
* ``#include <file.h>``: searches only along the include path

**No rules**, but ...

* Header files contain declarations and macros
* Header files generally include header files: have to protect
  themselves against *multiple inclusion* |longrightarrow| *include
  guards*
* ``#include`` always comes near the beginning of a source file -
  *never inside*

Macros: Text Replacement
------------------------

**Macro**: definition of a *token* that is brutally replaced

.. code-block:: c

   #define forever for (;;)
   
   ...
       forever {
           sleep(1);
           printf("No way out!");
       }

Macros: Constant Definition
---------------------------

.. code-block:: c

   #define LOWER 0
   #define UPPER 300
   #define STEP 20
   
   for (i = LOWER; i < UPPER; i += STEP)
       ...

**Better**: C99 ``const`` keyword

.. code-block:: c

   const int LOWER = 0;

|longrightarrow| Typed *immutable* variable

Macros: Inline Replacement as *Function Call* (1)
-------------------------------------------------

**Original problem**
  
* Function calls are slow
* Parameter passing |longrightarrow| copy
* Return |longrightarrow| copy

.. code-block:: c

   #define max(a, b) (((a) > (b))? (a) : (b))
   ...
   x = max(1, 2);

|longrightarrow| Statement is *expanded* as if it were a function call

**But ...**

Macros: Inline Replacement as *Function Call* (2)
-------------------------------------------------

**Braces are necessary:**

.. code-block:: c

   /* #define max(a, b) (((a) > (b))? (a) : (b)) */
   #define max(a, b) ((a > b)? a : b)
   ...
   x = max(p+q, r+s);

*brutally* expands to ...

.. code-block:: c

   x = (p+q > r+s) ? p+q : r+s;

|longrightarrow| **Operator precedence massacre!**

Macros: Inline Replacement as *Function Call* (3)

**C99:** ``inline`` **keyword**

.. code-block:: c

   inline int max(int a, int b)
   {
       return (a > b)? a : b;
   }

**Drawback**: cannot use ``max()`` with different types

Macros: Inline Replacement as *Function Call* (4)

**One more thing**:

.. code-block:: c

   #define max(a, b) (((a) > (b))? (a) : (b))
   ...
   x = max(i++, j++);

*brutally* expands to ...

.. code-block:: c

   x = ((i++) > (j++)) ? (i++) : (j++);

|longrightarrow| **Parameters are evaluated more than once!**

*Include Guards* (1)
--------------------

.. code-block:: c
   :caption: ``a.h``

   #include "c.h"

.. code-block:: c
   :caption: ``b.h``

   #include "c.h"
  
.. code-block:: c
   :caption: ``c.h``

   extern int g_lobal;

.. code-block:: c
   :caption: ``main.h``

   #include "a.h"
   #include "b.h"

|longrightarrow| **Error:** multiple declaration of ``g_lobal``

*Include Guards* (2)
--------------------

**Solution**: define a "guard" macro *by hand* (!)

.. code-block:: c

   #ifndef HAVE_C_H
   #define HAVE_C_H
   
   extern int g_lobal;

   #endif

**OMG!**

* *By hand* - after all, it's got nothing to do with C
* |longrightarrow| Bugs/errors are the logical consequence (e.g. guard
  macro clashes)
* |longrightarrow| GCC Extension: ``#include_once``

The C Preprocessor: Last Words
------------------------------

* C is low-level but not stupid
* *The C preprocessor is stupid*
* C programmers can take it
* Newbies not
* Unnecessary hurdle
* |longrightarrow| *Stupid!*

