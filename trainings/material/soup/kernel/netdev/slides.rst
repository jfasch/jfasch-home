.. include:: <mmlalias.txt>

Network Devices (Slideshow)
===========================

.. contents::
   :local:

Module Initialization: Device Allocation
----------------------------------------

.. code-block:: c

   struct net_device *alloc_netdev(
           int sizeof_priv, const char *name, 
           void (*setup)(struct net_device *));

* ``sizeof_priv``: private driver data, both allocated alongside net
  device structure in one large chunk

  .. code-block:: c

     priv = netdev_priv(dev);

* ``name``: can contain ``"%d"`` |longrightarrow| kernel inserts
  device number
* ``setup``: setup function, see below

Helper funcion for ethernet devices:

.. code-block:: c

   #include <linux/etherdevice.h>

   struct net_device *alloc_etherdev(int sizeof_priv);

Finally, deallocation on unload:

.. code-block:: c

   free_netdev(dev);

Module Initialization: Device Registration
------------------------------------------

.. code-block:: c

   err = register_netdev(dev);
   unregister_netdev(dev);

Device Methods
--------------

* ``int (*open)(struct net_device *dev);``

  Called when activated by ``ifconfig``. Allocates resources like
  interrupts, initializes devince, ...

* ``int (*stop)(struct net_device *dev);``

  The reverse of ``open()``

* ``int (*hard_start_xmit) (struct sk_buff *skb, struct net_device *dev);``

  Submits packet for transmission.

* ``void (*tx_timeout)(struct net_device *dev);``

  Called by networking layer above when it detects that a packet
  hasn't completed.

* ``int weight;``
* ``int (*poll)(struct net_device *dev; int *quota);``

  Used to mitigate interrupt load on high speed networks. Interrupts
  are off, and polling is used in stead. NAPI ("New API").

* ``int (*do_ioctl)(struct net_device *dev, struct ifreq *ifr, int cmd);``
  
  Much like ``ioctl()`` in character devices.

* (A lot more omitted)

Kernel Networking Layer Utilities
---------------------------------

* ``void netif_start_queue(struct net_device *dev);``

  Usually called by ``open()``.

* ``void netif_stop_queue(struct net_device *dev);``

  Stops a queue; usually called by the ``stop()`` method, or in
  situations where the device sees no way of handling further packets.

* ``void netif_wake_queue(struct net_device *dev);``

  Called when the device has room for more packets, and had stopped
  the queue before.

* (A lot more omitted)
