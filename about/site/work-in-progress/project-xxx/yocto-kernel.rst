.. jf-task:: project_xxx.yocto_kernel
   :initial-estimate: 2
   :percent-done: 100

Extract Kernel from Intel Yocto BSP
===================================

Figure out which kernel tree to clone, and which branch to use.

Done,

.. code-block:: console

   $ git clone git://git.yoctoproject.org/linux-yocto
   $ git checkout v5.4/standard/base

Recipe from ``YOCTO-BSP_SMARC-sXAL4_SMARC-sXAL_R1.0_combined.zip``,

.. literalinclude:: linux-kontron-smarc-sxal4_5.4.bb
   :caption: :download:`linux-kontron-smarc-sxal4_5.4.bb`
