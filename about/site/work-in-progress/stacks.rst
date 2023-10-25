Stacks (Hanging)
================

Topics
------

DBus (New Topic)
................

* Principles

  * commandline interface
  * system vs. session/user
  * XML service definitions

* ``pydbus``
* ``openheating``

https://pypi.org/project/pydbus/

* Blog post on fixing the ``import pydbus`` error

  .. code-block:: console

     $ ./unittests/run.py 
     Traceback (most recent call last):
       File "/home/jfasch/work/openheating/./unittests/run.py", line 8, in <module>
         from oh_tests.dbus.easysuite import suite as oh_dbus_easysuite
       File "/home/jfasch/work/openheating/unittests/oh_tests/dbus/easysuite.py", line 1, in <module>
         from .easysuite_error import suite as error_suite
       File "/home/jfasch/work/openheating/unittests/oh_tests/dbus/easysuite_error.py", line 2, in <module>
         from openheating.dbus.error import DBusHeatingError
       File "./unittests/../openheating/dbus/error.py", line 5, in <module>
         import gi.repository
     ModuleNotFoundError: No module named 'gi'

  .. note::
     
     use interactive interpreter for that

  Research:

  * Where does ``gi`` come from? See below, ``PyGObject``.
  * Why is there no dependency on ``PyGObject`` from ``pydbus``?

  .. code-block:: console

     $ pip install PyGObject
     Collecting PyGObject
       Using cached PyGObject-3.40.1.tar.gz (714 kB)
       Installing build dependencies ... error
       ERROR: Command errored out with exit status 1:
        command: /home/jfasch/venv/openheating/bin/python /tmp/pip-standalone-pip-ss_9wmug/__env_pip__.zip/pip install --ignore-installed --no-user --prefix /tmp/pip-build-env-9lrqmi4l/overlay --no-warn-script-location --no-binary :none: --only-binary :none: -i https://pypi.org/simple -- setuptools wheel pycairo
            cwd: None
       Complete output (38 lines):
       Collecting setuptools
         Using cached setuptools-57.0.0-py3-none-any.whl (821 kB)
       Collecting wheel
         Using cached wheel-0.36.2-py2.py3-none-any.whl (35 kB)
       Collecting pycairo
         Using cached pycairo-1.20.1.tar.gz (344 kB)
         Installing build dependencies: started
         Installing build dependencies: finished with status 'done'
         Getting requirements to build wheel: started
         Getting requirements to build wheel: finished with status 'done'
           Preparing wheel metadata: started
           Preparing wheel metadata: finished with status 'done'
       Building wheels for collected packages: pycairo
         Building wheel for pycairo (PEP 517): started
         Building wheel for pycairo (PEP 517): finished with status 'error'
         ERROR: Command errored out with exit status 1:
          command: /home/jfasch/venv/openheating/bin/python /tmp/tmpabab356k_in_process.py build_wheel /tmp/tmpt1yod7mc
              cwd: /tmp/pip-install-o4u45fjc/pycairo_33865a19ad6b4a719885f07926efe16d
         Complete output (15 lines):
         running bdist_wheel
         running build
         running build_py
         creating build
         creating build/lib.linux-x86_64-3.9
         creating build/lib.linux-x86_64-3.9/cairo
         copying cairo/__init__.py -> build/lib.linux-x86_64-3.9/cairo
         copying cairo/__init__.pyi -> build/lib.linux-x86_64-3.9/cairo
         copying cairo/py.typed -> build/lib.linux-x86_64-3.9/cairo
         running build_ext
         Package cairo was not found in the pkg-config search path.
         Perhaps you should add the directory containing `cairo.pc'
         to the PKG_CONFIG_PATH environment variable
         Package 'cairo', required by 'virtual:world', not found
         Command '['pkg-config', '--print-errors', '--exists', 'cairo >= 1.15.10']' returned non-zero exit status 1.
         ----------------------------------------
         ERROR: Failed building wheel for pycairo
       Failed to build pycairo
       ERROR: Could not build wheels for pycairo which use PEP 517 and cannot be installed directly

  * Install ``cairo`` headers and stuff

    .. code-block:: console

       $ sudo dnf install cairo-devel

  * Next: ``gobject-introspection-devel``

  .. code-block:: console

     $ pip install PyGObject
     Collecting PyGObject
         Using cached PyGObject-3.40.1.tar.gz (714 kB)
         Installing build dependencies ... done
         Getting requirements to build wheel ... done
           Preparing wheel metadata ... done
       Collecting pycairo>=1.16.0
         Using cached pycairo-1.20.1-cp39-cp39-linux_x86_64.whl
       Building wheels for collected packages: PyGObject
         Building wheel for PyGObject (PEP 517) ... error
         ERROR: Command errored out with exit status 1:
          command: /home/jfasch/venv/openheating/bin/python /home/jfasch/venv/openheating/lib64/python3.9/site-packages/pip/_vendor/pep517/in_process/_in_process.py build_wheel /tmp/tmpf2wjv23h
              cwd: /tmp/pip-install-4rtfumdz/pygobject_beef4432e2454eb0b7facc57fadf42b8
         Complete output (44 lines):
         running bdist_wheel
         running build
         running build_py
         creating build
         creating build/lib.linux-x86_64-3.9
         creating build/lib.linux-x86_64-3.9/pygtkcompat
         copying pygtkcompat/pygtkcompat.py -> build/lib.linux-x86_64-3.9/pygtkcompat
         copying pygtkcompat/generictreemodel.py -> build/lib.linux-x86_64-3.9/pygtkcompat
         copying pygtkcompat/__init__.py -> build/lib.linux-x86_64-3.9/pygtkcompat
         creating build/lib.linux-x86_64-3.9/gi
         copying gi/types.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/pygtkcompat.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/module.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/importer.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/docstring.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_signalhelper.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_propertyhelper.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_ossighelper.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_option.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_gtktemplate.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_error.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/_constants.py -> build/lib.linux-x86_64-3.9/gi
         copying gi/__init__.py -> build/lib.linux-x86_64-3.9/gi
         creating build/lib.linux-x86_64-3.9/gi/repository
         copying gi/repository/__init__.py -> build/lib.linux-x86_64-3.9/gi/repository
         creating build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/keysyms.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/__init__.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/Pango.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/Gtk.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/Gio.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/GdkPixbuf.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/Gdk.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/GObject.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/GLib.py -> build/lib.linux-x86_64-3.9/gi/overrides
         copying gi/overrides/GIMarshallingTests.py -> build/lib.linux-x86_64-3.9/gi/overrides
         running build_ext
         Package gobject-introspection-1.0 was not found in the pkg-config search path.
         Perhaps you should add the directory containing `gobject-introspection-1.0.pc'
         to the PKG_CONFIG_PATH environment variable
         Package 'gobject-introspection-1.0', required by 'virtual:world', not found
         Command '('pkg-config', '--print-errors', '--exists', 'gobject-introspection-1.0 >= 1.56.0')' returned non-zero exit status 1.
         
         Try installing it with: 'sudo dnf install gobject-introspection-devel'
         ----------------------------------------
         ERROR: Failed building wheel for PyGObject
       Failed to build PyGObject
       ERROR: Could not build wheels for PyGObject which use PEP 517 and cannot be installed directly

* Fix it

  ..  code-block:: console

      $ sudo dnf install gobject-introspection-devel

* Next, Gosh! ``cairo-gobject-devel``
		  
  .. code-block:: console

     $ pip install PyGObject
     Collecting PyGObject
       Using cached PyGObject-3.40.1.tar.gz (714 kB)
       Installing build dependencies ... done
       Getting requirements to build wheel ... done
         Preparing wheel metadata ... done
     Collecting pycairo>=1.16.0
       Using cached pycairo-1.20.1-cp39-cp39-linux_x86_64.whl
     Building wheels for collected packages: PyGObject
       Building wheel for PyGObject (PEP 517) ... error
       ERROR: Command errored out with exit status 1:
        command: /home/jfasch/venv/openheating/bin/python /home/jfasch/venv/openheating/lib64/python3.9/site-packages/pip/_vendor/pep517/in_process/_in_process.py build_wheel /tmp/tmp56g_ixbz
            cwd: /tmp/pip-install-bvay4iv4/pygobject_6777f13e15934fb2b13139399b143557
       Complete output (44 lines):
       running bdist_wheel
       running build
       running build_py
       creating build
       creating build/lib.linux-x86_64-3.9
       creating build/lib.linux-x86_64-3.9/pygtkcompat
       copying pygtkcompat/pygtkcompat.py -> build/lib.linux-x86_64-3.9/pygtkcompat
       copying pygtkcompat/generictreemodel.py -> build/lib.linux-x86_64-3.9/pygtkcompat
       copying pygtkcompat/__init__.py -> build/lib.linux-x86_64-3.9/pygtkcompat
       creating build/lib.linux-x86_64-3.9/gi
       copying gi/types.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/pygtkcompat.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/module.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/importer.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/docstring.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_signalhelper.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_propertyhelper.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_ossighelper.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_option.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_gtktemplate.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_error.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/_constants.py -> build/lib.linux-x86_64-3.9/gi
       copying gi/__init__.py -> build/lib.linux-x86_64-3.9/gi
       creating build/lib.linux-x86_64-3.9/gi/repository
       copying gi/repository/__init__.py -> build/lib.linux-x86_64-3.9/gi/repository
       creating build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/keysyms.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/__init__.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/Pango.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/Gtk.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/Gio.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/GdkPixbuf.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/Gdk.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/GObject.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/GLib.py -> build/lib.linux-x86_64-3.9/gi/overrides
       copying gi/overrides/GIMarshallingTests.py -> build/lib.linux-x86_64-3.9/gi/overrides
       running build_ext
       Package cairo-gobject was not found in the pkg-config search path.
       Perhaps you should add the directory containing `cairo-gobject.pc'
       to the PKG_CONFIG_PATH environment variable
       Package 'cairo-gobject', required by 'virtual:world', not found
       Command '('pkg-config', '--print-errors', '--exists', 'cairo-gobject >= 0')' returned non-zero exit status 1.
       
       Try installing it with: 'sudo dnf install cairo-gobject-devel'
       ----------------------------------------
       ERROR: Failed building wheel for PyGObject
     Failed to build PyGObject
     ERROR: Could not build wheels for PyGObject which use PEP 517 and cannot be installed directly

* Fix

  .. code-block:: console

     $ sudo dnf install cairo-gobject-devel

* Finally, yay!

  .. code-block:: console

     $ pip install PyGObject

* TODO: executive summary

  ``$ dnf install all packages``

Finish Meta/SEO and Stuff
-------------------------

* todo

  * style

    * <li> spacing
    * nested lists: space before less than after
    * /trainings/index.rst: only overview over topics, for example "C"
      (-> C1,2,3), "Sysprog" -> sysprog*, "Embedded" ->
      sysprog-embedded, raspi-hands-on, "misc" -> kernel

  * title page:
    https://www.w3schools.com/howto/howto_css_image_transparent.asp

  * courses

    * meta += see also (bisher gehaltene, unterlagen)

    * schulungen zentraler

      * auf der titelseite in die mitte
      * courses/index knackiger
      * image mit text:
        https://www.w3schools.com/howto/howto_css_image_transparent.asp

    * records

      * https://www.w3schools.com/howto/howto_js_read_more.asp
      * material in subdir (gegen menu clutter)

  * 404 not found -> link to co.at oder so

* seo/meta

  * Low prio

    * ``courses/booking.rst``
    * ``courses/programming-languages/index.rst``
    * ``courses/material/sysprog/signals-slides.rst``
    * ``courses/material/sysprog/ipc-slides.rst``

  * ``blog/2010/07/beagleboard-how-to-repair-nand-also-known-as-40w.rst``
  * ``blog/index.rst``
  * ``blog/2020/03/custom-domain-gh-pages.rst``
  * ``blog/2020/03/sphinx-gh-pages.rst``
  * ``blog/2020/02/fedora-kernel-build.rst``
  * ``blog/2012/04/Why-ps-sucks.rst``
  * ``blog/2011/01/saving-solid-state-disk-life--gentoo.rst``
  * ``blog/2011/01/porting-to-linux-there-s-always-a-better-way.rst``
  * ``index.rst``
  * ``about/myself/index.rst``
  * ``about/myself/cv-de.rst``
  * ``about/myself/projects-de.rst``
  * ``about/myself/skills-de.rst``
  * ``about/myself/contact.rst``
  * ``about/site/index.rst``
  * ``about/site/recipes.rst``
  * ``about/site/work-in-progress/layout-test.rst``
  * ``about/site/work-in-progress/todo-misc.rst``
  * ``about/site/work-in-progress/index.rst``
  * ``about/site/work-in-progress/stacks.rst``
  * ``about/site/work-in-progress/seo.rst``
  * ``about/site/work-in-progress/blog-queue/index.rst``
  * ``about/site/work-in-progress/blog-queue/github-pages-custom-domains-ssl-bad-certificate.rst``
  * ``about/site/work-in-progress/s5/tests/test-slides.rst``
  * ``about/site/work-in-progress/s5/tests/index.rst``
  * ``about/site/work-in-progress/s5/index.rst``
  * ``courses/linux/070-sysprog-fortgeschrittenes.rst``
  * ``courses/linux/700-kettner-lfs-descr.rst``
  * ``courses/linux/050-sysprog-network.rst``
  * ``courses/linux/200-raspi-hands-on.rst``
  * ``courses/linux/index.rst``
  * ``courses/linux/080-sysprog-embedded.rst``
  * ``courses/linux/020-sysprog-basics.rst``
  * ``courses/linux/060-sysprog-multithreading.rst``
  * ``courses/linux/_hidden/kettner-lfs-2013-09-16.rst``
  * ``courses/linux/010-linux-basics.rst``
  * ``courses/linux/190-kernel-programming-basics.rst``
  * ``courses/records/2020-01-10/Proposal.rst``
  * ``courses/records/2020-01-10/index.rst``
  * ``courses/records/2013-10-01/index.rst``
  * ``courses/records/index.rst``
  * ``courses/records/2019-11-12/index.rst``
  * ``courses/records/2020-03-30/index.rst``
  * ``courses/records/2019-10-28/index.rst``
  * ``courses/index.rst``
  * ``courses/programming-misc/index.rst``
  * ``courses/programming-misc/020-make.rst``
  * ``courses/programming-misc/030-svn.rst``
  * ``courses/programming-misc/050-design-patterns.rst``
  * ``courses/programming-misc/040-unittests.rst``

