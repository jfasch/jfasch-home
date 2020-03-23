.. post:: 2020-03-22
   :category: microsoft
   :language: en

.. meta::
   :description: This post details how to run Microsoft Teams on Linux
   :keywords: microsoft, teams, microsoft teams, linux, fedora,
              chrome, google chrome, video, conference, training,
              virtual classroom, virtual, classroom, training, remote,
              remote training

Using Microsoft Teams on Linux
==============================

.. sidebar:: Contents

   .. contents::
      :local:

I frequently run :doc:`trainings </trainings/index>` for
companies. These trainings use to take place physically - I book hotel
and train for the duration of the training, meet people face to face,
have fun, and then travel home again.

Things have changed: it's the *Age Of The Corona Virus*, everybody's
working from home [#homeoffice_should_be_default]_, and the demand for
video conferencing solutions has grown dramatically
[#microsoft_conspiracy_theory]_. A customer, having ordered a training
end of March, has asked me if we could do the training online - using
Microsoft Teams [#teamviewer_experience]_.

I spent a day or two to work out if and how that is done on Linux, and
to test all the details; this is what I want to share with you in this
post. It is sure not a definitive guide as I am not a Microsoft expert
[#driver_dont_tell_anybody]_, and things might have changed as you
read this. Please :doc:`inform me </about/myself/contact>` if you have
news.

.. note::

   What follows might not sound like I am a friend of Microsoft (I
   admit I'm not). I nevertheless really appreciate that they make
   their software (and their service) available for us poor stubborn
   Linux users.

.. _desktop-sharing-x11-revival:

Screen Sharing: X11 Revival
---------------------------

First off: none of the methods described in the remainder works with
`Wayland <https://wayland.freedesktop.org/>`__. Wayland (and its
reference implementation, Weston) is intended to replace the X11
display protocol which has shown its age. Major distributions have
invested large amounts of work to make the switch, to the point that
Wayland runs really smooth nowadays. An X11 compatibility layer is
there to keep X11 applications happy.

Smooth - except for cornercases like X11 programs which want to share
the desktop, apparently. For Teams, this means:

* The RPM native desktop app crashes hard when you hover over the
  "share screen" field.
* The browser app, from the sharer's point of view, appears to share
  like you tell it to. Meeting participants only see the mouse on a
  black screen, no matter what the sharer does.

So, here's how to make your login screen start an X11 session, rather
than a Wayland session.

In ``/etc/gdm/custom.conf``, a .ini style configuration file, you see
the ``[daemon]`` section, 

.. code-block:: console

   [daemon]
   # Uncomment the line below to force the login screen to use Xorg
   #WaylandEnable=false
   #DefaultSession=gnome-xorg.desktop

Switch to X11,

.. code-block:: console

   [daemon]
   WaylandEnable=false
   DefaultSession=gnome-xorg.desktop

Log out (i.e. terminate the current Wayland session), log back in
(i.e. start an X11 session), done.

RPM Package (Meh!)
------------------

(I'm on Fedora; there's also a ``.deb`` available.)

Download the RPM from `here
<https://teams.microsoft.com/downloads>`__; it'll be available as
``~/Downloads/teams-1.3.00.5153-1.x86_64.rpm`` (your version might
differ) if you used a browser. If you used ``wget`` then you know
better where the file is.

Install it as root,

.. code-block:: console

   $ sudo rpm -ivh ~/Downloads/teams-1.3.00.5153-1.x86_64.rpm

Start it,

.. code-block:: console

   $ teams

That was easy. Login with your Microsoft account, and figure out how
to use it (this is not the point of this post).

Annoyance #1: Keeps Running in Background
.........................................

Call me old fashioned, but I like programs to quit when I tell them
to - especially when I know they use my microphone and camera. Teams
doesn't; it keeps running in the background,

.. code-block:: console

   $ ps -efl|grep teams
   0 S jfasch     61762    1670  1  80   0 - 947213 -     17:04 ?        00:00:22 /usr/share/teams/teams
   0 S jfasch     61764   61762  0  80   0 - 98775 -      17:04 ?        00:00:00 /usr/share/teams/teams --type=zygote --no-sandbox
   0 S jfasch     61800   61762  0  80   0 - 239615 -     17:04 ?        00:00:13 /usr/share/teams/teams --type=gpu-process --enable-features=SharedArrayBuffer --disable-features=SpareRendererForSitePerProcess --gpu-preferences=KAAAAAAAAACAAABAAQAAAAAAAAAAAGAAAAAAAAAAAAAIAAAAAAAAAAgAAAAAAAAA --service-request-channel-token=4327801531638606376
   1 S jfasch     61825   61764  0  80   0 - 420846 -     17:04 ?        00:00:00 /usr/share/teams/teams --type=renderer --autoplay-policy=no-user-gesture-required --enable-features=SharedArrayBuffer --disable-features=SpareRendererForSitePerProcess --service-pipe-token=12993561460135093079 --lang=en-US --app-path=/usr/share/teams/resources/app.asar --user-agent=Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) MicrosoftTeams-Preview/1.3.00.5153 Chrome/69.0.3497.128 Electron/4.2.12 Safari/537.36 --node-integration=false --webview-tag=false --no-sandbox --preload=/usr/share/teams/resources/app.asar/lib/renderer/notifications/preload_notifications.js --disable-remote-module --background-color=#fff --electron-shared-settings=eyJjci5jb21wYW55IjoiRWxlY3Ryb24iLCJjci5kdW1wcyI6IiIsImNyLmVuYWJsZWQiOmZhbHNlLCJjci5wcm9kdWN0IjoiRWxlY3Ryb24iLCJjci5zZXNzaW9uIjoiIiwiY3IudXJsIjoiIiwiY3IudmVyc2lvbiI6InY0LjIuMTIifQ== --num-raster-threads=4 --enable-main-frame-before-activation --service-request-channel-token=12993561460135093079 --renderer-client-id=7 --shared-files=v8_context_snapshot_data:100,v8_natives_data:101 --msteams-process-type=notificationsManager
   1 S jfasch     61973   61764  2  80   0 - 790018 -     17:04 ?        00:00:45 /usr/share/teams/teams --type=renderer --autoplay-policy=no-user-gesture-required --enable-features=SharedArrayBuffer --disable-features=SpareRendererForSitePerProcess --service-pipe-token=432557619363765409 --lang=en-US --app-path=/usr/share/teams/resources/app.asar --user-agent=Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) MicrosoftTeams-Preview/1.3.00.5153 Chrome/69.0.3497.128 Electron/4.2.12 Safari/537.36 --node-integration=false --webview-tag=true --no-sandbox --preload=/usr/share/teams/resources/app.asar/lib/renderer/preload.js --disable-remote-module --background-color=#fff --electron-shared-settings=eyJjci5jb21wYW55IjoiRWxlY3Ryb24iLCJjci5kdW1wcyI6IiIsImNyLmVuYWJsZWQiOmZhbHNlLCJjci5wcm9kdWN0IjoiRWxlY3Ryb24iLCJjci5zZXNzaW9uIjoiIiwiY3IudXJsIjoiIiwiY3IudmVyc2lvbiI6InY0LjIuMTIifQ== --num-raster-threads=4 --enable-main-frame-before-activation --service-request-channel-token=432557619363765409 --renderer-client-id=16 --shared-files=v8_context_snapshot_data:100,v8_natives_data:101 --msteams-process-type=mainWindow
   1 S jfasch     62033   61764  5  80   0 - 1259666 -    17:04 ?        00:01:26 /usr/share/teams/teams --type=renderer --autoplay-policy=no-user-gesture-required --enable-features=SharedArrayBuffer --disable-features=SpareRendererForSitePerProcess --service-pipe-token=5585537623314398260 --lang=en-US --app-path=/usr/share/teams/resources/app.asar --user-agent=Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) MicrosoftTeams-Preview/1.3.00.5153 Chrome/69.0.3497.128 Electron/4.2.12 Safari/537.36 --node-integration=false --webview-tag=false --no-sandbox --preload=/usr/share/teams/resources/app.asar/lib/pluginhost/preload.js --disable-remote-module --background-color=#fff --electron-shared-settings=eyJjci5jb21wYW55IjoiRWxlY3Ryb24iLCJjci5kdW1wcyI6IiIsImNyLmVuYWJsZWQiOmZhbHNlLCJjci5wcm9kdWN0IjoiRWxlY3Ryb24iLCJjci5zZXNzaW9uIjoiIiwiY3IudXJsIjoiIiwiY3IudmVyc2lvbiI6InY0LjIuMTIifQ== --num-raster-threads=4 --enable-main-frame-before-activation --service-request-channel-token=5585537623314398260 --renderer-client-id=20 --shared-files=v8_context_snapshot_data:100,v8_natives_data:101 --msteams-process-type=pluginHost
   
When I look at the ``SZ`` column of the ``ps`` output, that
:doc:`makes me wish </blog/2012/04/Why-ps-sucks>` it would really
stop. It consumes insane amounts of memory doing nothing.

Make it so,

.. code-block:: console

   $ killall teams

Check,

.. code-block:: console

   $ ps -efl|grep teams
   0 R jfasch     63500    1670 47  80   0 - 298385 -     17:41 ?        00:00:00 /usr/share/teams/teams
   0 S jfasch     63502   63500  1  80   0 - 98775 -      17:41 ?        00:00:00 /usr/share/teams/teams --type=zygote --no-sandbox

Blood pressure rising,

.. code-block:: console

   $ killall -9 teams

.. note::

   If I don't wipe it entirely with ``killall -9``, it comes back from
   time to time and says, "Please log in with your Microsoft
   account". *Cool feature, guys!*

Annoyance #2: (Re)Registers Itself For Autostart
................................................

Logout, and back in. Teams pops up right into my face. Maybe that's
the desired behavior in the office world where everyone's in a meeting
at any given point in time. I live in a different world, though: when
I want something to pop into my face at startup (I rarely do), I
configure it so.

.. code-block:: console

   $ rm ~/.config/autostart/teams.desktop

True, I could have edited the offending line of that file,

.. code-block:: console

   X-GNOME-Autostart-enabled=true

But no.

.. code-block:: console

   $ sudo rpm -e teams

Run In Browser (My Recommendation)
----------------------------------

It turns out that Teams can run in the browser (thanks to `WebAssembly
<https://webassembly.org/>`__?). Really cool:

* I need not install a closed-source program (and let it access all my
  files)
* I need not blow it out of the water when my blood pressure rises
* It simply goes away when I close the browser tab
* Its security is that of the browser (if that's an argument)

Simply point your browser to
`<https://teams.microsoft.com/>`__. That's it.

Well, no, it's actually not so simple.

* It does not work with Firefox 74.0 (shipped with Fedora 31, as of
  2020-03-22). The error message says something like "DOM storage not
  enabled". Which is not true because it is enabled; this is where I
  gave up.
* It works in Chromium "Version 80.0.3987.132 (Developer Build) Fedora
  Project (64-bit)" (as it says) (shipped with Fedora 31, as of
  2020-03-22)
* Take care to run :ref:`X11 as explained above
  <desktop-sharing-x11-revival>` (to be able to share the desktop)



.. rubric:: Footnotes

.. [#homeoffice_should_be_default] Once the plague comes to an end, I
                                   hope we remember that The Internet
                                   hasn't originally been invented for
                                   the purpose of gaming, streaming,
                                   and pornwatching - and work from
                                   home more.

.. [#microsoft_conspiracy_theory] It's also the age of conspiracy
                                  theories. "That's `Roche again
                                  <https://www.zeit.de/wissen/gesundheit/2012-01/tamiflu-cochrane-wirksamkeit>`__!"
                                  I take the opportunity to add
                                  another one, "That's Microsoft
                                  marketing their products more
                                  aggressively than even Steve Ballmer
                                  was able to!" (*Satire!*)

.. [#driver_dont_tell_anybody] I have :ref:`written a device driver
                               for Windows
                               <projekte-device-driver-for-doze>`, but
                               please don't tell anybody.

.. [#teamviewer_experience] I have used `Teamviewer
			    <https://www.teamviewer.com/>`__ in the
			    past, as a part-time teacher at `FH
			    Joanneum
			    <https://www.fh-joanneum.at/>`__ - it
			    works great on Linux.

