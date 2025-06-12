``libgpiod``
============

Installation
------------

.. code-block:: console
   :caption: Fedora

   $ sudo dnf install libgpiod-dev

.. code-block:: console
   :caption: Debian/Ubuntu

   $ sudo apt install libgpiod-dev

Documentation
-------------

* Main documentation page on readthedocs.io:
  https://libgpiod.readthedocs.io/en/latest/index.html
* C++ binding documentation:
  https://libgpiod.readthedocs.io/en/latest/cpp_api.html

Upstream Source
---------------

* https://github.com/brgl/libgpiod

Example: Get Line Value
-----------------------

See libgpiod/bindings/cxx/examples/get_line_value.cpp

``gpio-sim`` Kernel Module: ``configfs`` GPIO Simulator
-------------------------------------------------------

* Configfs GPIO Simulator:
  https://docs.kernel.org/admin-guide/gpio/gpio-sim.html
* https://askubuntu.com/questions/1546213/how-to-create-gpio-sim-devices-in-configfs
* Load module

  .. code-block:: console
  
     # modprobe gpio-sim

* Create ``foo`` simulation "combo"

  .. code-block:: console
  
     # cd /sys/kernel/config/gpio-sim
     # mkdir foo
     # mkdir foo/bank0
     # echo 8 > foo/bank0/num_lines
     # echo 1 > live

Videos
------

* `Bartosz Golaszewski: "New GPIO interface for linux user space" /
  #LinuxPiter <https://youtu.be/BK6gOLVRKuU?si=j_cm_tiBo3uL9s57>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/BK6gOLVRKuU?si=FfNfRC9Kslhqw35-" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `New GPIO interface for linux user space GPIO character device API
  and libgpiod <https://youtu.be/76j3TIqTPTI?si=mGTd0wk0VmCWqDtx>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/76j3TIqTPTI?si=mGTd0wk0VmCWqDtx" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>
