.. ot-topic:: sysprog.fileio.create

.. include:: <mmlalias.txt>


Creating Files
==============

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__

``O_CREAT`` And ``O_EXCL``
--------------------------

* ``O_CREAT``, combined with ``O_WRONLY`` or any other such flag
  [#read-just-as-well]_, creates a file if it does not exist
* If the file is created, then ``mode`` is used to initialize its
  permission mask
* Additionally, if ``flags`` contains ``O_EXCL``, ``open()`` fails if
  the file exists

  * |longrightarrow| Important when no two processes must create the
    same file and overwrite each other's contents

Creating A File If It Does Not Exist (``O_CREAT``)
--------------------------------------------------

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/basics/permissions/umask`

* Note: ``mode`` is ``0666``

  * This is the preferred ``mode`` that the program should specify
  * The user's
    :doc:`/trainings/material/soup/linux/basics/permissions/umask`
    specifies the bits that are subtracted from it

* Use this on ``/tmp/somefile`` from previous section
  (:doc:`../file-output/index`)
* |longrightarrow| File opened for overwrite (we did not say
  ``O_APPEND``)
* |longrightarrow| File mode as before (file existed)
* Remove file, and call again
* |longrightarrow| Created with ``mode`` specified

.. literalinclude:: code/create-simple.cpp
   :caption: :download:`code/create-simple.cpp`
   :language: c++

Creating A File, Failing If It Already Exists (``O_EXCL``)
----------------------------------------------------------

* ``O_CREAT | O_EXCL``: "exclusive" creation
* ``O_CREAT`` creates a file if it does not exist
* ``O_EXCL`` fails if the file already exists
* |longrightarrow| No data can be accidentally overwritten
* Prevents race condition if two processes ...

  * see that a file does not exist
  * create it

.. code-block:: c

   if ("/tmp/somefile" does not exist)    // <-- both see this
       create "tmp/somefile";             // <-- both do this

.. rubric:: Footnotes
.. [#read-just-as-well] One could legally combine ``O_CREAT`` with
                        ``O_RDONLY`` just as well if that made sense.

Attention: ``mode`` (A.k.a. *Permissions*)
------------------------------------------

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/basics/permissions/umask`

* Always specifiy ``mode`` when using ``O_CREAT``: the new file needs
  well-defined *permissions*!
* C cannot tell you that it's missing
* |longrightarrow| Unspecified third parameter is the same as using
  uninitialized memory
* Recommendation: ``mode`` should be ``0666`` (``rw-rw-rw-``)

  * Bits are subtracted from it using the user's ``umask`` (see
    :doc:`here
    </trainings/material/soup/linux/basics/permissions/umask>`)


(Short demo maybe)
