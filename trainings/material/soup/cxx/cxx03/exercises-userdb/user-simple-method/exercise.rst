.. include:: <mmlalias.txt>


Exercise: Simple Method (Users Age By ``n`` Years)
==================================================

.. contents::
   :local:

Description
-----------

Objects of type ``class User`` are initialized once in their lifetime,

.. code-block:: c++
		
   User joerg("Joerg", "Faschingbauer", 55);

Currently, there is no way to celebrate birthdays, for example. User
``joerg`` remains 55 years old, indefinitely. While this is not a bad
idea in general, lets implement a way to let users age. Like so,

.. literalinclude:: user-aging.cpp
   :caption: :download:`user-aging.cpp`

Essentially: add to ``class User`` a method, ``void
age_by_n_years(unsigned int);``
