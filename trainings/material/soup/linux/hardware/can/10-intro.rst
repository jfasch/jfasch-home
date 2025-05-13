.. meta::
   :description: CAN Bus (using MCP2515)
   :keywords: linux, can bus, spi, raspberry pi, raspi

.. include:: <mmlalias.txt>


CAN/Linux Basics
================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`40-harware`

Why This Talk?
--------------

* Everything is very complicated ((C) `Fred Sinowatz
  <https://de.wikipedia.org/wiki/Fred_Sinowatz>`__) ... if things are
  not kept apart
* CAN bus is not usually associated with simplicity
* |longrightarrow| Linux makes it simple by keeping matters apart

  * Network programming |longrightarrow| common knowledge
  * *SocketCAN*: donated by Volkswagen
  * Application *is a network application*

    * *not* bound to hardware
    * CAN controller independent |longrightarrow| controllers can be
      exchanged
    * Programming language independent (Python is best of course
      |:kissing_heart:|)

* Special goodie: virtual CAN bus

  * |longrightarrow| development and testing on the PC, no hardware at
    all needed

Network Programming: Datagram Exchange
--------------------------------------

.. list-table::
   :align: left
   :widths: auto

   * * Packet traffic (*no* connection) |longrightarrow| datagrams

       * On the Internet: User Datagram Protocol (UDP)
       * Not a point to point connection like TCP
       * Broadcasts possible
       * Packet boundaries (as opposed to *octet streams* in TCP)

     * .. image:: datagram-socket.dia
          :scale: 50%


And CAN?
--------

* Very small packets (max. 8 bytes payload)
* Bus arbitration, packet prioritization, and "application" done by
  *packet IDs*
* No addresses, *only broadcasts*
* |longrightarrow| looks like network, is network

.. image:: can-topo.dia
   :scale: 50%

One CAN Network Packet ...
--------------------------

* Defined as a C struct
* In *host byteorder*
* Python: ``struct.pack()``, ``struct.unpack()``

.. code-block:: c

   #include <linux/can.h>

   struct can_frame {
       canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
       __u8    can_dlc; /* frame payload length */
       __u8    data[8] __attribute__((aligned(8)));
   };
