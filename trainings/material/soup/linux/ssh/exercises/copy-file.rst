.. ot-exercise:: linux.ssh.exercises.copy_file
   :dependencies: linux.ssh.exercises.pubkey,
		  linux.ssh.key_pair,
		  linux.ssh.scp,
		  linux.ssh.basics


Exercise: Copy a File To Remote Machine, And Verify
===================================================

.. sidebar::

   **Topics**

   * :doc:`../scp`

* View your *local* password database's metadata, and compute its
  SHA256 fingerprint.

  .. code-block:: console

     $ ls -l /etc/passwd
     -rw-r--r--. 1 root root 2746 Mar  3 14:12 /etc/passwd
     $ sha256sum /etc/passwd
     72c18232434d0551af75f964ea66ae5d9271faba895f40a929fb17f19d7ab44c  /etc/passwd

* Use the ``scp`` command to copy that file to the remote machine -
  into your remote home directory under the name ``~/my-local-passwd``
* Use the ``ssh`` command *non-interactively* to verify the SHA256
  checksum *on the remote side*:

  * You do not login to the remote machine
  * You do not type the ``sha256sum`` command an a remote login shell
  * Rather, you use the local ``ssh`` command to automate that process
    and call ``sha256sum`` remotely for you.

* Compare the remote fingerprint with the local fingerprint
* Did the copy succeed without information loss?

.. ot-graph::
   :entries: linux.ssh.exercises.copy_file
