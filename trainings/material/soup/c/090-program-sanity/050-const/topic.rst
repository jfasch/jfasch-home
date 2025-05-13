.. include:: <mmlalias.txt>


Correctness - ``const``
=======================

Non-Modifiable Memory (1)
-------------------------

**Did you know the difference?**

.. code-block:: c

   void f(void)
   {
       char str[] = "blah";
       str[0] = 'x';
   }

.. code-block:: c

   void f(void)
   {
       char *str = "blah";
       str[0] = 'x';
   }

Non-Modifiable Memory (2)
-------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          char str[] = "blah";

       .. image:: 91-05-00-sanity-const-memory-stack.dia

       * Array initialization
       * Allocated on the *stack*, at *runtime*
       * |longrightarrow| *writable*

     * .. code-block:: c

          char *str = "blah";

       .. image:: 91-05-00-sanity-const-memory-rodata.dia

       * Allocated in *read-only memory*, at *compilation time*
       * Pointer setup *at runtime*, to point there
       * |longrightarrow| *not writable*

The ``const`` Keyword (1)
-------------------------

So there is already the concept of read-only data ...

* Sadly compilers generally issue no warnings
* (On Linux) Not an error, only on-demand duplication of a *shared* read-only memory page
* |longrightarrow| *expensive*
* Unintended in most cases

.. code-block:: console

   $ gcc -Wwrite-strings ...
   warning: initialization discards ‘const’ qualifier from 
      pointer target type

**A-ha:** "const" qualifier!

The ``const`` Keyword (2)
-------------------------

.. code-block:: console

   warning: initialization discards ‘const’ qualifier from 
      pointer target type

* ``char *str = "blah";``
* Obviously (no surprise) the compiler knows that ``"blah"`` is in
  read-only memory
* |longrightarrow| String literals are ``const char *``

.. code-block:: c

   const char *str = "blah";

**Consequences:**

* ``str`` cannot be written to
* |longrightarrow| Code has to be fixed until compiler is happy
* |longrightarrow| *Correctness* with minimal effort

``const`` Variables
-------------------

Getting rid of the preprocessor (good idea) ...

.. code-block:: c

   const int MAX_BUCKETS = 64;

... is the same, compiler-wise, as ...

.. code-block:: c

   #define MAX_BUCKETS 64

**Additional benefits ...**

* ``MAX_BUCKETS`` has a type
* Not a stupid string substitution, but a regular C identifier
* "unused" warnings

``const`` Parameters (1)
------------------------

.. code-block:: c

   int sum(int *begin, int *end);

**Reading this declaration, we assume the following:**

* It builds a ``sum``
* It returns the result
* It operates on a range ``[begin, end)``
* It does not modify the input data
  
**Ambiguity alert:**

* We can say nothing of the above for sure
* ... but we can help with the last item

``const`` Parameters (2)
------------------------

.. code-block:: c

   int sum(const int *begin, const int *end);

**Now we can say one thing for sure:**

* It does not modify the input data
  
**Consequences:**

* ``sum()`` has to modified
* Not a big deal when only a few lines involved
* Can be a problem when code is large and complex
* |longrightarrow| "``const`` pollution"

Pointers, Pointers, Pointers ... (1)
------------------------------------

**What's known so far:**

* ``const`` can be applied to scalar types
* ``const`` can be applied to ``struct`` types (we don't know this,
  but it's a logical consequence)
* ``const``, applied to pointers, keeps me from modifying what they point to

.. code-block:: c

   const int i;
   int const j; /* same! */
   const int *pi = &i;
   int const *pj = &j;

.. image:: 91-05-00-sanity-const--c-p-nc.dia

Pointers, Pointers, Pointers ... (2)
------------------------------------

**Mixing ...**

.. code-block:: c

   int const i = 42;
   int *pi = &i;

.. code-block:: console

   warning: initialization discards ‘const’ qualifier 
     from pointer target type

* ``pi`` does not promise to *not modify* the value it points to
* Pointee is *read-only*
* Sadly this can only be a warning for historical reasons

Pointers, Pointers, Pointers ... (3)
------------------------------------

**So, given that ...**

.. code-block:: c

   int const i;

... is a read-only variable, ...

.. code-block:: c

   int * const pi;

... is a read-only variable:

* A pointer that cannot be modified
* But can be used to modify what it points to (it's an ``int``, not an
  ``int const``)

Pointers, Pointers, Pointers ... (4)
------------------------------------

.. code-block:: c

   int * const pi;
   /* error: assignment of read-only variable ‘pi’ */
   pi = NULL;
   /* ok, compiles */
   *pi = 42;

.. image:: 91-05-00-sanity-const--nc-p-c.dia

**But is this correct?**

Pointers, Pointers, Pointers ... (5)
------------------------------------

**So what's this?**

.. code-block:: c

   int i = 42
   int const * const pi = &i;
   
   /* error: assignment of read-only variable ‘pi’ */
   pi = NULL;
   
   /* error: assignment of read-only location ‘*pi’ */
   *pi = 42;

.. image:: 91-05-00-sanity-const--c-p-c.dia

Pointers, Pointers, Pointers ... (6)
------------------------------------

**How about pointers that point to pointers?**

.. code-block:: c

   int i = 42;
   int *pi = &i;
   int **ppi = &pi;
   
   **ppi = 7;
   *ppi = NULL;

.. image:: 91-05-00-sanity-const--nc-p-nc-p-nc.dia

Pointers, Pointers, Pointers ... (7)
------------------------------------

**How about pointers that point to pointers that point to**
``const``}? **(Gosh)**

.. code-block:: c

   int const i = 42;
   int const *pi = &i;
   int const **ppi = &pi;
   
   ppi = NULL;
   *ppi = NULL;
   /* error: assignment of read-only location ‘**ppi’ */
   **ppi = 7;

.. image:: 91-05-00-sanity-const--pppppp.dia

Pointers, Pointers, Pointers ... (8)
------------------------------------

**How about pointers that point to non-modifiable pointers that point
to** ``const`` **?**

.. code-block:: c

   int const i = 42;
   int const * const pi = &i;
   int const * const *ppi = &pi;
   
   ppi = NULL;
   /* error: assignment of read-only location ‘*ppi’ */
   *ppi = NULL;
   /* error: assignment of read-only location ‘**ppi’ */
   **ppi = 7;

.. image:: 91-05-00-sanity-const--ppppppccccppppp.dia

Pointers, Pointers, Pointers ... (9)
------------------------------------

**How about ...?** (To be continued)
