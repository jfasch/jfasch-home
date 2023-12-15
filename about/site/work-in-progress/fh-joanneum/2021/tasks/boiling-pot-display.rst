.. include:: <mmlalias.txt>

.. ot-task:: fh2021.boiling_pot_display
   :dependencies: fh2021.boiling_pot, fh2021.display_infrastructure


Boiling Pot: Display, And Status Reporting
==========================================

.. sidebar::

   **See also**

   * :doc:`boiling-pot``

.. contents::
   :local:

Standup Records
---------------

Requirements
------------

``BoilingPot`` clearly needs a temperature display and a status
reporting interface.

Make the following test cases work (both from `boiling-pot-test.cpp
<https://github.com/jfasch/FH-ECE21/blob/main/tests/boiling-pot-test.cpp>`__

* ``BoilingPot_suite.status_report``
* ``BoilingPot_suite.percentage_display``

Dependencies
------------

.. ot-graph::
   :entries: fh2021.boiling_pot_display
