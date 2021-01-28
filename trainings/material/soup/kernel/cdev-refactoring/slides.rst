.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how to maintain
		 multiple devices (and get rid of global variable)
   :keywords: schulung, training, linux, kernel, module, container_of

Refactoring (Slideshow)
=======================

.. contents::
   :local:

What's Bad?
-----------

* global variables |longrightarrow| list of devices
* too much code in ``my_driver.c`` |longrightarrow| split apart, and
  show how to build a driver from multiple sources
