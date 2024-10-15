.. ot-topic:: linux.hardware.can.programming
   :dependencies: linux.hardware.can.intro,
		  linux.hardware.can.interfaces

.. meta::
   :description: CAN Bus (using MCP2515)
   :keywords: linux, can bus, spi, raspberry pi, raspi

.. include:: <mmlalias.txt>


Programming
===========

.. contents::
   :local:

CAN Programming
---------------


**CAN  Sockets ...**

* Packet switching |longrightarrow| much like UDP on the Internet
* New *protocol family*: ``PF_CAN``
* No addresses |longrightarrow| binding by *interface index*
* Fixed size packets (*frames*)

CAN in C - Socket, *Interface Index*
------------------------------------

From `Documentation/networking/can.txt
<https://github.com/torvalds/linux/blob/master/Documentation/networking/can.rst>`__

.. code-block:: c

   int s;
   struct sockaddr_can addr;
   struct ifreq ifr;
   
   s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
   
   strcpy(ifr.ifr_name, "can0");
   ioctl(s, SIOCGIFINDEX, &ifr);
   
   addr.can_family = AF_CAN;
   addr.can_ifindex = ifr.ifr_ifindex;
   
   bind(s, (struct sockaddr *)&addr, sizeof(addr));

CAN in Python - Socket, *Interface Index*
-----------------------------------------

.. code-block:: python

   import socket

   can_socket = socket.socket(socket.PF_CAN, socket.SOCK_RAW, socket.CAN_RAW)
   can_socket.bind(('can0',))

CAN in C - Frames (1)
---------------------

Kernel accepts (``write()/send()``) and delivers (``read()/recv()``)
fixed size network packtes |longrightarrow| CAN frames

.. code-block:: c

   #include <linux/can.h>

   struct can_frame {
       canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
       __u8    can_dlc; /* frame payload length */
       __u8    data[8] __attribute__((aligned(8)));
   };

CAN in C - Frames (2)
---------------------

.. code-block:: c

   #include <linux/can.h>

   struct can_frame frame;
   read(s, &frame, sizeof(struct can_frame));
   
   /* do something with frame */
   
   write(s, &frame, sizeof(struct can_frame));

CAN in Python - Frames
----------------------

.. code-block:: c

   struct can_frame {
       canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
       __u8    can_dlc; /* frame payload length */
       __u8    data[8] __attribute__((aligned(8)));
   };

.. code-block:: python

   import struct

   frame_layout = "=IB3x8s"
   frame_size = struct.calcsize(frame_layout)
   frame = can_socket.recv(frame_size)
   can_id, can_dlc, data = struct.unpack(frame_layout, frame)
   
   # do something with frame
   
   frame = struct.pack(frame_layout, can_id+1, len(data), data)
   can_socket.send(frame)

What Else?
----------

* Interface Index ``0`` (Python: empty interface name |longrightarrow| *all* interfaces)
* Alternative system calls: ``recvfrom()`` and ``sendto()`` if one
  wants to know the interface on which a frame is received
* The rest is Unix

  * File descriptors
  * Event loops
  * |longrightarrow| well-know client/server techniques

* Realtime ... is a completely different story

  * Can be done if needed
  * *Caution*: if you don't need it don't use it!
