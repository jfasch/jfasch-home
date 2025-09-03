.. include:: <mmlalias.txt>


``std::string``
===============

.. contents::
   :local:

.. sidebar:: Documentation

   * `std::string
     <https://en.cppreference.com/w/cpp/string/basic_string>`__

Initialization
--------------

.. sidebar:: Documentation

   * `std::string constructors
     <https://en.cppreference.com/w/cpp/string/basic_string/basic_string>`__

.. literalinclude:: code/initialization.cpp
   :caption: :download:`code/initialization.cpp`
   :language: c++

Convenient Operators: Addition, Comparison, And Such
----------------------------------------------------

.. sidebar:: Documentation

   * `operator+()
     <https://en.cppreference.com/w/cpp/string/basic_string/operator%2B>`__
   * `operator+=
     <https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D>`__
   * `operator==,!=,<,<=,>,>=,<=>
     <https://en.cppreference.com/w/cpp/string/basic_string/operator_cmp>`__

.. literalinclude:: code/addition.cpp
   :caption: :download:`code/addition.cpp`
   :language: c++

.. literalinclude:: code/comparison.cpp
   :caption: :download:`code/comparison.cpp`
   :language: c++

Conversion To Numbers: ``std::sto*()``
--------------------------------------

.. sidebar:: Documentation

   * `std::stoi(), std::stol(), std::stoll()
     <https://en.cppreference.com/w/cpp/string/basic_string/stol>`__
   * `std::stoul(), std::stoull()
     <https://en.cppreference.com/w/cpp/string/basic_string/stoul>`__
   * `std::stof(), std::stod(), std::stold()
     <https://en.cppreference.com/w/cpp/string/basic_string/stof>`__

.. sidebar:: See also

   * :doc:`/trainings/material/soup/c/020-types-operators-expressions/080-type-conversions/topic`

In namesapce ``std``, there exist several functions to convert strings
to numbers.

.. literalinclude:: code/convert_to_signed_integer.cpp
   :caption: :download:`code/convert_to_signed_integer.cpp`
   :language: c++

.. literalinclude:: code/convert_to_unsigned_integer.cpp
   :caption: :download:`code/convert_to_unsigned_integer.cpp`
   :language: c++

If the string does not contain what is expected, the conversion
functions throw an instance of ``std::invalid_argument``.

.. literalinclude:: code/convert_to_number_error.cpp
   :caption: :download:`code/convert_to_number_error.cpp`
   :language: c++

Conversion To String: ``std::to_string()``
------------------------------------------

.. sidebar:: Documentation

   * `std::to_string()
     <https://en.cppreference.com/w/cpp/string/basic_string/to_string>`__

In namespace ``std``, there exist several overloads to convert any
kind of numbers to a string.

.. code-block:: c++

   std::string to_string(int value);
   std::string to_string(long value);
   std::string to_string(long long value);
   std::string to_string(unsigned value);
   std::string to_string(unsigned long value);
   std::string to_string(unsigned long long value);
   std::string to_string(float value);
   std::string to_string(double value);
   std::string to_string(long double value);

.. literalinclude:: code/convert_from_something.cpp
   :caption: :download:`code/convert_from_something.cpp`
   :language: c++

Searching: ``s.find()``
-----------------------

.. sidebar:: Documentation

   * `std::string::find()
     <https://en.cppreference.com/w/cpp/string/basic_string/find>`__

.. literalinclude:: code/find.cpp
   :caption: :download:`code/find.cpp`
   :language: c++

Substrings: ``s.substr()``
--------------------------

.. sidebar:: Documentation

   * `std::string::substr()
     <https://en.cppreference.com/w/cpp/string/basic_string/substr>`__

.. literalinclude:: code/substr.cpp
   :caption: :download:`code/substr.cpp`
   :language: c++
