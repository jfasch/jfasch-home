.. include:: <mmlalias.txt>


``std::variant`` (Manual Virtual Dispatch, Using ``if``)
========================================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/miscellaneous/any-variant-optional/variant`

.. contents::
   :local:

Overview
--------

* Take ``union`` approach from :doc:`unrelated` further
* |longrightarrow| store not only pointers, but objects
* *Manual* virtual dispatch (see
  :download:`code/variant-manual-if/virtual.h`) based on
  ``std::variant<>`` examination (``if``)
* |longrightarrow| *Adding another sensor type requires another branch
  in* ``if``

Sensor Definitions
------------------

.. literalinclude:: code/variant-manual-if/sensors.h
   :caption: :download:`code/variant-manual-if/sensors.h`
   :language: c++

Virtual Access
--------------

.. literalinclude:: code/variant-manual-if/virtual.h
   :caption: :download:`code/variant-manual-if/virtual.h`
   :language: c++

Average Across Many
-------------------

.. literalinclude:: code/variant-manual-if/avg.h
   :caption: :download:`code/variant-manual-if/avg.h`
   :language: c++

Main Program
------------

.. literalinclude:: code/variant-manual-if/main.cpp
   :caption: :download:`code/variant-manual-if/main.cpp`
   :language: c++
