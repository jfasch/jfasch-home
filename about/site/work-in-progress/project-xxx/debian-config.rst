.. ot-task:: project_xxx.debian_config
   :initial-estimate: 3
   :percent-done: 100

Get Debian 10 Kernel Config
===========================

Figure out where to get Debian's kernel config.

Run Debian within Qemu
----------------------

See `here
<https://linuxwebdevelopment.com/run-debian-qemu-kvm-virtual-machine-using-ubuntu-debian/>`__.

.. code-block:: console

   $ mkdir qemu-debian
   $ cd qemu-debian
   $ wget https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-10.10.0-amd64-netinst.iso
   $ qemu-img create -f qcow2 virtualdebian.img 30G
   $ qemu-kvm -hda virtualdebian.img -cdrom debian-10.10.0-amd64-netinst.iso -m 2048 -net nic -net user

Extract Kernel Config from ``/boot``
------------------------------------

Sic. Cool how ``qemu`` works out of the box, network configured,
``scp``.
