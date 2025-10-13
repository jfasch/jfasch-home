.. include:: <mmlalias.txt>


Exercise: MQTT: Publish User Records
====================================

Requirement
-----------

Write a program ``mqtt-pub-users-csv-noheader.py`` that

* Takes a *no-header* style CSV file as input
* Reads users from it (use the routine we created in
  :doc:`userdb_csv`)
* Publishes these users to an MQTT broker

The program is supposed to be run like follows,

.. code-block:: console

   $ ./mqtt-pub-users-csv-noheader.py      # want usage message if wrong number of parameters given
     Usage: ./mqtt-pub-users-csv-noheader.py CSVFILENAME BROKER TOPIC
   $ ./mqtt-pub-users-csv-noheader.py Users-noheader-cp1252.csv test.mosquitto.org my-users-topic
