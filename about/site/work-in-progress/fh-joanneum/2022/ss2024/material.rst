.. include:: <mmlalias.txt>


Embedded Computing 1 (STECE-2022): Material
===========================================

.. contents::
   :local:

.. sidebar:: Github Project

   * Github project: https://github.com/jfasch/FH-STECE2022

.. sidebar:: Documentation

   * `VSCode: Developing in WSL
     <https://code.visualstudio.com/docs/remote/wsl>`__
   * `VSCode: Remote Development using SSH
     <https://code.visualstudio.com/docs/remote/ssh>`__

Block 1: Linux, and Working With Remote/Embedded Devices
--------------------------------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Date
     * #Units
     * Topics
   * * 2024-03-04
     * 6
     * 
       * **Quiz**

	 * `Moodle: how much I like my studies
           <https://moodle-23-24.fh-joanneum.at/mod/feedback/view.php?id=47767>`__
	 * `Moodle: how good I program
           <https://moodle-23-24.fh-joanneum.at/mod/feedback/view.php?id=47929>`__

       * **Intro: Course Contents**

	 * Raspberry Pi: Not-So-Embedded Linux System

	   * SSH login on the Pi: ``ssh -p 2020
             firstname.lastname@jfasch.bounceme.net`` (and activate
             camera; see :doc:`here </about/site/recipes/camera-ssh>`)
	   * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
	   * `Sysfs GPIO (deprecated)
             <https://www.kernel.org/doc/Documentation/gpio/sysfs.txt>`__
	   * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`
	   * Outlook: project in winter semester (:doc:`gluehwein`)

	 * Writing my own programs to combine functionality, and add
           logic

	   * On PC, read CPU temperatures |longrightarrow|
             https://github.com/jfasch/FH-STECE2022/blob/main/datalogger.cpp

       * **Homework**

	 Working
	 :doc:`/trainings/material/soup/linux/basics/intro/wsl`
	 installation until next time around.

   * * 2024-03-21
     * 6
     *
       * **Intro: Course Contents (cont'd)**

	 Data logger: https://github.com/jfasch/FH-STECE2022/blob/main/datalogger.cpp

	 * Cross compilation, and deployment
	 * System interaction from the shell

	   * ``cat``?
	   * ``strace``!

	 * And Python?

       * **OS Concepts** (from
         :doc:`/trainings/material/soup/linux/basics/intro/group`)

         * :doc:`/trainings/material/soup/linux/basics/intro/overview`
         * :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file`
         * :doc:`/trainings/material/soup/linux/basics/intro/process`
         * :doc:`/trainings/material/soup/linux/basics/intro/process-tree`

       * **Shell Usage** (from
         :doc:`/trainings/material/soup/linux/basics/shell/group`)

         * :doc:`/trainings/material/soup/linux/basics/shell/commandline`
         * :doc:`/trainings/material/soup/linux/basics/shell/paths`
         * :doc:`/trainings/material/soup/linux/basics/shell/ls`
         * :doc:`/trainings/material/soup/linux/basics/shell/cwd`
         * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
         * :doc:`/trainings/material/soup/linux/basics/shell/cp`
         * :doc:`/trainings/material/soup/linux/basics/shell/mv`
         * :doc:`/trainings/material/soup/linux/basics/shell/links`
         * :doc:`/trainings/material/soup/linux/basics/shell/configfiles`

	 *Exercises:* from :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group` ...

         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/mkdir-p-rm-r`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-create-files`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-copy-files`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-move-files`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/copy-tree`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-tree`
         * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-rf`

       * **SSH Setup**. From :doc:`/trainings/material/soup/linux/ssh/group`

         * :doc:`/trainings/material/soup/linux/ssh/basics`
         * :doc:`/trainings/material/soup/linux/ssh/key-pair`
         * :doc:`/trainings/material/soup/linux/ssh/scp`

   * * 2024-04-14
     * 6
     * * **SSH: Secure Shell** (from
	 :doc:`/trainings/material/soup/linux/ssh/group`)

         * :doc:`/trainings/material/soup/linux/ssh/basics`
         * :doc:`/trainings/material/soup/linux/ssh/key-pair`
         * :doc:`/trainings/material/soup/linux/ssh/scp`
         * :doc:`/trainings/material/soup/linux/ssh/sshfs`

       * **File System Permissions** (from
	 :doc:`/trainings/material/soup/linux/basics/permissions/group`)

         * :doc:`/trainings/material/soup/linux/basics/permissions/basics`
         * :doc:`/trainings/material/soup/linux/basics/permissions/umask`
         * :doc:`/trainings/material/soup/linux/basics/permissions/setuid`

       * **File System Permissions (Exercises)** (from
	 :doc:`/trainings/material/soup/linux/basics/permissions/exercises/group`)

         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/credentials`
         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/shared-file`
         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory`
         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory-question`
         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory`
         * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory-question`

       * **Homework**

	 On Wednesday, we will start to program. Please make sure you
	 have the following prerequisites installed:

	 * In WSL, install the packages ``build-essential`` (C and C++
           compilers) and ``cmake`` (a build tool at a higher level
           than ``make``)
	 * In Windows, install `Visual Studio Code
           <https://code.visualstudio.com/docs/cpp/config-wsl>`__
	 
Block 2: C on Linux: Local and *Cross* Development
--------------------------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Date
     * #Units
     * Topics
   * * 2024-04-17
     * 6
     * **Recap, Outlook**

       * setuid root
       * syscalls
       * toolchain
       * cross
       * c++
       * cmake

       Ugly and undocumented

       **Toolchain Intro, And Basic Makefiles** (from
       :doc:`/trainings/material/soup/linux/toolchain/group`)

       * :doc:`/trainings/material/soup/linux/toolchain/basics/topic`
       * :doc:`/trainings/material/soup/linux/toolchain/separate-compilation/topic`
       * :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
       * :doc:`/trainings/material/soup/linux/toolchain/exercises/native-build`

       **CMake, Native Build** (from
       :doc:`/trainings/material/soup/linux/toolchain/group`)

       * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`
       * Exercise: like above
         (:doc:`/trainings/material/soup/linux/toolchain/exercises/native-build`),
         only using CMake

       **Github links**

       Today's outcome visible in
       https://github.com/jfasch/FH-STECE2022/tree/main/livecoding/toolchain-demo

   * * Date
     * #Units
     * Topics
   * * 2024-04-22
     * 6
     * **CMake, Native Build** (from
       :doc:`/trainings/material/soup/linux/toolchain/group`)

       * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`
       * Exercise: like above
         (:doc:`/trainings/material/soup/linux/toolchain/exercises/native-build`),
         only using CMake

       **Systems Programming Basics: File I/O**

       * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/050-command-line-arguments/topic`
       * :doc:`/trainings/material/soup/linux/sysprog/basics/group`
       * From :doc:`/trainings/material/soup/linux/sysprog/file-io/group`

         * :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`
         * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_RDONLY`
         * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_WRONLY`
         * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_CREAT`
         * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_EXCL`

       **Homework (until next time - 2024-05-06)**

       * :doc:`/trainings/material/soup/linux/sysprog/file-io/basics-exercise-copy`

Block 3: C++
------------

