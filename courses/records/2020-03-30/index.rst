C++ für Embedded C Programmierer (30.3.2020 - 3.4.2020 nahe Heilbronn) 
======================================================================

.. sidebar:: Material

   * :doc:`C Einührung (Schulungsbeschreibung)
     </courses/programming-languages/10-C>`
   * :doc:`C Advanced (Schulungsbeschreibung)
     </courses/programming-languages/15-C-Advanced>`
   * :doc:`C++ (Schulungsbeschreibung)
     </courses/programming-languages/20-CXX>`
   * :download:`C (PDF) </training-material/pdf/050-c.pdf>`
   * :download:`C++03 (PDF) </training-material/pdf/055-c++03.pdf>`
   * :download:`C++11 (PDF) </training-material/pdf/056-c++11.pdf>`
   * :download:`CMake </training-material/pdf/045-cmake.pdf>`

Plan (sich entwickelnd)
-----------------------

* Gleich zu Beginn: ctor, dtor am Beispiel Memoryleak. Live Hacking
  Session, introducing

  * class
  * ctor
  * *deterministic* dtor
  * "RAII"

* CMake im Vorbeigehen, sobald der angehäufte C++ Code zu gross wird.

  Vielleicht mit der Bemerkung, dass man überhaupt alles erst dann
  machen sollte, wenn mans braucht. Probates Mittel, um Angst vor
  Änderung (und Kaputtgehen) zu nehmen: Unittests.

* STL: Pointerarithmetik Wiederholung (Folien)

  * Range based for
  * ``auto``
  * Lambda
