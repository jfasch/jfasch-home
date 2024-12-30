.. include:: <mmlalias.txt>

Doubly Linked Lists (Slideshow)
===============================

.. contents::
   :local:

* See `LDD3
  <https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch10s05.html>`__
  for something much more comprehensive.
* See `Kernel Documentation
  <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#list-management-functions>`__
  for something much more comprehensive.

Big Picture
-----------

(Stolen from `LDD3
<https://www.oreilly.com/library/view/linux-device-drivers/0596000081/tagoreillycom20070220oreillyimages66916.png>`__)

.. image:: linked-list.png
   :scale: 150%

List Head
---------

.. code-block:: c

   #include <linux/list.h>

   struct list_head some_list;

   /* in some init function ... */
   INIT_LIST_HEAD(&some_list);

* Pointers to head and tail
* Used as entry into list
* Rest of list nodes are usually embedded into *payload* structures

.. code-block:: c

   struct payload {
       int some_data;
       struct list_head node;
   };

Insert a Node
-------------

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `list_add <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_add>`__
      * * `list_add_tail <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_add_tail>`__

**Add one node after another regular node**

.. code-block:: c

   struct payload* new_payload = ...; // allocate?
   struct payload* existing_payload = ...; // already in list
   list_add(&new_payload->node, &existing_payload->node);

**Prepend**: add after head of list

.. code-block:: c

   struct payload* new_payload = ...; // allocate?
   list_add(&new_payload->node, &some_list);

**Append**: add before tail member of ``list_head``

.. code-block:: c

   struct payload* new_payload = ...; // allocate?
   list_add_tail(&new_payload->node, &some_list);

Iteration, and Getting a Node's Container
-----------------------------------------

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `list_for_each <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_for_each>`__
      * * `list_entry <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_entry>`__
   
* List iteration is error prone |longrightarrow| ``list_for_each()``
  macro
* Cursor variable is of type ``struct list_head`` |longrightarrow|
  need to access containing structure

.. code-block:: c

   struct list_head* run;
   list_for_each(run, &some_list) {
       struct payload* run_payload = list_entry(run, struct payload, node);
       // do something with payload
   }

.. note::

   Do not modify a list while iterating!

Emptying a List
---------------

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `list_empty <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_empty>`__
      * * `list_first_entry <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_first_entry>`__
      * * `list_del <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=list_add#c.list_del>`__

* To empty a list, best use a ``while`` loop until ``list_empty()`` is
  true
* Call ``list_del()`` to remove ``list_first_entry()`` in each
  iteration

.. code-block:: c

   while (! list_empty(&some_list)) {
       struct payload* a_payload = list_first_entry(&some_list, struct payload, node);
       list_del(&payload->node);
       // deallocate?
   }
