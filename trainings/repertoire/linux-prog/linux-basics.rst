.. meta::
   :description: A Linux introduction for programmers, testers,
                 architects, hardware engineers
   :keywords: schulung, training, programming, embedded, linux, shell,
              bash, bourne shell, redirection, console, kill, ps, cat,
              less, pipe, filesystem, grep, debugging, scripting

Linux Basics: A Gentle Introduction
===================================

.. sidebar::
   :class: jf-course-description-sidebar

   .. grid:: 1

      .. grid-item-card:: Duration: 3 Days
      .. grid-item-card:: :doc:`/trainings/info`
      .. grid-item-card:: 
   
	 .. dropdown:: Related Courses

	    * :doc:`bash`
	    * :doc:`/trainings/repertoire/linux-prog/sysprog/index`

	 .. dropdown:: Slide Material

	    * :doc:`/trainings/material/soup/linux/basics/index`

This course is an introduction to the operating system and its strong
concepts. By using only the shell (no programming skills needed),
we'll learn how the system works.

Target Audience
---------------

* Programmers
* Testers
* Support personnel
* Hardware engineers
* ... or anybody who is interested in understanding the OS

Course Outline
--------------

* Commandline Basics

  * Editing a command
  * Completion: the TAB key
  * Variables and environment variables
  * The history buffer

* Filesystem

  * Directories, and path names
  * File types (symbolic links, device special files, ...)
  * Current working directory
  * Commands: ``ls``, ``cp``, ``mv``, ``find``
  * Filesystem permissions

* Text file handling

  * ``cat``, ``less``, ``diff``, ``grep``

* Pipes etc.

  * Standard filedescriptors: ``stdin``, ``stdout``, ``stderr``
  * IO redirection
  * Pipes and named pipes

* Tools, and their combination using the pipe

  * ``gzip``, ``tar``, in combination with e.g. ``find``
  * ``ssh``
  * Shell scripts

* Processes

  * Basics (including virtual memory)
  * Shell job control
  * System calls
  * ``ps``
  * ``top``
  * Signals
  * Scheduling

* Networking

  * Network status reporting (``ss``, and ``netstat``)
  * ``netcat``

Prerequisites
-------------

Programming skills are sure helpful but not required. Interest in and
fun with operating systems are required.
