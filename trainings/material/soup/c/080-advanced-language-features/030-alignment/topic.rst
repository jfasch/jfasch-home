.. include:: <mmlalias.txt>

.. ot-topic:: c.advanced_language_features.alignment
   :dependencies: c.advanced_language_features.atomic


Alignment
=========

.. http://en.wikipedia.org/wiki/Data_structure_alignment
..
.. The compiled size of the structure is now 12 bytes. It is important
.. to note that the last member is padded with the number of bytes
.. required so that the total size of the structure should be a
.. multiple of the largest alignment of any structure member
.. (alignment(int) in this case, which = 4 on linux-32bit/gcc)[citation
.. needed].
..
..
.. http://www.ibm.com/developerworks/library/pa-dalign/
..
.. http://www.makelinux.net/books/lkd2/ch19lev1sec3

Data Alignment
--------------

**Data alignment:** processors like data items of size N (a
power of two) to exist at base addresses that are a multiple of N

|longrightarrow| **"Natural alignment"**

* A character can exist at any address (no alignment restriction)
* A 16 bit integer (``short`` on most/all architectures) must align to
  a 2 byte boundary
* Same with 32 bit and 64 bit integers, ``float`` and ``double``
* Pointers on a 32 bit architecture must align to a 4 byte boundary
* Pointers on a 64 bit architecture must align to a 8 byte boundary

.. image:: 90-03-00-alignment-data-ok.dia

Data Alignment, Compilers
-------------------------

* Compilers generally know about a machine's data sizes and alignment
  requirements
* Variables are placed at addresses that align them naturally
* Not normally a problem during development
* Except ...

  * Mixing 32 bit and 64 bit code (e.g. running a 32 bit executable on
    a 64 bit OS) |longrightarrow| *different pointer sizes*, at least
  * Reading and interpreting binary data from *somewhere*

Unaligned Data Access (1)
-------------------------

.. image:: 90-03-00-alignment-data-unaligned.dia

* Split in two memory accesses, combined by arithmetic (shift, bitwise OR)
* Architecture dependent

  * Done in hardware
  * Trap into OS, emulation in software

* Either way: non-negligible performance penalty
* |longrightarrow| Play by the rules and just don't do it

**How can I produce an unaligned access?**

Unaligned Data Access (2)
-------------------------

* The following code is not clean
* Works only because all is done to make unaligned access work

.. code-block:: c

   char dog[10];
   char *p = &dog[1];
   unsigned long l = *(unsigned long *)p;

* Future proof (but no faster) ...

.. code-block:: c

   char dog[10];
   unsigned long l;
   memcpy(&l, dog+1, sizeof(unsigned long));

Padding (1)
-----------

**What happens to structure members?**
  
* No standalone variables which are freely allocated by the compiler
* Compiler is forbidden (per C/C++ standard) to rearrange members of a
  ``struct``

.. code-block:: c
  
   struct animals {
     char dog;             /* 1 byte */
     unsigned long cat;    /* 8 bytes */
     unsigned short pig;   /* 2 bytes */
     char fox;             /* 1 byte */
   };

**How large would this be?** ``1+8+2+1 == 12``?

Padding (2)
-----------

.. code-block: c

   struct animals {
     char dog;             /* 1 byte */
     unsigned long cat;    /* 8 bytes */
     unsigned short pig;   /* 2 bytes */
     char fox;             /* 1 byte */
   };

.. image:: 90-03-00-alignment-struct-no-padding.dia

* Quite naive structure layout: \alert{no compiler does this!}
* Can be enforced by compiler specific structure attributes (GCC) or pragmas (Doze) $\to$ \textit{Bogus!}

Padding (3)
-----------

**Compiler inserts padding**

* Preserves order of members (dictated by law)
* Artificially guarantees aligned access

.. code-block:: c

   struct animals {
     char dog;             /* 1 byte */
     char __pad0[7];       /* 7 bytes */
     unsigned long cat;    /* 8 bytes */
     unsigned short pig;   /* 2 bytes */
     char fox;             /* 1 byte */
     char __pad1[5];       /* 5 bytes (?) */
   };

.. image:: 90-03-00-alignment-struct-padding.dia

Padding (4)
-----------

* **Bloat** in size
* |longrightarrow| Rearrange members manually, ordered by decreasing
  size/alignment

.. code-block:: c

   struct animals {
     unsigned long cat;    /* 8 bytes */
     unsigned short pig;   /* 2 bytes */
     char dog;             /* 1 byte */
     char fox;             /* 1 byte */
   };

.. image:: 90-03-00-alignment-struct-padding-rearranged.dia

Structure Alignment (1)
-----------------------

**What is the alignment of a structure?**

* Padding is applied inside a structure, to meet alignment
  requirements of all members
* On what addresses can a structure exist, then?
* |longrightarrow| On all addresses where the member with the largest
  alignment can exist
* **Rule:** *The alignment of a structure is the alignment of the
  largest included type.*
* **Corollary:** *The alignment of a union is the alignment of the
  largest included type*

Structure Alignment (2)
-----------------------

**Remember?**

.. image:: 90-03-00-alignment-struct-padding.dia

* Largest member is ``cat``, 8 bytes |longrightarrow| structure's
  alignment is 8
* If we place the entire structure at address 8, ``cat`` is at 16 -
  which aligns it correctly

**So, remember:**

* **The alignment of a structure is the alignment of the largest
  included type.**
* **The alignment of a union is the alignment of the largest included
  type.**

And Arrays? (1)
---------------

**Correctly Aligned**

.. image:: 90-03-00-alignment-struct-padding.dia

* There is a padding of 5 bytes at the end of the structure
* If we omit it, the alignment is not changed - only the structure
  becomes smaller in size (19 bytes, which is not only odd but prime)

**Bogus, no padding at end**

.. image:: 90-03-00-alignment-struct-padding-no-endpad-array.dia

And Arrays? (2)
---------------

**Prime-Aligned Structure**

.. image:: 90-03-00-alignment-struct-padding-no-endpad-array.dia

* This structure is clearly not suited for arrays
* Nearly all members of the second array element would be misaligned
* Would it suffice to end-pad the structure so its entire size is a
  multiple of 4?

And Arrays? (3)
---------------

* Would it suffice to end-pad the structure so its entire size is a
  multiple of 4 (and not 8)?
* |longrightarrow| No: the ``cat`` member of the second array element
  would then be misaligned

**So, remember:**

* **The size of a structure is a multiple of the alignment of the
  largest included type.**
* **The alignment of an array is the alignment of its base type.**
