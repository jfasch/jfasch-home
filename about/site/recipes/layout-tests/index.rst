Layout Tests
============

.. toctree::

   text-styles
   sidebar-slide-doc-seealso
   sidebar-fancy-course-descriptions
   sphinx-design-buttons

.. contents::
   :local:
   :depth: 1
   

Admonitions
-----------

Admonition
..........

.. admonition:: This is an ``.. admonition::``

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Tip
...

.. tip::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Note
....

.. note::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Hint
....

.. hint::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Important
.........

.. important::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Attention
.........

.. attention::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Caution
.......

.. caution::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Error
.....

.. error::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Danger
......

.. danger::

   blah blah blah blah blah blah blah blah blah blah blah blah blah

Sidebar
-------

.. sidebar:: Blech Sidebar Title Blah

   lorem ipsum hödlmoser und so weiter

Sidebars require a title anyway. Hmm. So the least annoying thing was
to have a transparent sidebar with a very thin border around it.

Sidebar "Course Data"
---------------------

.. sidebar::

   .. grid:: 1

      .. grid-item-card:: Duration: 5 Days
   
      .. grid-item:: 

         .. button-ref:: course-info
   	    :ref-type: ref
            :color: primary
	    :expand:

      .. grid-item:: 
   
	 .. dropdown:: Related Courses

            * :doc:`/trainings/repertoire/c-like/c-advanced`
            * :doc:`/trainings/repertoire/misc/unittests`

      .. grid-item:: 
   
	 .. dropdown:: Slide Material

            * :doc:`/trainings/material/soup/c/index`

Hmm. Should be an eye-catcher somehow.

blah blah blah blah blah blah Dieser Einführungskurs richtet sich an
Programmierer, die Linux nicht so sehr kennen, es aber kennen lernen
wollen. Die Zusammenhänge und die Grundpfeiler des Systems werden
erklärt, sodass man am Ende ein großes Bild hat und sich selbst
orientieren und zurechtfinden kann.  

blah blah blah blah blah blah blah blah blah blah blah blah blah blah
blah blah blah blah blah blah blah blah blah blah blah blah blah blah
blah blah blah blah blah blah blah blah blah blah blah blah blah blah
blah blah blah blah blah blah blah blah blah blah blah blah blah blah
blah blah blah blah blah blah blah blah blah blah blah

Local Content
-------------

.. contents::
   :local:

Local Heading 1
...............

Local Heading 1.1
`````````````````

Local Heading 1.2
`````````````````

Local Heading 2
...............

Sidebar with Local Content
--------------------------

Have to write an extension someday that provides me an extension for
that. Better yet, redefine the ``contents`` directive to wrap it in a
sidebar somehow. Anyway, that's how it looks.

.. sidebar:: Bleh Content Blah

   .. contents::
      :local:

Local Heading 1
...............

Local Heading 1.1
`````````````````

Local Heading 1.2
`````````````````

Local Heading 2
...............

To Do
-----

https://mdbootstrap.com/docs/jquery/content/icons-list/

