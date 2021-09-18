.. ot-topic:: python.basics.installation

Python Installation
===================

Setup
-----

The language itself consists of the Python interpreter itself, and a
rather complete set of *modules* (one says, "Python comes with
batteries included").

In the training we might look into *external* modules, such as `NumPy
<https://numpy.org/>`__ and/or `Pandas
<https://pandas.pydata.org/>`__, but installing these is not the focus
of the current topic  [#pip_venv]_.

.. note::

   While the training material covers Python versions 2 and 3 to a
   large extent, time has come to consider version 2 *obsolete*.

   **Please choose Python 3 when installing!**

For the matter of the training, for diadactical purposes, I suggest we
use the standard Python installation,

* Download Windows installer from `here
  <https://www.python.org/downloads/>`__, and go through the
  installation process. *Take care to check the "add python to path"*
  box.

  (For Linuxers, Python usually comes as part of your favorite
  distribution and is already installed.)
* If there is the need to install packages that are not contained in
  Python's own set of packages, we will install them using ``pip``.

Data scientists often use a *distribution* named `Anaconda
<https://www.anaconda.com/>`__ which brings the standard Python
installation and a large set of set of pre-packaged external
extensions [#anaconda_r]_ . If you are already familiar with Anaconda,
then I don't object.

Programming Environment
-----------------------

As we are all programmers to a certain extent, we know what tools to
use. For example, the training does not dictate which IDE (or editor)
a participant uses. The exercises are not voluminous enough to justify
that, after all; a simple text editor like Nodepad++ is sufficient.

That said, here's a list of IDEs/editors that are frequently used for
Python programming. It is in no particular order, and far from being
complete.

* `Visual Studio Code <https://code.visualstudio.com/>`__. See
  :doc:`here <../draft/vscode>` for more.
* `PyCharm <https://www.jetbrains.com/pycharm/>`__. I frequently see
  people use it, so it cannot be all that bad.
* `Eclipse <https://www.eclipse.org/>`__ and `PyDev
  <http://pydev.org/>`__. Definitely a heavy weight (regarding memory
  footprint at least) among IDEs, Eclipse knows how to handle Python.
* `Spyder <https://www.spyder-ide.org/>`__. It is used by data
  scientists a lot. Running code in it feels like a `Jupyter Notebook
  <https://jupyter.org/>`__ execution in that there are seemingly
  strange "cell" like dependencies. (Take this into account when you
  decide to go with it.)
* `Emacs <https://www.gnu.org/software/emacs/>`__. (I had to say
  that.) Your trainer will use it to do occasional live hacking
  demos. Watching someone use it is ok, but learning how to use it
  requires a nontrivial amount of patience.

.. rubric:: Footnotes

.. [#anaconda_r] Anaconda also packages the `R
                 <https://www.r-project.org/>`__ language which is
                 also heavily used by data scientists.
.. [#pip_venv] See :doc:`../draft/pip/topic` and :doc:`../draft/venv/topic` for how to
               install external packages.


