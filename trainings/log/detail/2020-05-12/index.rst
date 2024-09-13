.. meta::
   :description: Vor- und Nachbearbeitung eines zweitägigen Python
                 Trainings
   :keywords: schulung, training, programming, python

Python Grundlagen (13.5.2020 - 14.5.2020 bei einer Firma in Graz)
=================================================================

.. toctree::
   :hidden:

   code/index

.. sidebar:: *Information*

   **Table of Contents**

   .. contents::
      :local:

   **Date, Location**

   * Wednesday 13.5.2020 8:30, and Thursday
   * Location: `Zoom Meeting <https://zoom.us/>`__

   **Slides**

   * :doc:`/trainings/material/soup/python/basics/group`
   * :download:`Unittesting
     </trainings/material/pdf/060-design-patterns-unittests.pdf>`
     (PDF)
   * :doc:`/trainings/material/soup/python/swdev/unittest`

   **Training Description**

   * :doc:`/trainings/material/soup/python/basics/group`
   * :doc:`/trainings/material/soup/python/swdev/group`

   **Code**

   Coding will be done in a git clone of this homepage, in a
   :doc:`sandbox <code/index>` dedicated to this training.

Environment
-----------

We will try to follow a draft plan, based upon up-front
discussion. Please don't take this as a hard rule - we will take
ourselves the freedom to spontaneously go deeper into one topic, at
the cost of another.

Unit Testing and Test Driven Development
........................................

Part of the requirements was to spend a few words on unit testing and
test driven development. I take the opportunity to kind of invert the
training scenario, into something that comes into being using the
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
.......................

As we are all programmers to a certain extent, we know what tools to
use. For example, the training does not dictate which IDE (or editor)
a participant uses. The exercises are not voluminous enough to justify
that, after all; a simple text editor like Nodepad++ is sufficient.

That said, here's a list of IDEs/editors that are frequently used for
Python programming. It is in no particular order, and far from being
complete.

* `Visual Studio Code <https://code.visualstudio.com/>`__. Not to be
  confused with Visual Studio, Visual Studio Code is actually a modern
  text editor, not an IDE. Together with its configurabilty, it can be
  turned into one, but by itself does not dictate anything upon the
  user.
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

Topics
------

.. _envisioned-topics:

Day 1: Language Basics
......................

* Unit testing and Test Driven Development (preparing the basics for
  the remainder of the training)
* Very basics: syntax, datatypes, variables
* Control flow constructs: ``if``, ``while``, ``for``
* Complex datatypes: ``list``, ``set``, ``dict``
* *Mutability* and *immutabiliy*: ``tuple``
* Functions and parameter passing
* Closures
* Iteration and Generators

Day 2: Advanced Topics
......................

* More about *slicing*, and about its use in `NumPy
  <https://numpy.org/>`__
* Exception handling
* Modules and packages ("namespaces")
* Maybe a larger group exercise, to consolidate news from two days.

Wrap-Up
-------

How Was It?
...........


The training was done online on `Zoom <https://zoom.us/>`__, due to
the Corona crisis. This was my second online experience (first one is
:doc:`here <../2020-03-30/index>`), and I must say online is not much
different from face-to-face. Questions were asked at a normal rate,
nobody slept over (at least I did not see anybody falling from their
chairs). I would have liked to see faces more, though, and I am
definitely missing the off-topic communication during breaks and
lunch. All in all, though, I definitely can say that there is no
reason to not do trainings online.

That said, we probably tried to squeeze a little too much into only
two days. To make the bigger part of the audience more happy, we
should have probably explicitly agreed to strip basics (which the plan
had dedicated day one to), at the cost of some in the audience who
were not so advanced. Such things happen from time to time in
trainings, it would appear that it's the trainer's job to detect such
situations more early. My takeaway is that it is very important to
state facts clearly and *early*, especially in settings where you
cannot rely on your nonverbal antennae.

Topics
......

Being a stubborn greybeard though, I use to insist in bringing big
pictures (which Python's iteration, (im)mutability, and ``exec()``
belong to, among others), which I definitely did.

Day two was dedicated to a walk through the ``unittest`` module,
together with a sketch of what Test Driven Development could do for
you. We thereby saw what Python *modules* and *packages* are, and how
modularization is done in Python. ``$PYTHONPATH`` and such. To wrap
this up, the sketch ended with a discussion of ``distutils``. We saw
what a ``setup.py`` file adds, and discussed what (possibly
continuous?) integration and deployment is at such a small
scale. (Probably Azure DevOps is a rather heavyweight solution to that
little local problem; it might solve problems that kept out of reach
of this little local training though.)

Later in the afternoon of day two, we were only able to scratch the
surface of parallel programming (not among the agreed topics) by
discussing how threading is done in Python. We saw how the Global
Interpreter Lock (GIL) enables simplicity, but also makes true
parallism nearly impossible.

Some topics have only been covered on their surface, others not at
all. Clearly two days can't have it all, so what follows is a list of
YouTube links. Opinionated recommendations of mine to expand all those
topics that would have been interesting to cover, but which we haven't
had the time for.

Links
.....

My favorite Python videos are those that are both entertaining and
informative, and long. Among those, many are by **David Beazley** (a
freelance trainer who teaches Python) and **Raymond Hettinger** (same,
in addition to being a Python core developer). I am slightly biased
towards Beazley because I like his sense of humor.

For short and to-the-point tutorials, below, I recommend (and cite
below) **Corey Schafer** (for general topics), and **Keith Galli** for
data science.

Anyway, here a couple of links

* `Modern dictionaries
  <https://www.youtube.com/watch?v=p33CVV29OG8>`__: **Raymond
  Hettinger** emphasizing on dictionaries, even more than
  I did. (Hehe, I just discovered that he's bringing my quick hash
  table explanation to a conclusive end. Hard stuff for the unaware
  though.)
* `Understanding the Python GIL
  <https://www.youtube.com/watch?v=Obt-vMVdM8s>`__: **David Beazley**
  dissecting the Global Interpreter Lock, explaining why
  multiprocessing is better. At around minute 45, in the
  questions/answers, there a mention that using NumPy operations in
  multiple threads is *truly parallel*.
* `Concurrency <https://www.youtube.com/watch?v=9zinZmE3Ogk>`__:
  **Raymond Hettinger** covering most if not all aspects and
  possiblities of concurrency. Very informative, very concise,
  covering

  * Multithreading
  * Multiprocessing
  * Async; I didn't even mention that. `asyncio
    <https://docs.python.org/3/library/asyncio.html>`__. Me big fan.

* `Modules and Packages
  <https://www.youtube.com/watch?v=0oTh1CXRaQ0>`__. **David Beazley**
  has a three hour (!) *really cool and in-depth* look into the
  seemingly simple ``import`` mechanism.
* `Unit Testing <https://www.youtube.com/watch?v=6tNS--WetLI>`__:
  **Corey Schafer** (he has a number of really good *and* short
  tutorial videos; look out for him as you search).
* `Virtual Environments Tutorial
  <https://www.youtube.com/watch?v=APOPm01BVrk>`__: **Corey Schafer**
  again. Virtual environments are kind of an isolated development
  sandbox, solving a similar problem as containers do, but much more
  lightweight and Python only.
* `Packaging, Deployment, PyPI, and pip
  <https://www.youtube.com/watch?v=P3dY3uDmnkU>`__: **Chris Wilcox**
  (of Google) talking about packaging and deployment, and related
  topics
* `Generators Tutorial
  <https://www.youtube.com/watch?v=bD05uGo_sVI>`__: **Corey Schafer**
  again, this time 11 minutes on generators.
* `Generators: The Final Frontier
  <https://www.youtube.com/watch?v=D1twn9kLmYg>`__: **David Beazley**,
  again a bit (a whopping four hours) more precise on that topic.
* `Decorators Tutorial
  <https://www.youtube.com/watch?v=FsAPt_9Bf3U>`__: **Corey Schafer**
  on decorators and closures.
* `NumPy Tutorial <https://www.youtube.com/watch?v=GB9ByFAIAH4>`__:
  **Keith Galli** has a number of good **data science** tutorials.
* :doc:`Here <../2019-11-12/index>` and :doc:`here
  <../2019-11-12/code/BigPlan>` you might want to read up on another
  Python training I gave last year; **me** getting in touch with
  `NumPy <https://numpy.org/>`__ more closely.
* `Simulating COVID-19 using Python, NumPy & Matplotlib
  <https://www.youtube.com/watch?v=KAmZe5D3v5I>`__: finishing the
  list, I found that funny. Apart from that, it is a good live hacking
  session that brings it all together. You might like `Matplotlib
  <https://matplotlib.org/>`__, btw.

.. rubric:: Footnotes

.. [#anaconda_r] Anaconda also packages the `R
                 <https://www.r-project.org/>`__ language which is
                 also heavily used by data scientists.

