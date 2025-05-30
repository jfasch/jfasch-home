.. include:: <mmlalias.txt>


Exercise (FH): Extract Measurement Loop Into Function
=====================================================

.. contents::
   :local:

Requirement
-----------

#. Extract the measurement loop into a parameterizable function:

   .. code-block:: c++

      static void loop_and_measure(unsigned interval, int niterations, W1Sensor& sensor)
      {
          .. measurement loop here ...
      }

   That function is defined in the same file as the ``main()``
   function, which is why we can restrict its visibility to the file
   itself and use ``static``.

#. Call the function at the point in the ``main()`` function where you
   extracted the loop from
