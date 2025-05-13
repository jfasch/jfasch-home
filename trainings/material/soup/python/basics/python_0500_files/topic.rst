.. include:: <mmlalias.txt>


File I/O
========

.. contents::
   :local:

Python 2 vs. Python 3
---------------------

**Encoding, again: incompatibility alert!**

* Python 2 already had types ``str`` and ``bytes``
* ... it just didn't make a difference
* Files are inherently binary, at the lowest level
* ... and so were Python 2's files
* Python 3 won't let you mix ``str`` and ``bytes``
* Hard rule: "Transform to string as early as possible"
* |Longrightarrow| Transformation must be done inside file I/O
* |Longrightarrow| Files know about their encoding
* |Longrightarrow| Python 2 vs. Python 3

Opening Files
-------------

**Files are opened** to obtain a *handle*

.. code-block:: python

   f = open('/etc/passwd')

* ``f`` refers to an *open file*
* Buffered IO (as ``stdio`` in C)
* Read-only (the default)
* Python 3: UTF-8 encoded (the default, unless otherwise specified)
* |longrightarrow| I/O is done in units of *strings*

.. code-block:: python
   :caption: Specifying an encoding

   f = open('/etc/passwd', encoding='ascii')

Reading Files
-------------

.. list-table::
   :align: left

   * - ``f.read()``
     - reads entire file content
   * - ``f.read(n)``
     - reads ``n`` characters/bytes
   * - ``f.readline()``
     - reads a line, *including* the terminating linefeed
   * - ``f.readlines()``
     - reads entire file |longrightarrow| list of lines

.. code-block:: python
   :caption: Note the end-of-file condition

   while True:
       line = f.readline()
       if len(line) == 0:
           break
       print(line)

.. code-block:: python
   :caption: Shorter but less resource-friendly

   for line in f.readlines():
       print(line)

Reading Files: Pythonic
-----------------------

**Iteration** is a central theme in Python

* Readability
* *Iterable*: anything that can be iterated
* Many things can be iterated
* Fine-tunable behaviour and performance
* Why shoudn't we iterate files?

.. code-block:: python

   for line in f:
       print(line)

Writing Files (1)
-----------------

.. code-block:: python
   :caption: Open file *write-only*

   f = open('/tmp/some-file', 'w')

.. code-block:: python
   :caption: Writing arbitrary content

   f.write('arbitrary content')

.. code-block:: python
   :caption: Writing multiple "lines"

   f.writelines(['one\n', 'two\n'])

.. code-block:: python
   :caption: Using ``print()``, linefeed added automatically

   print('one line (with automatic linefeed)', file=f)

Writing Files (2)
-----------------

**The beauty of iteration (again)** ...

* ``writelines()`` does *not* add linefeed (probably a misnomer)
* Items can come from any *iterable*
* |longrightarrow| *Very* cool!

.. code-block:: python
   :caption: Copying a file the Pythonic way

   src = open('/etc/passwd', 'r')
   dst = open('/tmp/passwd', 'w')
   
   dst.writelines(src)

File Modes
----------

**Available** ``mode`` **characters**

.. list-table::
   :align: left

   * - ``r``
     - open for reading (default)
   * - ``w``
     - open for writing, truncating the file first
   * - ``x``
     - open for exclusive creation, failing if the file already exists
   * - ``a``
     - open for writing, appending to the end of the file if it exists
   * - ``b``
     - binary mode (no encoding and decoding)
   * - ``t``
     - text mode (default)
   * - ``+``
     - open a disk file for updating (reading and writing)

**Combinations and their meanings**

.. list-table::
   :align: left

   * - ``w+``
     - read/write/truncate
   * - ``r+``
     - read/write (write pointer at beginning)
   * - ``a+``
     - read/write (write pointer at end)

Text vs. Binary Mode
--------------------

**Python 3 is Unicode clean**. For file I/O this means ...

* Cannot pass ``bytes`` to a file opened in text mode
* Cannot pass ``str`` to a file opened in binary mode
* Unless otherwise specified (``mode='b'``), files are in *text mode*

**Python 2 is not Unicode clean**

* ``mode='b'`` means "No stupid CR/LF conversion on Doze"
* ``bytes`` or ``str``, noone cares

Standard Streams
----------------

**Good Ol' Unix ...**

.. csv-table::
   :header: Number, POSIX Macro, Python equivalent

   0, ``STDIN_FILENO``, ``sys.stdin``
   1, ``STDOUT_FILENO``, ``sys.stdout``
   2, ``STDERR_FILENO``, ``sys.stderr``

* Interaktive Shell: all three associated with terminal
* Standard input and output used for I/O redirection and pipes
* Standard error receives errors, warnings, and debug output

.. important::

   *Windows-Programmers*: no errors, warnings, and debug output to
   *standard output*!!

.. code-block:: python
   :caption: Error and debug output goes to *standard error*

   print('An error occurred', file=sys.stderr)
