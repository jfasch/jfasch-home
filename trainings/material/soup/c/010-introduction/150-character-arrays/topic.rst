.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.character_arrays
   :dependencies: c.introduction.exercise_power_declaration


Character Arrays
================

Strings: Mistake by Design?
---------------------------

* Only what is necessary is built-in in C
* From today's point of view C is *the* language for hardware-oriented
  programming
* Invented to keep UNIX portable, independent from PDP-11 assembler
* |longrightarrow| C itself is the language core - everything else
  belongs in *libraries*

**Contradiction:**

* Language core knows what string literals are
* 7-bit ASCII sufficed at that time |longrightarrow| no multibyte
  character sets, no need for Unicode
* *But*: much later somebody claimed that "640K is enough"

Strings: Definition
-------------------

**String**

* Array of characters ...
* ... terminated by a "null" character (``'\0'``)

.. list-table::
   :align: left

   * * .. code-block:: c

          char a_string[] = "hello";

     * 

       .. image:: 01-09-string.dia

Strings: Library Functions
--------------------------

**Functions** from the *standard library*

* ``strlen(const char[])``
* ``strcpy(char dest[], const char src[])``
* ``strncpy(char dest[], const char src[], int maxlen)``
* ``strcat(char dest[], const char src[])``
* ``strncat(char dest[], char src[], int n)``
* ``strcmp(const char lhs[], const char rhs[])``
* ``strncmp(const char lhs[], const char rhs[], int maxlen)``

Many more |longrightarrow| see `manual page
<https://man7.org/linux/man-pages/man3/string.3.html>`__

Strings as Parameters
---------------------

* Strings (like *arrays* in general) are passed as *pointers*
* |longrightarrow| *Modifications visible to the caller*

.. list-table::
   :align: left

   * * .. code-block:: c

          char a_string[] = "hello";
          char another_string[10];
          ...
          copy(another_string, a_string);

     * 

       .. image:: 01-09-param-passing.dia

Strings: Dangers
----------------

**Low level definition leads to errors**
  
* Copy: not enough memory allocated to hold the copy
* Forget to null-terminate when composing strings by hand
* ... many many more ...

