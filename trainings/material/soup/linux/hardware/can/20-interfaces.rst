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
   3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN mode DEFAULT group default qlen 10
       link/can 

.. code-block:: console

   # ip link set can0 type can help

.. code-block:: console

   # ip link set can0 type can bitrate 500000
   # ip link set can0 txqueuelen 1000
   # ip -detail link show can0 
   12: can0: <NOARP,ECHO> mtu 16 qdisc pfifo_fast state DOWN mode DEFAULT group default qlen 1000
       link/can  promiscuity 0 allmulti 0 minmtu 0 maxmtu 0 
       can state STOPPED restart-ms 0 
   	  bitrate 500000 sample-point 0.875
   	  tq 125 prop-seg 6 phase-seg1 7 phase-seg2 2 sjw 1 brp 6
   	  gs_usb: tseg1 1..16 tseg2 1..8 sjw 1..4 brp 1..1024 brp_inc 1
   	  clock 48000000 numtxqueues 1 numrxqueues 1 gso_max_size 65536 gso_max_segs 65535 tso_max_size 65536 tso_max_segs 65535 gro_max_size 65536 gso_ipv4_max_size 65536 gro_ipv4_max_size 65536 parentbus usb parentdev 3-6.2.4:1.0 
   
.. code-block:: console
   :caption: Same, but listen-only

   # ip link set can0 bitrate 500000 listen-only on

.. code-block:: console
   :caption: Finally: turn on the interface

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
