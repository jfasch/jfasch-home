Topics to be Written
====================

.. contents::
   :local:

New Topics to Write
-------------------

* Python: classmethod, staticmethod, class members
* Python: more on exceptions (``finally``, ``else``)
* Python: ``exec()``

  * in dict
  * in class dict

* Python: modules and packages. There is one half hearted topic. Split
  and pimp:

  * Developer: elaborate on packages, namespace packages, ``__init__.py``,
    ``__all__``, etc.
  * User: ``import``, ``PYTHONPATH``, etc.

* C++: Exception Handling from a Goto Orgy Perspective

  Always under valgrind supervision, hack something that uses malloc()
  in a function that creates seomthing, and has an error path. cleanup
  in that path is not always obvious. It leads to severe code
  duplication orgies when you use an if then else
  
  .. code-block:: c
  
      void* f(int a, int b)
      {
          // return allocation of a*b, when an environment variable is set
          // to a filename (getenv(), fopen() -> allocation error, read
          // error). if set to something else, then return an error, but
          // only if a<b. or some bullshit like that; everyone gets the
          // point.
      
          // code gets unobvious at best, resource leaky and erroneous at
          // worst.
      
          // extract common code. hm. externalize in a function, end up
          // duplicating the error path in the external cleanup function,
          // sketch that. hm. goto is the clearest. hack that.
      
          // ach
      
          if (0) {
              // really bad error earliest. nothing jump to outest error
              // level.
              goto cleanup_stage1;
          }
      
          if (42) {
              // ach
          }
