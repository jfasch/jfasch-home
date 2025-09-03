.. include:: <mmlalias.txt>


Formatting Library (``std::format()``, ``std::print()``)
========================================================

.. contents:: 
   :local:

.. sidebar:: Documentation

   * `Formatting library
     <https://en.cppreference.com/w/cpp/utility/format/spec.html>`__
   * `Standard format specification
     <https://en.cppreference.com/w/cpp/utility/format/spec.html>`__
   * `(Python) Format Specification Mini-Language
     <https://docs.python.org/3/library/string.html#formatspec>`__

Basics
------

.. literalinclude:: code/basics.cpp
   :caption: :download:`code/basics.cpp`
   :language: c++

Positional Arguments
--------------------

.. literalinclude:: code/positional.cpp
   :caption: :download:`code/positional.cpp`
   :language: c++

Not Consuming All Arguments Is Not An Error
-------------------------------------------

.. literalinclude:: code/not_consuming_all_args_is_not_an_error.cpp
   :caption: :download:`code/not_consuming_all_args_is_not_an_error.cpp`
   :language: c++

Escaping Curly Braces
---------------------

.. literalinclude:: code/escape_curly.cpp
   :caption: :download:`code/escape_curly.cpp`
   :language: c++

C-Style Escapes
---------------

.. literalinclude:: code/c_style_escapes.cpp
   :caption: :download:`code/c_style_escapes.cpp`
   :language: c++

Format String
-------------

``fill-and-align ﻿(optional) sign ﻿(optional) #(optional) 0(optional) width ﻿(optional) precision ﻿(optional) L(optional) type ﻿(optional)``

Fill And Align: Basics
----------------------

* Datatype statically deduced
* |longrightarrow| Type specific fill and align

.. literalinclude:: code/fill_and_align__datatype_deduced_from_parameter.cpp
   :caption: :download:`code/fill_and_align__datatype_deduced_from_parameter.cpp`
   :language: c++

Fill And Align: Explicit Datatype
---------------------------------

.. literalinclude:: code/fill_and_align__explicit_datatype.cpp
   :caption: :download:`code/fill_and_align__explicit_datatype.cpp`
   :language: c++

Sign
----

.. literalinclude:: code/sign.cpp
   :caption: :download:`code/sign.cpp`
   :language: c++

Hash: Integral Datatypes
------------------------

.. literalinclude:: code/hash_integral.cpp
   :caption: :download:`code/hash_integral.cpp`
   :language: c++

Unicode Support
---------------

Not there. See :doc:`../drafts/unicode/topic`.
