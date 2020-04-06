Python Grundlagen (12.5.2020 - 14.5.2020 bei einer Firma in Graz)
=================================================================

.. toctree::
   :hidden:

.. sidebar:: *Information*

   **Table of Contents**

   .. contents::
      :local:

   * Monday 12.5.2020
   * Location: to be defined [#maybe_online]_

   **Slides**

   * :download:`Python </trainings/material/pdf/300-python.pdf>` (PDF)
   * :download:`Unittesting
     </trainings/material/pdf/060-design-patterns-unittests.pdf>`
     (PDF)

   **Training Descriptions**

   * :doc:`/trainings/repertoire/python-basics`
   * :doc:`/trainings/repertoire/python-advanced`

Culture
-------

Based upon up-front discussion, I came up with draft plan (see below)
as to how the structure of our two days Python training will look
like. Please don't take this as a hard rule - we will take ourselves
the freedom to spontaneously go deeper into one topic, at the cost of
another.

Unit Testing and Test Driven Development
........................................

Part of the requirements was to lose a few words about unit testing
and test driven development. I take the opportunity to kind of invert
the training scenario, into something that comes into being using the
basis of all *agile* methodologies. Exercises will not have textual
descriptions, for example, but will be formulated as unit tests that
initially fail (naturally).

Python Installation
...................

The language itself consists of the Python interpreter itself, and a
rather complete set of *modules* (one says, "Python comes with
batteries included"). This - the *python installation* - is the
primary focus of this training. We might look into `NumPy
<https://numpy.org/>`__ and/or `Pandas <https://pandas.pydata.org/>`__
a bit.

.. note::

   While the training material covers Python versions 2 and 3, time
   has come to consider version 2 *obsolete*.

   **Please choose Python 3 when installing!**

For the matter of this training, for diadactical purposes, I suggest
we use the standard Python installation,

* Download Windows installer from `here
  <https://www.python.org/downloads/>`__, and go through the
  istallation process. *Take care to check the "add python to path"*
  box.

  (For Linuxers, Python usually comes as part of your favorite
  distribution and is already installed.)
* If there is the need to install packages that are not contained in
  Python's own set of packages, we will install them using ``pip``.

Data scientists often use a *distribution* named `Anaconda
<https://www.anaconda.com/>`__ which brings the standard Python
installation and a large pre-packaged set of external extensions
[#anaconda_r]_ . If you are already used to Anaconda, then I don't
object.

Programming Environment
.......................

As we are all programmers to a certain extent, we know what tools to
use. For example, the training does not dictate which IDE (or editor)
a participant uses. The exercises are not voluminous enough to justify
that, after all; a simple text editor like Nodepad++ is sufficient.

That said, here's a list of IDEs/editors that are frequently used for
Python programming. It is in no particular order, and far from being
complete.

* `PyCharm <https://www.jetbrains.com/pycharm/>`__. I frequently see
  people use it, so it cannot be all that bad.
* `Eclipse <https://www.eclipse.org/>`__ and `PyDev
  <http://pydev.org/>`__. Definitely a heavy weight (regarding memory
  footprint at least) among IDEs, Eclipse knows how to handle Python.
* `Visual Studio Code <https://code.visualstudio.com/>`__. Not to be
  confused with Visual Studio, Visual Studio Code is actually a modern
  text editor, not an IDE. Together with its configurabilty, it can be
  turned into one, but by itself does not dictate anything upon the
  user.
* `Spyder <https://www.spyder-ide.org/>`__. It is used by data
  scientists a lot. Running code in it feels like a `Jupyter Notebook
  <https://jupyter.org/>`__ execution in that there are seemingly
  strange "cell" like dependencies. (Take this into account when you
  decide to go with it.)
* `Emacs <https://www.gnu.org/software/emacs/>`__. (I had to say
  that.) You trainer will use it to do occasional live hacking
  demos. Watching someone use it is ok, but learning how to use it
  requires a nontrivial amount of patience.

Topics
------

Day 1: Language Basics
......................

* Unit testing and Test Driven Development (preparing the basics for
  the remainder of the training)
* Very basics: syntax, datatypes, variables
* Control flow constructs: ``if``, ``while``, ``for``
* Complex datatypes: ``list``, ``set``, ``dict``
* *Mutability* and *immutabiliy*: ``tuple``
* Iteration and Generators

Day 2: Advanced Topics
......................

* More about *slicing*, and about its use in `NumPy
  <https://numpy.org/>`__
* Exception handling
* Modules and packages ("namespaces")
* Maybe a larger group exercise, to consolidate news from two days.

.. rubric:: Footnotes

.. [#maybe_online] It is still undecided whether we will meet in
                   person or online.
.. [#anaconda_r] Anaconda also packages the `R
                 <https://www.r-project.org/>`__ language which is
                 also heavily used by data scientists.
