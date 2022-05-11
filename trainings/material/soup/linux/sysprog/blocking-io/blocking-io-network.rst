.. ot-topic:: linux.sysprog.blocking_io.blocking_io_network
   :dependencies: linux.sysprog.fileio.basics,
		  linux.sysprog.blocking_io.blocking_io

.. include:: <mmlalias.txt>


Blocking I/O: On A Network Socket
=================================

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 7 socket (sockets overview) <https://man7.org/linux/man-pages/man7/socket.7.html>`__
   * `man -s 2 socket <https://man7.org/linux/man-pages/man2/socket.2.html>`__
   * `man -s 2 connect <https://man7.org/linux/man-pages/man2/connect.2.html>`__
   * `man -s 2 read <https://man7.org/linux/man-pages/man2/read.2.html>`__
   * `man -s 2 write <https://man7.org/linux/man-pages/man2/write.2.html>`__
   * `man -s 2 close <https://man7.org/linux/man-pages/man2/close.2.html>`__

.. sidebar:: See Also

   * :doc:`/trainings/material/soup/linux/sysprog/basics/group`

Opening a Network Connection
----------------------------

* Even more :doc:`than a file <blocking-io-file>`, network connections
  are tedious

  * Determine destination address: local/remote? (|longrightarrow| do
    I send it to address on local net, or do I send it to my net's
    gateway?)
  * Formulate IP packet
  * Setup DMA on network hardware
  * Wait for interrupt
  * Start transmission timeout
  * ... (you get the point) ...

* |longrightarrow| a job for an *Operating System*

Abstractions
------------

* *What* do we read?

  * Bytes from a *network connection*
  * Addresses depend on network type (TCP/IP is just one out of many)
  * |longrightarrow| **Socket abstraction!**

* *How* do we read that? In the case of TCP ...

  * Don't want to ... blah interrupt, DMA, blah ... want none of that
  * Only want to *connect* to peer/server
  * Only want to *read* data

Simplicity
----------

* System call: ``socket()``
* System call: ``connect()``
* System call: ``read()``
* System call: ``write()``
* System call: ``close()``

.. literalinclude:: read-network.c
   :language: c
   :caption: :download:`read-network.c`

Build, Run, Look
----------------

.. code-block:: console

   $ gcc -o read-network read-network.c 

.. list-table::
   :align: left
   :header-rows: 1

   * * Client
     * Server (start first)
   * * .. code-block:: console

          $ strace ./read-network
	  socket(AF_INET, SOCK_STREAM, IPPROTO_IP) = 3
	  connect(3, {sa_family=AF_INET, sin_port=htons(1234), sin_addr=inet_addr("127.0.0.1")}, 16) = 0
	  read(3, 

       |longrightarrow| *Blocking* system call: nothing there to read

     * .. code-block:: console
       
          $ nc -l -p 1234

   * * .. code-block:: console

          ... "hallo du!\n", 16)              = 10
          write(1, "hallo du!\n", 10hallo du!
	  )             = 10
	  read(3, 

       |longrightarrow| *Wakes up* to read "``hallo du!\n``", and then
       *blocks* again

     * .. code-block:: console

          hallo du!

   * * .. code-block:: console

          ... "this is a very l", 16)         = 16
          write(1, "this is a very l", 16this is a very l)        = 16
          read(3, "ong text!!!!!\n", 16)          = 14
          write(1, "ong text!!!!!\n", 14ong text!!!!!
          )         = 14
          read(3, 

       (Needs two iterations for a very long text)

     * .. code-block:: console

          this is a very long text!!!!!

   * * .. code-block:: console

          ... "", 16)                         = 0
	  close(3)                                = 0

     * .. code-block:: console
          :caption: ``^D`` is end-of file on standard input

          ^D
