.. ot-topic:: cxx11.embedded_problems.variant_manual_visit
   :dependencies: cxx11.embedded_problems.variant_manual_if

.. include:: <mmlalias.txt>


``std::variant`` (Manual Virtual Dispatch, Using ``std::visit``)
================================================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant`

.. contents::
   :local:

Overview
--------

* Much like :doc:`variant-manual-if`
* Only using ``std::visit()``
* ... with manually defined visitor methods
* |longrightarrow| *Adding another sensor type requires another*
  ``operator()``

Virtual Access
--------------

.. literalinclude:: code/variant-manual-visit/virtual.h
   :caption: :download:`code/variant-manual-visit/virtual.h`
   :language: c++

