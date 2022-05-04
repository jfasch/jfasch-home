.. ot-topic:: linux.hardware.can.interfaces

.. meta::
   :description: CAN Bus (using MCP2515)
   :keywords: linux, can bus, spi, raspberry pi, raspi

.. include:: <mmlalias.txt>


CAN Interfaces
==============

.. contents::
   :local:

CAN-Interface: Configuration
----------------------------

**CAN is a network...**

.. code-block:: console

   # ip link show
   ... all interfaces here ...
   # ip link show can0
   3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN mode DEFAULT qlen 10
       link/can 
   # ip link set can0 type can help
   # ip link set can0 bitrate 500000
   # ip link set can0 bitrate 500000 listen-only on
   # ip link set can0 up

CAN Utils
---------

.. sidebar:: Links

   * https://github.com/linux-can/can-utils.git

**Nice little utilities ...**

* Userspace relic of the *SocketCAN* project (|longrightarrow| make
  CAN a network)
* ``cansend``: send a frame
* ``candump``: recording frames from one or more CAN interfaces
* ``canplayer``: replay from recording
*  ... and others ...
*  |longrightarrow| testing!

**Installation**

.. code-block:: console
   :caption: Fedora

   # dnf install can-utils

.. code-block:: console
   :caption: Debian/Ubuntu

   # apt install can-utils

CAN Utils: Usage (1)
--------------------

**Generating frames:**

.. code-block:: console

   $ cansend can0 123#deadbeef
   $ cangen -D deadbeef -L 4 can0
   $ cangen -D deadbeef -L 4 -I 42 can0
   $ cangen -D i -I 42 -L 8 -g 100 -p 100 can0

**Sniffing frames:** 

.. code-block:: console

   $ candump can0
   $ candump can0 can1 ...

CAN Utils: Usage (2)
--------------------

**Record, Replay:**

.. code-block:: console

   $ candump -L can0 > can0.log
   $ canplayer < ./can0.log 

**Changing the interface:**

.. code-block:: console

   $ canplayer can1=can0 < ./can0.log 

``vcan``: Virtual CAN-Bus
-------------------------

**Problem:**
  
* CAN development traditionally needs hardware
* ... at least two participants (loopback on one controller possible))
* |longrightarrow| programming and testing as hard as can be

**Lösung:**

.. code-block:: console

   # modprobe vcan
   # ip link add dev mein-test-can type vcan
   # ip link set mein-test-can up
   # canplayer mein-test-can=can0 < ./can0.log 

**Fantasy:**

* Programming and testing on the PC
* Continuous integration
* ...
