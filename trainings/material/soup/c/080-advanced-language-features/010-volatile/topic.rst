.. include:: <mmlalias.txt>


Volatile
========

.. contents::
   :local:

Links
-----

* `Compiler Optimizations
  <http://compileroptimizations.com/category/volatile.htm>`__
* `Stackoverflow: Why is volatile needed in C? <http://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c>`__
* `Linux Kernel Documentation: Why the “volatile” type class should
  not be used
  <https://www.kernel.org/doc/html/latest/process/volatile-considered-harmful.html>`__

``volatile``: The Lie (1)
-------------------------

**What** ``volatile`` **does**:
  
* Prevents *compiler* optimization of everything involving the
  variable declared ``volatile``
* Corollary: the variable must not be kept in a register

.. code-block:: c

   volatile int x;

**Attention:**

* All it does is provide a false impression of correctness
* *Most of its uses are outright bugs*

``volatile``: The Lie (2)
-------------------------

**What** ``volatile`` **doesn't:**

* Variable can still be in a cache

  * *Variable is not at all sync with memory* when using *write-back*
    cache strategy

* Not a memory barrier |longrightarrow| load/store reordering still
  possible (done by CPU, *not by compiler*)
* |longrightarrow| *Not a replacement for proper locking*

**Still broken:** *load-modify-store*

.. code-block:: c

   volatile int use_count;
   
   void use_resource(void)
   {
     do_something_with_shared_resource();
     use_count++;
   }

``volatile``: Valid Use: Hardware
---------------------------------

**Originally conceived for use with hardware registers**
  
* Optimizing compiler would wreak havoc

  * Loops would never terminate
  * Memory locations would not be written to/read from
  * ...

.. code-block:: c

   volatile int completion_flag;
   volatile int out_word;
   volatile int in_word;
   
   int communicate(int word)
   {
       out_word = word;
       while (!completion_flag);
       return in_word;
   }

``volatile``: Valid Use: Unix Signal Handlers
---------------------------------------------

**A variable might change in unforeseeable ways**

* Signal handler modifies ``quit`` variable
* Optimizing compiler would otherwise make the loop infinite

.. code-block:: c
  
   volatile int quit;
   
   int main(void)
   {
     while (!quit)
       do_something();
   }
