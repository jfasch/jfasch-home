.. include:: <mmlalias.txt>


Running Python Programs
=======================

The UNIX Way: *Executable* Bit, ``chmod``
-----------------------------------------

* In UNIX, file extensions have no special meaning
* Python programs generally don't have a ``.py`` extension
* Rather, programs are *executable* through their *mode*

.. code-block:: console
   :caption: Normal file (default mode 644)

   $ ls -l hello-unix
   -rw-r--r-- 1 jfasch jfasch 40 Jan 20 09:06 hello-unix

.. code-block:: console
   :caption: Executable file: mode 755 (executable by everybody)

   $ chmod 755 hello-unix
   $ ls -l hello-unix
   -rwxr-xr-x 1 jfasch jfasch 40 Jan 20 09:07 hello-unix

The UNIX Way: Hash-Bang (She-Bang)
----------------------------------

* Scripts (Shell, Python, Perl, AWK, ...) need an interpreter though

  * Only `ELF programs
    <https://en.wikipedia.org/wiki/Executable_and_Linkable_Format>`__
    run directly on the CPU

* *Interpreter line*, *Hash-Bang*, *She-Bang*: first line in a script,
  usually

  .. code-block:: python

     #!/usr/bin/python

     ... here goes Python code ...

* Sometimes ``python`` is Python 2 (on the Raspberry, for example)

  .. code-block:: python

     #!/usr/bin/python3
     ...

* In :doc:`Virtual Environments
  </trainings/material/soup/python/swdev/venv/topic>` things are different

  * Python interpreter is not ``/usr/bin/python``
  * ``python`` is taken from ``PATH`` setting of the environment

  .. code-block:: python

     #!/usr/bin/env python
     ...

The UNIX Way: Running
---------------------

* Prerequisites

  * Script is executable
  * Scripts has She-bang

.. literalinclude:: hello-unix
   :caption: :download:`hello-unix`

* UNIX uses ``$PATH`` environment variable to find programs
* Current working directory is not usually in ``$PATH``
* |longrightarrow| specify ``.`` explicitly

.. code-block:: console

   $ ./hello-unix
   Hello World

The Doze Way: Registry
----------------------

* In Doze, file extensions have special meaning
* In Doze, there is no executable bit, no mode
* ``.py`` files are executed by the Python interpreter

  * Extension not necessary when invoking

* How does the system know?

  * During Python installation, the installer registers the Python
    program as being responsible for ``.py``
  * Somewhere in the Windows registry.

* Doze always looks in the current working directory [#doze-security]_

.. literalinclude:: hello-doze.py
   :caption: :download:`hello-doze.py`

.. code-block:: console

   > hello-doze
   Hello World

.. rubric:: Footnotes

.. [#doze-security] Ain't that a security risk?
