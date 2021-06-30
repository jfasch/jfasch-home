.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.exceptions.basics
   :dependencies: cxx03.functions_and_methods.operators


Basics
======

Error Handling: ``if`` - ``else if`` - ``else``
-----------------------------------------------

.. list-table::
   :header-rows: 1

   * * Traditional Error Handling
     * My Wish ...
   * * .. code-block:: c++

          if (dothat())
              if (dothis())
                  if (dothose())
                      finally();
                  else
                      dammit();
              else
	          dammit();
          else 
              dammit();
     * .. code-block:: c++

          dothat();
          dothis();
          dothose();
          finally();
          // only if anything bad happens:
          dammit();
