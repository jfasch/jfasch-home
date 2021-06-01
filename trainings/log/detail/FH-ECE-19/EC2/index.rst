Embedded Computing 2 (ECE 19)
=============================

.. contents::
   :local:

Group Project
-------------

**Topics**

.. figure:: ../EC1/Bullshit-Bingo-G2.jpg

**Random Ideas**

* MQTT for debug messages and status reports.

  Background: Christan Vogel thinking about how to watch a uC car
  (that from *Embedded Systems*) drive, internally. Students running
  side by side a car and watching what's on the display does not scale
  so well.

  Good opportunity to look into 

  * how debugging could be done in a real-world
    application. (``stderr`` first.)
  * how ``stderr`` could be replaced with MQTT client.
  * how the Python ``logging`` module is used. MQTT log sink.
