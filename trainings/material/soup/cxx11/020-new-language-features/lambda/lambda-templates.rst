.. ot-topic:: cxx11.new_language_features.lambda.lambda_templates

.. include:: <mmlalias.txt>


Lambda And Templates
====================

.. contents::
   :local:

Generic Lambda (``auto`` Parameters)
------------------------------------

* ``auto`` is cool! One wouldn't expect how simple templates could be!

.. literalinclude:: code/generic-lambda.cpp
   :caption: :download:`code/generic-lambda.cpp`
   :language: c++

* *Abbreviated function templates*: the same, but with regular
  function templates instead (no lambda)

.. literalinclude:: code/abbreviated-function-template.cpp
   :caption: :download:`code/abbreviated-function-template.cpp`
   :language: c++

Template Lambda (C++20)
-----------------------

* Re-unification: generic lambda vs. template lambda

.. literalinclude:: code/template-lambda.cpp
   :caption: :download:`code/template-lambda.cpp`
   :language: c++
