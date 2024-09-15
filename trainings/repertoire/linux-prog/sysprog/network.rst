Linux Systems Programming: Network Programming
==============================================

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 2 days
      * * **Language**
	* Trainer language is English or German
      * * **Material**
	* * PDF Slides, :download:`sysprog </trainings/material/pdf/020-linux-sysprog--en.pdf>`
      * * **Related**
	* * :doc:`basics`
	  * :doc:`fortgeschrittenes`
	  * :doc:`multithreading`
	  * :doc:`/trainings/repertoire/linux-prog/linux-basics`
      * * **Booking**
	* :doc:`/trainings/booking`


Netzwerkprogrammierung unter Linux (und UNIX) fügt sich hervorragend
in das Grundprinzip "Everything is a File" ein. Das Socket-Interface
stellt ein leicht zu benutzendes Programmierparadigma dar, das nicht
auf TCP/IP beschränkt ist, sondern auf eine Vielzahl anderer
Netzwerkprotokolle anwendbar ist.

Kursinhalt
----------

* **Grundlagen der Netzwerkprogrammierung**. Das Socket-Interface -
  seine Datentypen und Systemcalls - wird erklärt, ohne jedoch noch
  auf ein spezielles Medium einzugehen.

  * *Relevante Systemcalls*: ``socket()``, ``connect()``, ``bind()``,
    ``listen()``, ``accept()``
  * *Streamverbindungen*: Verbindungsaufnahme und Kommunikation
  * *Datagramme*: verbindungslose Kommunikation
  * *Fehlerszenarien*
  * *Adressfamilien*: jedes "Medium" hat seine eigene Auffassung der
    Adresse eines Endpoints. Beispielsweise kennt man von IPv4 die
    vier Nummern wie 192.168.1.2 - andere Medien wie Bluetooth haben
    andere Adressen, die aber mit den gleichen System Calls bearbeitet
    werden.

* **TCP/IP**. Netzwerkprogrammierung am Internet.

  * TCP (Stream-Verbindungen) und UDP (Datagramme)
  * Hilfsfunktionen zur Adresskonvertierung
  * DNS-Lookup
  * IPv4 und IPv6

* **UNIX Domain Sockets**. Prozesse, die nur lokal (innerhalb eines
  Systems) kommunizieren, verwenden UNIX Domain Sockets. Sie
  funktionieren gleich wie ihre TCP/IP-Äquivalente, nur sind sie
  ungleich ressourcenschonender, und ihre Adressen sind Pfadnamen im
  Filesystem.
* **CAN-Bus**. CAN (Controller Area Network) war lange Zeit nur über
  Controller-spezifische Driver und deren Interfaces bedienbar;
  mittlerweise wurde dieses Medium, wenngleich *broadcast-only*, in
  das Socket-Interface eingepasst und ist dementsprechend angenehm zu
  verwenden.
* **IO-Multiplexing mit select/poll/epoll**. Eine Möglichkeit, in
  einem Prozess mit mehreren Verbindungen umzugehen, ist, jeder
  Verbindung einen Thread zu widmen - und sich dadurch den damit
  verbundenen Gefahren auszusetzen. IO-Multiplexing ist eine
  alternative Methode, mit mehreren Verbindungen umzugehen - man
  reagiert auf *IO-Events* wie "Daten können von einem Socket gelesen
  werden", oder "Daten können auf ein Socket geschrieben werden".

  * *Eventgetriebenes ("nonblocking") Programmieren*
  * *Verbindungsaufnahme*, nonblocking
  * *I/O*, nonblocking
  * *Eventgetriebenes Programmieren* abseits von Netzwerk-I/O: Timer, Signale, ...

Empfohlene Vorkenntnisse
------------------------

Solide Kenntnisse in C werden vorausgesetzt, genau wie eine
Grundkenntnis des Systems (vgl. :doc:`Einführungskurs
<basics>`).
