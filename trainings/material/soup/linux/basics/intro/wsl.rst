.. ot-topic:: linux.basics.intro.wsl
   :dependencies: linux.basics.intro.overview

.. include:: <mmlalias.txt>


Windows Subsystem for Linux (WSL)
=================================

.. note:: Disclaimer!

   **I am no Windows expert**. Although I have written a Kernel driver
   (PCI, DMA, tons of interrupts) in the past that runs equally stable
   on both Linux (did that first, and then ported to Doze as you might
   imagine), I tend to keep my fingers away because I know my enemy.

.. contents::
   :local:

Links
-----

This document is a rather half hearted approach to guiding people
through *working for Linux on Windows*. Follow the links below - so
much for guidance (the rest of the document is very opinionated
|:face_with_raised_eyebrow:|).

* `Basic install document
  <https://docs.microsoft.com/en-us/windows/wsl/install>`__
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
Linux development.

M$ has finally `acknowledged
<https://www.zdnet.com/article/ballmer-i-may-have-called-linux-a-cancer-but-now-i-love-it/>`__
that `fighting Linux
<https://www.theregister.com/2001/06/02/ballmer_linux_is_a_cancer/>`__
does not make sense. 

All those companies are addicted to Windows (who can imagine leading a
life without Outlook? Teams?), so it is very respectful from Microsoft
to help them out as much as they can [#selfish]_. 

WSL, Finally
------------

WSL is a good thing. If I needed to, I'd appreciate that I could just
say (but not without opening a command window first),

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
