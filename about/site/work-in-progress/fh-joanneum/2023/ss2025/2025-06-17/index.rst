.. include:: <mmlalias.txt>


2025-06-17 (2*3 UE): Project Work
=================================

.. contents::
   :local:

Group 1: Pressure Sensor, SPS Dreamteam, Edge Detection
-------------------------------------------------------

Group 2: ``libgpiod`` Fiasco
----------------------------

``libgpiod`` on Raspi

Install prerequisites
.....................

.. code-block:: console

   $ sudo apt install -y automake autoconf autoconf-archive libtool

Get/Build/Install ``libgpiod``
..............................

.. code-block:: console

   $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git
   $ cd libgpiod/
   $ ./autogen.sh --enable-tools
   $ ./configure --enable-tools --enable-bindings-cxx
   $ make
   $ sudo make install

Build Our Project
.................

* Sync your fork
* Proceed as usual
