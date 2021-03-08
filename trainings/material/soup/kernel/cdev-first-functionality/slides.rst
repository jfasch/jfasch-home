.. include:: <mmlalias.txt>

First Functionality (Slideshow)
===============================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_first_functionality/_morph>`__

Implement Event List
--------------------

Right inside the main driver file (refactoring later), define and
implement the following artifacts

* ``struct my_event``

  * Subject to be linked into a list
  * Only payload is an ``enum my_event_type``, indicating the event
    source. We will implement a ``ioctl`` request that adds an event
    to the list, so the only enumerator in the enum will be something
    like ``MY_EVENT_IOCTL``.
  * Will extend to contain a timestamp (``jiffies``) once we get to
    it.

* ``struct my_event_list``

  * Members

    * A ``struct list_head`` instance: the real list
    * ``num_events``: counts how many events the list contains

  * Methods

    * ``void my_event_list_init(struct my_event_list* self)``. The
      "constructor"; initializes ``self``.
    * ``void my_event_list_destroy(struct my_event_list* self)``. The
      "destructor"; deallocates all events contained in ``self``.
    * ``void my_event_list_add(struct my_event_list* self, enum
      my_event_type type)``. Allocates one event on the heap,
      initializes it with the given type, and appends it to the
      list. *Once the list exceeds a (hardwired?) maximum event count,
      the first element in the list is removed.*

Implement ``ioctl`` Request to Add an Event
-------------------------------------------

* Start defining an ``enum``, like so:

  .. code-block:: c

     enum my_ioctl_requests
     {
         MY_IOCTL_ADD_EVENT,
     };

* In the ``ioctl()`` driver method, use the above ``add()`` method to
  implement said request.

Implement a Userspace Test Program
----------------------------------

* Write a user space program to exercise that request.
* Makes sense to add a number of ``printk()`` statements to the kernel
  to see what is going on.
