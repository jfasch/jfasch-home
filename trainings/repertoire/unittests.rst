Unittesting, Test Driven Development
====================================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 2 Tage
      PDF Slides, :download:`Test Driven Development </trainings/material/pdf/060-design-patterns-unittests.pdf>`

**Unittesting**: das Prinzip kann einfacher nicht sein. Statt per Hand
zu testen, schreibt man ein Programm, dass einem das auf Knopfdruck
abnimmt - oder verwendet eines der zahlreichen
Unittest-Frameworks. Jede Änderung an der Software wird automatisch
abgeklopft. Man verliert die Angst, etwas zu ändern, die daher kommt,
dass man nicht weiss, was man alles kaputtmachen könnte.

Warum machen das nicht alle?

Das ist eine Frage, die nicht so ohne weiteres zu beantworten
ist. Konstruktiver ist es, die Einfachheit des Prinzips klarzumachen
und umzusetzen - sodass es jede/r einmal gemacht hat. Man kann dann
selbst entscheiden, ob man es will oder nicht.

**Test Driven Development**: anstatt vorhandenen Code mit Unittests
auszustatten, schreibt man zuerst den Test und dann den Code
dazu. Effekt: man macht sich Gedanken, was man will, bevor man
überhaupt zu programmieren beginnt - und hat automatisch die ersten
paar Unittests.

Hat man den Wert dieses Vorgehens einmal erkannt, will man nicht mehr
ohne. Dass man nicht mehr ohne macht, ist allerdings eine wichtige
Entscheidung: wenn Unittests zur Last werden, hat man es verbockt.

Zielpublikum
------------

* Softwareentwickler jedweder Branche, die einfach nur stabilen Code
  abliefern möchten.
* Entscheidungsträger und/oder Vorgesetzte, die schlüssige Kanäle
  zwischen Requirements Engineering und Coding etablieren möchten.

Kursinhalt
----------

**Terminologie**. Jedes Unittestframework implementiert in der einen
oder anderen Weise Mechanismen, die *Namen* tragen. Namen sind
wichtig, denn ohne sie ist Kommunikation sehr schwerfällig. Beispiele:
*Test Suite*, *Fixture*, *Test Runner*.

Der Rest des Kurses hat Workshopcharakter - das Prinzip ist in der
ersten halben Stunde erklärt. Alles übrige ist, sich im
Unittestframework seiner Wahl zurechtzufinden und, was wichtiger ist,
die Tests nicht zur Last werden zu lassen.

Der Vortragende kann aufgrund seiner Herkunft mit folgendem aufwarten:

* `Boost.Test (C++)
  <https://www.boost.org/doc/libs/1_72_0/libs/test/doc/html/index.html>`__
* `Google Test (C++) <https://github.com/google/googletest>`__
* `Python's unittest Modul
  <https://docs.python.org/3.7/library/unittest.html>`__

Der Inhalt des Kurses ist aber die Sache, nicht die Sprache. Ich kann
den Teilnehmern nicht Java oder C# beibringen (beide mit üppigen
Unittestframeworks ausgestattet), aber die Einfachheit des Prinzips
wird sich wohl auch dort nicht verbergen.

Empfohlene Vorkenntnisse
------------------------

Etwas Programmiererfahrung in der präferierten Sprache. (C++ und
Python können vom Vortragenden unterstützt werden.)
