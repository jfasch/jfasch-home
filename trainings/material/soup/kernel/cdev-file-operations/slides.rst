.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how struct
                 file_operations is used on a character device
   :keywords: schulung, training, linux, kernel, module, character
              device, cdev, device_create, file_operations, hooks

File Operations on Character Devices (Slideshow)
================================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_file_operations/_morph>`__

File Operations: Interface Definition ("vtable") (1)
----------------------------------------------------

**Character devices are interfaces**

* Driver writer supplies methods (read, write, ...)
* Semantics are up to the implementor
* Good Unix citizenship encouraged (but not enforced)

.. code-block:: c
   :caption: From <linux/fs.h>

   struct file_operations {
        struct module *owner;
        int (*open) (struct inode *, struct file *);
        ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
        ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
        long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
        /*...*/
   };

.. code-block:: c
   :caption: Usage

   #include <linux/fs.h>
   
   const struct file_operations my_ops = {
       .owner = THIS_MODULE,
       .open = my_open,
       .read = my_read,
       .write = my_write,
       .unlocked_ioctl = my_ioctl,
       /*...*/
   };

Available Methods
-----------------

More methods "overloadable" ...

* All methods receive ``struct file`` as "this" parameter
* ``open()``: implements ``man -s 2 open`` - ``inode`` already loaded,
    ``struct file`` allocated |longrightarrow| "constructor"
* ``read()``: implements ``man -s 2 read``
* ``write()``: implements ``man -s 2 write``
* ``unlocked_ioctl()``: implements ``man -s 2 ioctl``
* ``flush()``: reference count decremented
* ``release()``: reference count reached zero |longrightarrow|
    ``struct file`` freed

.. note:: 

   ``flush()``/``release()``: see :doc:`fork()/dup()
   <../stub-sysprog-dup/topic>`

``open()``: Userspace
---------------------

.. code-block:: c
   :caption: ``man -s 2 open``

   int open(const char *pathname, int flags);
   int open(const char *pathname, int flags, mode_t mode);

* Opens and/or creates a file
* Many flags/parameters
* Permissions
* Driver not concerned with all that
* |longrightarrow| *Virtual File System* layer

(`Manual page <https://man7.org/linux/man-pages/man3/open.3p.html>`__)

``open()``: Kernelspace
-----------------------

.. code-block:: c

   int my_open(struct inode* inode, struct file* filp) {...}

* All complicated stuff (permissions etc.) done by VFS layer
* Hook for driver to associate driver data with ``struct file``
* Looks weird
* Is simple
* |longrightarrow| Later by example

``ioctl()``: Userspace
----------------------

**Swiss army knife** ...

* Used to communicate with drivers
* All that doesn't fit in ``read()``, ``write()``

.. code-block:: c
   :caption: ``man -s 2 ioctl``

   #include <sys/ioctl.h>
   
   int ioctl(int fd, unsigned long request, ...);

* ``fd``: handle to open device node
* ``request``: device specific request code
* ``...``: (if any) a single parameter

  * Usually a pointer
  * Can be integer, but should be of pointer size
  * Type depends on value of ``request``

(`Manual page <https://man7.org/linux/man-pages/man2/ioctl.2.html>`__)

``ioctl()``: Kernelspace
------------------------

.. code-block:: c

   static long my_ioctl(
       struct file *file,
       unsigned int request,
       unsigned long arg) {...}

* ``file``: (as always) in-kernel pendant to userspace file descriptor
* ``request``: userspace ``request``
* ``arg``: the ``...`` parameter from userspace. Cast arbitrarily,
  depending on ``request``

.. _ioctl-strange-beast:

``ioctl()``: Requests
---------------------

Ideally ``request`` is a simple number; e.g.

.. code-block:: c

   enum my_ioctl_requests
   {
       MY_REQUEST_SUCH,
       MY_REQUEST_SUCH_AND_SUCH,
       /*...*/
   };

**Things are not so simple though**

* History-laden
* Historically, hardcoding major an minor number led to conflicts
  between devices (so they say)
* Safety measure: ``ioctl`` request numbers need to be endoded

  * Type information of 3rd argument
  * Direction

``_IO*()`` Macros
-----------------

.. code-block:: c
   :caption: <linux/ioctl.h>

   /*
    * Used to create numbers.
    *
    * NOTE: _IOW means userland is writing and kernel is reading. _IOR
    * means userland is reading and kernel is writing.
    */
   #define _IO(type,nr)		_IOC(_IOC_NONE,(type),(nr),0)
   #define _IOR(type,nr,size)	_IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
   #define _IOW(type,nr,size)	_IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
   #define _IOWR(type,nr,size)	_IOC(_IOC_READ|_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))

* ``type``: some (arbitrary?) "magic number"
* ``nr``: actual ``ioctl`` request
* ``size``: the C type, *not* the size (OMG)

``_IO*()`` Macros: Usage
------------------------

.. code-block:: c

   enum my_ioctl_requests
   {
       MY_REQUEST_SUCH          = _IO(666, 0), /* no argument */,
       MY_REQUEST_SUCH_AND_SUCH = _IOW(666, 1, int), /* user to kernel, int argument */,
       /*...*/
   };

