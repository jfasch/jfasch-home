.. include:: <mmlalias.txt>


Slide Material: Python, asyncio, libgpiod, and Pointless Blinking
=================================================================

.. contents::
   :local:

``blink``
---------

* Source code: https://github.com/jfasch/blink
* Talk's livehacking outcome:
  https://github.com/jfasch/blink/tree/main/glt2024/final

``gpiod``
---------

* C interface (at the heart of it), C++ binding:
  https://libgpiod.readthedocs.io/en/latest/modules.html
* PyPI: https://pypi.org/project/gpiod/
* Kernel documentation: https://www.kernel.org/doc/Documentation/gpio/
* Python binding

  .. code-block:: console

     $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git
     $ ls -1 libgpiod/bindings/python/examples/
     async_watch_line_value.py
     find_line_by_name.py
     get_chip_info.py
     get_line_info.py
     get_line_value.py
     get_multiple_line_values.py
     Makefile.am
     reconfigure_input_to_output.py
     toggle_line_value.py
     toggle_multiple_line_values.py
     watch_line_info.py
     watch_line_rising.py
     watch_line_value.py
     watch_multiple_line_values.py

``asyncio``
-----------

* :doc:`python:library/asyncio`
* `Yury Selivanov - async/await in Python 3.5 and why it is awesome <https://youtu.be/m28fiN9y_r8?si=i-rD9wQGmzehON4k>`__

   .. raw:: html

      <iframe width="560" height="315" 
              src="https://www.youtube.com/embed/m28fiN9y_r8?si=k3V6yIDj9X11dTTP" 
	      title="YouTube video player" 
	      frameborder="0" 
	      allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	      referrerpolicy="strict-origin-when-cross-origin" 
	      allowfullscreen>
      </iframe>

* `David Beazley - Build Your Own Async
  <https://youtu.be/Y4Gt3Xjd7G8?si=TaItLr1WHxHgBmQU>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/Y4Gt3Xjd7G8?si=TaItLr1WHxHgBmQU" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

Textual
-------

* Homepage, Documentation: https://textual.textualize.io/
* Source code: https://github.com/textualize/textual/

Python SDbus
------------

* Documentation: https://python-sdbus.readthedocs.io/en/latest/
* Source code: https://github.com/python-sdbus
* Lennart Pöttering about SDbus, *recommended reading*:
  https://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html
* DBus specification: https://www.freedesktop.org/wiki/Software/dbus/

Python 3.12 Installation (for ``TaskGroup``)
--------------------------------------------

.. code-block:: console

   $ sudo apt install libssl-dev libreadline-dev libffi-dev libsystemd-dev python3-dev
   $ wget https://www.python.org/ftp/python/3.12.2/Python-3.12.2.tar.xz
   $ tar xf Python-3.12.2.tar.xz 
   $ cd Python-3.12.2/
   $ ./configure --prefix=$HOME/Python-3.12.2-Install --with-readline
   $ make
   $ make install
