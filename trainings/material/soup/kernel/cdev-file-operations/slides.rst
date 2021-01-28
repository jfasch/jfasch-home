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

File Operations: "vtable"
-------------------------

.. code-block:: c

   struct file_operations {
        /* ... */
	int (*open) (struct inode *, struct file *);
	int (*flush) (struct file *, fl_owner_t id);
	int (*release) (struct inode *, struct file *);
	/* ... */
	loff_t (*llseek) (struct file *, loff_t, int);
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
	int (*mmap) (struct file *, struct vm_area_struct *);
	/* ... */
   }


``open()``
----------

jjj

.. code-block:: c

   static int my_open(struct inode *inode, struct file *filp)
   {
       ...
   }

   static const struct file_operations my_fops = {
       .open = my_open,
   };

* blah C "designated initializer"

See :doc:`screenplay`

``read()``
----------

