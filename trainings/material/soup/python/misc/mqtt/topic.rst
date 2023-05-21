.. ot-topic:: python.misc.mqtt
   :dependencies: python.swdev.venv

MQTT
====

.. contents::
   :local:

Installation
------------

Server/Broker
.............

First, install an MQTT broker of your choice. My choice is `Eclipse
Mosquitto <https://mosquitto.org/>`__. On Fedora, you install that
package like so ...

.. code-block:: console

   # dnf install mosquitto

Client
......

Then, to communicate with that broker from Python programs, you
install a Python client implementation of your choice. My choice is
the `Paho implementation <https://pypi.org/project/paho-mqtt/>`__,
which is installed like so ...

.. code-block:: console

   $ pip install paho-mqtt

Starting the Service
--------------------

This is `Fedorish <https://getfedora.org/>`__, your mileage might
vary:

.. code-block:: console

   # systemctl start mosquitto.service
   # netstat -antp|grep mosquitto
   tcp        0      0 0.0.0.0:1883            0.0.0.0:*               LISTEN      53767/mosquitto     
   tcp6       0      0 :::1883                 :::*                    LISTEN      53767/mosquitto     

Ah, runs on port 1883.

See if it works. In one terminal, subscribe to a random topic. (Topic
are created as soon as they are mentioned.)

.. code-block:: console

   $ mosquitto_sub --host localhost --port 1883 --topic /random/topic 
   ...sit and wait for message...

In another terminal, publish a message,

.. code-block:: console

   $ mosquitto_pub --host localhost --port 1883 --topic /random/topic --message blah

You should see "blah" as the output of ``mosquitto_sub`` in the other
terminal.

Publishing a Message in Python
------------------------------

This is the easiest, so lets start with that.

.. literalinclude:: publish.py
   :caption: :download:`publish.py`
   :language: python

Run it, and in the terminal running ``mosquitto_sub`` you'll see
``"blech"`` on ``stdout``.

Subscribing a Topic in Python
-----------------------------

A little more complicated - we have to 

* run an *event loop*: we want to see more than one message coming in
* register a *callback* function that is called by MQTT to notify us
  about an incoming message

.. literalinclude:: subscribe.py
   :caption: :download:`subscribe.py`
   :language: python

Run it, possibly side by side with ``mosquitto_sub``. Publish a
message, using either the ``publish.py`` program above, or
``mosqitto_pub``.

.. code-block:: console

   $ ./subscribe.py 
   b'blech'

Message Payload?
----------------

Note the ``b`` in the output: what comes in is *not* a string. MQTT's
transport is encoding-free; what is sent is completely up to the
communicating parties.

You should probably read up on

* Encoding:
  :doc:`/trainings/material/soup/python/misc/encoding/topic`
* `JSON <https://docs.python.org/3/library/json.html#module-json>`__,
  a popular transport format, used for MQTT message transfer, and on
  The Web which is full of it.

Links
-----

* Nice video about MQTT concepts, and a little Python code (*German*)

   .. raw:: html
   
      <iframe
          width="560" 
	  height="315" 
	  src="https://www.youtube.com/embed/DiqLgy2-lD4" 
	  frameborder="0" 
	  allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	  allowfullscreen>
      </iframe>

* Same, but with Node-RED (*Styrian*)

   .. raw:: html
   
      <iframe
          width="560" 
          height="315" 
          src="https://www.youtube.com/watch?v=ItcGWCvYa8o" 
          frameborder="0" 
          allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" 
          allowfullscreen>
      </iframe>

* Communicating from Arduino/ESP to Raspberry (*German*)

  * `Python side
    <https://smarthome-blogger.de/tutorial/mqtt-raspberry-pi-einfuehrung/>`__
  * `Arduino/ESP side
    <https://smarthome-blogger.de/tutorial/esp8266-mqtt-tutorial/>`__

* Encryption, Users, from minute 11:30 (*German*)

   .. raw:: html
   
      <iframe
          width="560" 
          height="315" 
          src="https://www.youtube.com/watch?v=gU5Vp0zCzak" 
          frameborder="0" 
          allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" 
          allowfullscreen>
      </iframe>

Dependencies
------------

.. ot-graph:: 
   :entries: python.misc.mqtt

