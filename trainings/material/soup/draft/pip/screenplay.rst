Python Package Index (Livehacking Screenplay)
=============================================

.. contents::
   :local:

Invocation
----------

.. code-block:: console
   :caption: ``pip`` program

   $ pip --version
   pip 19.3.1 from /usr/lib/python3.8/site-packages/pip (python 3.8)

.. code-block:: console
   :caption: Import module as ``__main__``

   $ python -m pip --version
   pip 19.3.1 from /usr/lib/python3.8/site-packages/pip (python 3.8)

* Takes the version out
* ``python`` dictates version, importing module ``pip`` that was
  installed together with Python
* Will use that invocation because more correct, and emphasizes the
  mechanism

Help
----

.. code-block:: console

   $ python -m pip --help
   
   Usage:   
     /usr/bin/python -m pip <command> [options]
   
   Commands:
     install                     Install packages.
     download                    Download packages.
     uninstall                   Uninstall packages.
     freeze                      Output installed packages in requirements format.
     list                        List installed packages.
     show                        Show information about installed packages.
     check                       Verify installed packages have compatible dependencies.
     config                      Manage local and global configuration.
     search                      Search PyPI for packages.
     wheel                       Build wheels from your requirements.
     hash                        Compute hashes of package archives.
     completion                  A helper command used for command completion.
     debug                       Show information useful for debugging.
     help                        Show help for commands.
   
   General Options:
     -h, --help                  Show help.
     --isolated                  Run pip in an isolated mode, ignoring environment variables and user configuration.
     -v, --verbose               Give more output. Option is additive, and can be used up to 3 times.
     -V, --version               Show version and exit.
     -q, --quiet                 Give less output. Option is additive, and can be used up to 3 times (corresponding to WARNING, ERROR, and CRITICAL logging levels).
     --log <path>                Path to a verbose appending log.
     --proxy <proxy>             Specify a proxy in the form [user:passwd@]proxy.server:port.
     --retries <retries>         Maximum number of retries each connection should attempt (default 5 times).
     --timeout <sec>             Set the socket timeout (default 15 seconds).
     --exists-action <action>    Default action when a path already exists: (s)witch, (i)gnore, (w)ipe, (b)ackup, (a)bort.
     --trusted-host <hostname>   Mark this host or host:port pair as trusted, even though it does not have valid or any HTTPS.
     --cert <path>               Path to alternate CA bundle.
     --client-cert <path>        Path to SSL client certificate, a single file containing the private key and the certificate in PEM format.
     --cache-dir <dir>           Store the cache data in <dir>.
     --no-cache-dir              Disable the cache.
     --disable-pip-version-check
                                 Don't periodically check PyPI to determine whether a new version of pip is available for download. Implied with --no-index.
     --no-color                  Suppress colored output

Most Used Subcommands
.....................

* ``search``
* ``install``

  * ``-U, --upgrade``
  * ``--user``

* ``uninstall``

  * ``--user``

* ``list``

  * ``-o, --outdated``
  * ``--user``

Subcommand Help
...............

.. code-block:: console

   $ python -m pip list --help

System vs. User
---------------

.. code-block:: console

   $ python -m pip install numpy
   Collecting numpy
     Using cached https://files.pythonhosted.org/packages/c7/44/e17846ef3601dcb6f118ea447439650e0c35cb4fe60274fbe24214156df2/numpy-1.19.1-cp38-cp38-manylinux2010_x86_64.whl
   Installing collected packages: numpy
   ERROR: Could not install packages due to an EnvironmentError: [Errno 13] Permission denied: '/usr/local/lib64/python3.8'
   Consider using the `--user` option or check the permissions.

.. code-block:: console

   $ python -m pip install --user numpy
   Collecting numpy
     Using cached https://files.pythonhosted.org/packages/c7/44/e17846ef3601dcb6f118ea447439650e0c35cb4fe60274fbe24214156df2/numpy-1.19.1-cp38-cp38-manylinux2010_x86_64.whl
   Installing collected packages: numpy
   Successfully installed numpy-1.19.1

Ends up in ``~/.local``

.. code-block:: console

   $ python -m pip install numpy

Search
------

.. code-block:: console

   $ pip search numpy
   numpy (1.19.1)                            - NumPy is the fundamental package for array computing with Python.
     INSTALLED: 1.19.1 (latest)
   numpy-cloud (0.0.5)                       - Numpy in the cloud
   numpy-ext (0.9.3)                         - numpy extension
   numpy-utils (0.1.6)                       - NumPy utilities.
   ... lotsa ...

Somehow sorted by relevance. Alas, ``numpy`` is an exact hit.

List
----

.. code-block:: console
   :caption: All system packages

   $ python -m pip list
   Package            Version   
   ------------------ ----------
   argcomplete        1.10.0    
   argh               0.26.1    
   asn1crypto         1.3.0     
   ...

.. code-block:: console
   :caption: Outdated system packages

   $ python -m pip list --outdated
   Package         Version    Latest       Type 
   --------------- ---------- ------------ -----
   argcomplete     1.10.0     1.12.0       wheel
   argh            0.26.1     0.26.2       wheel
   asn1crypto      1.3.0      1.4.0        wheel
   ...

.. code-block:: console
   :caption: All user packages

   $ python -m pip list --user
   Package Version
   ------- -------
   numpy   1.19.1 

.. code-block:: console
   :caption: outdated user packages

   $ python -m pip list --user --outdated
