.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how the linux
		 kernel's doubly linked list implementation is used

   :keywords: schulung, training, linux, kernel, module, doubly linked
              list

First Functionality (Slideshow)
===============================

.. contents::
   :local:

* list: https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch10s05.html

  * ``#include <linux/list.h>``
  * Drawing from
    https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch10s05.html
  * ``INIT_LIST_HEAD()``
  * ``list_for_each()``

    * careful: do not modify while iterating

  * ``list_entry()``
  * ``list_add_tail()``
  * ``list_first_entry()``
  * more

* kmalloc etc: https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch08.html

  * ``#include <linux/slab.h>``

* bring in ``ioctl()`` chapter from :download:`Kernel </trainings/material/pdf/400-kernel.pdf>`
