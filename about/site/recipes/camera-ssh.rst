Sending A V4L Camera Device Output Over SSH
===========================================

.. contents::
   :local:

Capture Video To File
---------------------

.. code-block:: console

   $ ffmpeg -an -f video4linux2 -s 640x480 -i /dev/video0 -r 10 -b:v 500k -f matroska out.mks

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-an``
     * Disable audio
   * * ``-f video4linux2``
     * Force format to ``video4linux2``. Apparently this for the next
       file (``-i``) mentioned on the commandline.
   * * ``-s 640x480``
     * Frame size 640x480
   * * ``-i /dev/video0``
     * Input file be ``/dev/video0``
   * * ``-r 10``
     * Frame rate 10 Hz
   * * ``-b:v 500k``
     * Video bitrate 500k
   * * ``-f matroska``
     * Force format to ``matroska`` (next file mentioned is
       ``out.mks``)

Play Video From Remote System, Using SSH
----------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/ssh/basics`

* If ``ffmpeg`` sees ``-`` (instead of ``out.mks``) as output file,
  then it uses ``stdout``.
* Same holds for ``mplayer``, it then uses ``stdin``

.. code-block:: console

   $ ssh USER@REMOTE 'ffmpeg -an -f video4linux2 -s 640x480 -i /dev/video0 -r 10 -b:v 500k -f matroska -' | mplayer -
