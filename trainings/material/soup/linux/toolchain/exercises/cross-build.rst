.. ot-exercise:: linux.toolchain.exercises.cross_build
   :dependencies: linux.toolchain.static_library,
		  linux.toolchain.raspi.toolchain_setup


Exercise: Build Software Package (Cross, Raspberry)
===================================================

* Install the Rasberry cross toolchain
  (:doc:`../raspberry-pi/toolchain-setup`)
* Write a ``Makefile`` as in :doc:`native-build`, with the difference
  that you'll perform a cross-build onto the Raspberry.

.. ot-graph::
   :entries: linux.toolchain.exercises.cross_build
