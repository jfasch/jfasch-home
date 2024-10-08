Design Tools And Laboratory Engineering: Intro
==============================================

.. contents::
   :local:

.. sidebar:: Work Environment

   A VirtualBox image with Debian Linux is provided
   

C And C++
---------

C: Structures, Pointers And Arrays
..................................

From :doc:`/trainings/material/soup/c/060-structures/group` ...

* :doc:`/trainings/material/soup/c/060-structures/010-basics-of-structures/topic`
* :doc:`/trainings/material/soup/c/060-structures/020-structures-and-functions/topic`

From :doc:`/trainings/material/soup/c/050-pointers-and-arrays/group` ...

* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/010-pointers-and-addresses/topic`
* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/020-pointers-and-function-arguments/topic`
* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/030-exercise-swap/topic`
* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`

C++: A Better C?
................

From :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group` ...

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`

From
:doc:`/trainings/material/soup/cxx03/030-functions-and-methods/group` ...

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`

From :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group` ...

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

Recommended Readings, Links
...........................

* Bjarne Stroustrup: The C++ Programming Language (Fourth Edition),
  Addison-Wesley (`PDF
  <https://chenweixiang.github.io/docs/The_C++_Programming_Language_4th_Edition_Bjarne_Stroustrup.pdf>`__)
* `C++ Tutorial for Beginners - Full Course
  <https://youtu.be/vLnPwxZdW4Y?si=T-myWFs4zt9ekbf0>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/vLnPwxZdW4Y?si=T-myWFs4zt9ekbf0" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

Linux Basics
------------

Filesystem Commands
...................

From :doc:`/trainings/material/soup/linux/basics/shell/group` ...

* :doc:`/trainings/material/soup/linux/basics/shell/commandline`
* :doc:`/trainings/material/soup/linux/basics/shell/paths`
* :doc:`/trainings/material/soup/linux/basics/shell/special-paths`
* :doc:`/trainings/material/soup/linux/basics/shell/ls`
* :doc:`/trainings/material/soup/linux/basics/shell/cwd`
* :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
* :doc:`/trainings/material/soup/linux/basics/shell/cp`
* :doc:`/trainings/material/soup/linux/basics/shell/mv`

Exercises
.........

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/mkdir-p-rm-r`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-create-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-copy-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-move-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/copy-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-rf`

More Commands
.............

From :doc:`/trainings/material/soup/linux/basics/text-tools/group`

* :doc:`/trainings/material/soup/linux/basics/text-tools/cat`
* :doc:`/trainings/material/soup/linux/basics/text-tools/head-tail`
* :doc:`/trainings/material/soup/linux/basics/text-tools/cut`

.. TODO head und tail

.. cat as nop filter file:///tmp/jfasch-home/html/trainings/material/soup/linux/basics/text-tools/cat.html
.. file:///tmp/jfasch-home/html/trainings/material/soup/linux/basics/text-tools/overview.html
.. from stdin :doc:`/trainings/material/soup/linux/basics/text-tools/head-tail`
.. /etc/passwd * :doc:`/trainings/material/soup/linux/basics/text-tools/cut`

Exercises
.........

#. Output the first two lines of ``/etc/passwd``
#. Output the third line of ``/etc/passwd`` (Note: use head and tail
   in a pipe)

OS Concepts: File System Permissions
....................................

* :doc:`/trainings/material/soup/linux/basics/permissions/basics`

Exercises
.........

From
:doc:`/trainings/material/soup/linux/basics/permissions/exercises/group` ...

* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/credentials`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/shared-file`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory-question`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory-question`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/fh-questions`

Recommended Readings, Links
...........................

* Willian E. Shotts: The Linux Command Line, 2nd Edition: A Complete
  Introduction 1st Edition, no starch press (`Amazon
  <https://www.amazon.com/Linux-Command-Line-Complete-Introduction/dp/1593273894>`__)
* `Linux Command-Line for Beginners: Your First 5 Minutes
  <https://youtu.be/id3DGvljhT4?si=PVgFncafJCy8CgaO>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/id3DGvljhT4?si=PVgFncafJCy8CgaO" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `Linux Commandline: Full Course <https://youtu.be/5jIIOkA0NpI?si=V0tNpDqphK095RLn>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/5jIIOkA0NpI?si=V0tNpDqphK095RLn" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

