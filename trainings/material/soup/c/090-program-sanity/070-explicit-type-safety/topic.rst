.. include:: <mmlalias.txt>


Explict Type Safety
===================

Integer Types Are Ambiguous
---------------------------

**Using integers as parameters and return types obfuscates code**

* Conversions happen automatically, without any notice by the compiler
* Worse: their semantics is not always clear

  * ``size_t`` helps to a certain extent

* Even more worse:

  * Mixing integers with different semantics
  * Changing semantics |longrightarrow| *no* help by compiler

**Example:** error handling ...

Example: Ambiguous Error Schemes (1)
------------------------------------

**Returns a "signed size type": negative on error, size written
otherwise** (Unix tradition: waste half of the domain for an
occasional -1):

.. code-block:: c

   ssize_t send_frame(
     struct protocol_engine *eng,
     const struct frame *f);

**Always returns a valid sum:**

.. code-block:: c

   int sum(const int *begin, const int *end);

Example: Ambiguous Error Schemes (2)
------------------------------------

**Automatic Conversion Massacre**

.. code-block:: c

   unsigned int send_sum(
     struct protocol_engine *engine,
     const int *begin, const int *end)
   {
     struct frame f;
     int retval = sum(begin, end);
   
     f.type = INT32;
     f.v_int32 = retval;
     retval = send_frame(engine, &f);
   
     return retval;
   }

Example: Ambiguous Error Schemes (3)
------------------------------------

**What are we trying to accomplish?**

* ``int sum()``: ok; sum of integers is an integer

  * Should think of overflow (gosh)

* ``ssize_t send_frame()``: ok, but uses weird Unix style error
  reporting.
* ``unsigned int send_sum()``: combines these in a spectacular way,
  and returns an application defined error number (0 for ok).

Imagine for a moment that there is one programmer who is able to code
such crap ...

* Compiler happily converts between all these different integer types
* |longrightarrow| Hell will break loose sooner or later

Artificial Integer Type Safety
------------------------------

**Passing** ``struct`` **By-Value**

.. code-block:: c

   struct point
   {
     int x, y;
   };
   struct point addpoints(struct point lhs, struct point rhs);

``struct`` assignment only possible on *equally* typed values

* Mixing impossible
* Why not wrap our integer error codes in ``struct`` s of adequate
  type?

Error Schemes, Revisited
------------------------

**What was our problem?**

* Unix system calls have that weird "-1 on failure, examine global
  ``errno`` variable if so" scheme

  * Valid ``errno`` errors are always > 0

* Application-defined ``unsigned int`` errors otherwise
* Mixing is prevented only by coding *very* carefully

**Proposed solution**: two dedicated error types ...

* ``struct unix_error``, encapsulating a Unix error
* ``struct app_error``, encapsulating the application's own error
  values

Error Schemes: Encapsulating Unix Details
-----------------------------------------

**Sketch: Definition of** ``unix_error``

.. code-block:: c

   struct unix_error
   {
       int errno;
   };
   static inline struct unix_error unix_error_create(int errno)
   {
       struct unix_error e;
       e.errno = errno;
       return e;
   }
   static inline int unix_error_ok(struct unix_error e)
   {
       return e.errno == 0;
   }

Error Schemes: Using Encapsulated Stuff
---------------------------------------

**Sketch: Usage of Type Safe Errors**

.. code-block:: c

   struct app_error send_sum(
     struct protocol_engine *engine,
     const int *begin, const int *end)
   {
     struct unix_error uerr;
     ...
     uerr = send_frame(engine, &f);
     if (!unix_error_ok(uerr))
         return app_error_create(APP_OS_ERROR);
     ...
   }

Wrap-Up: Artificial Type Safety
-------------------------------

**Good news:**

* It is possible to write entirely type safe code in C
* Using the right measures (inlining, small structs), no performance
  impact
* Greatly enhances maintainability

**Bad news:**

* A lot of explicit typing
* C++ can do the same with overloading and much less typing
