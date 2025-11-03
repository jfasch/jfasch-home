.. include:: <mmlalias.txt>


Windows Subsystem for Linux (WSL)
=================================

Links
-----

.. topic:: Disclaimer!

   **I am not a Windows expert**. Although I have written a Kernel
   driver (PCI, DMA, tons of interrupts) in the past that runs equally
   stable on both Linux (did that first) and Windows (ported the Linux
   implementation to Doze), I tend to keep my fingers away because I
   know my enemy.

This document is a rather half hearted approach to guiding people
through *working for Linux on Windows*. Follow the links below - so
much for guidance (the rest of the document is very opinionated
|:face_with_raised_eyebrow:|).

**Main entry point**: `Windows Subsystem for Linux Documentation
<https://docs.microsoft.com/en-us/windows/wsl/>`__

Please browse the site to find what you need, or use the following
table to solve dedicated problems.

.. list-table::
   :align: left
   :widths: auto

   * * Installation
     * `Install WSL <https://docs.microsoft.com/en-us/windows/wsl/install>`__
   * * Sharing files across Windows and Linux
     * `Working across Windows and Linux file systems
       <https://docs.microsoft.com/en-us/windows/wsl/filesystems>`__

       Long story short:

       * If your files are stored in Windows, say ``C:\Users\<user
         name>\Project``, in Linux you say

	 .. code-block:: console

	    $ ls -l /mnt/c/Users/<user name>/Project

       * If your files are stored in WSL distribution ``Ubuntu``, say
         in directory ``/home/<user name>/Project``, in Windows you
         can see them in ``\\wsl$\Ubuntu\home\<user name>\Project``


More Links
..........

* `Set up a WSL development environment
  <https://docs.microsoft.com/en-us/windows/wsl/setup/environment>`__
* `Get started using Visual Studio Code with Windows Subsystem for
  Linux
  <https://docs.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode>`__

My $0.02
--------

People ever wanted to develop on Linux [#linux_is_fun]_ - but it has
never been easy to make a living from it. Anyway, times are changing:
Linux development has gained a commercial side as more and more
devices run Linux and a lot of companies are making good money with
Linux development. Many of these companies are addicted to Windows
(who can imagine leading a life without Outlook? Teams?), and it has
proved hard to work for Linux on a (company-rules-dicdated |:ninja:|)
Windows machine.

M$ has finally `acknowledged
<https://www.zdnet.com/article/ballmer-i-may-have-called-linux-a-cancer-but-now-i-love-it/>`__
that `fighting Linux
<https://www.theregister.com/2001/06/02/ballmer_linux_is_a_cancer/>`__
does not make sense. 

It is, in this light, very respectful from Microsoft to help people
out as much as they can [#selfish]_.

WSL, Finally
------------

WSL is a good thing. If I had to, I'd appreciate that I could just say
(but not without opening a command window first),

.. code-block:: console

   wsl --install   

This innocent looking command installs a virtualized `Ubuntu Linux
<https://ubuntu.com/>`__ inside Windows, and provides mostly seamless
integration with it.

Alternatives are:

* A full virtual machine like `VirtualBox
  <https://www.virtualbox.org/>`__ or `VMWare
  <https://www.vmware.com>`__
* Jumping through hoops (sorry guys) with `MinGW
  <https://www.mingw-w64.org/>`__ or `Cygwin
  <https://www.cygwin.com/>`__


.. rubric:: Footnotes

.. [#linux_is_fun] Fun can be had there; I tend to have fun when I
                   understand things (clear concepts for exampke)
                   which is not easy on Windows.
.. [#selfish] I suppose the motivation is not pure altruism though.
