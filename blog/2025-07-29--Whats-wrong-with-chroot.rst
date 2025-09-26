.. post:: Sep 26, 2025
   :category: linux, embedded

Why Use A Container When There Is ``chroot``?
=============================================

.. LinkedIn post
.. -------------
.. 
.. Why Use A Container When There Is ``chroot``?
.. 
.. Recenty I had the problem that Yocto does not support the OS that I am
.. running (Fedora 42), and I had to setup a supported OS to do the
.. job. Normally, nowadays, one would jump up and throw a container at
.. that particular kind of problem. In this article I present how good
.. old ``chroot`` is used to do the same, although a little more
.. lightweight.


I cannot build `Yocto "Walnascar"
<https://docs.yoctoproject.org/migration-guides/migration-5.2.html>`__
natively on my Fedora 42 - it is not supported [#yocto_tried]_. So I
was looking for a way to "isolate" a supported distribution (Fedora 41
for that matter) inside Fedora 42.

I had done this a number of times before: using a subdirectory on one
OS as the root directory for another OS, combining a few features like
``chroot`` and bind mounts. Also, I am always looking for
opportunities to :doc:`explain people the world </trainings/index>` -
setting up a ``chroot`` jail in front the audience would not only
explain what ``chroot`` is, but also what a root directory is.

After a number of attempts to contain myself (speak: `Docker
<https://www.docker.com/>`__ and `systemd-nspawn
<https://www.freedesktop.org/software/systemd/man/latest/systemd-nspawn.html>`__),
I came to the conclusion that a virtual machine, however lightweight,
was still too heavy for my task.

Read on to see how easy it is to setup a "container" without having to
install any additional baggage than the contained OS itself. Jump
directly to :ref:`blog_chroot_decontainerized_simple` to skip my case
against Docker and read the full explanation of everything. Jump to
:ref:`blog_chroot_short_fedora41` if you don't want any explanation
but only want the pure commandlines for a Fedora 41 ``chroot``.

.. _blog_chroot_container_attempts:

Container Attempts
------------------

.. contents::
   :local:

Docker
......

`Docker <https://www.docker.com/>`__ was my first choice. Colleagues
are using it a lot to do build stuff, and are happy with its
convenience. Convenience - e.g. gazillions of images to download from
`Docker Hub <https://hub.docker.com/>`__ - might be the primary reason
why Docker is so popular.

Installed docker, pulled ``fedora:41`` from `Docker Hub
<https://hub.docker.com/>`__. Read docs, managed to get a
shell. Further steps would have been to mount my home directory into
it, to solve my original problem - build Yocto.

While digging around I found the alarmistic article `"Docker
considered harmful"
<https://quantum5.ca/2025/03/18/docker-considered-harmful/>`__ which
is really worth a read. I mean, it's probably me - I am really
sceptical about any hype, and it takes very little (for example, an
article titled "Docker considered harmful" |:wink:|) for me to run
away.

``systemd-nspawn``
..................

Since ``systemd`` took place, everything just works. ``systemd``
always used Linux `cgroups
<https://man7.org/linux/man-pages/man7/cgroups.7.html>`__
[#cgroups_docker]_ and `namespaces
<https://man7.org/linux/man-pages/man7/namespaces.7.html>`__ to run
services at different isolation levels. ``systemd-nspawn`` (`here
<https://www.freedesktop.org/software/systemd/man/latest/systemd-nspawn.html>`__)
is a logical step further. It is It has been created by the
``systemd`` team to test ``systemd`` itself, and is comparable to
Docker in many ways.

After my Docker experience, I was still in a mood for
self-modernization. I decided to give ``systemd-nspawn`` a try, partly
because its documentation compares it with ``chroot``, only on
steroids.

Long story short: network setup for nspawn containers works best when
the host system's network is managed by ``systemd-networkd``. My
machine runs GNOME, which works best together with GNOME's
``NetworkManager``, which again is perfectly integrated with
``wpa_supplicant``. ``systemd-networkd`` has no idea what
``wpa_supplicant`` is. Doing everything by hand is a cool learning
experience, but does not help me get the job (remember: Yocto) done.

Conclusion
..........

I'm sure I'd have been able to build bloody Yocto going the
containerization route. On the other hand, all I wanted was to have a
shell in an isolated environment, and from there access to my home
directory *outside* that environment.

If I went down that route though, I'd have to think a lot more.

* Learn about the containerization technology, especially:
* How does the technology want me to configure access to my outside
  home directory
* If I access my outside home directory, how would that go together
  with UID isolation?
* How about network access? I don't want *any* isolation at that
  level. If you are building a cluster of microservices, each one
  running in a different container, you'd probably want network
  virtualization/isolation - I don't, however.

**But again**: my only problem is that I want to build Yocto on Fedora
42 which is not supported by Yocto. I know what ``chroot`` is, I know
what a *bind mount* is, I know what Linux is - so I should be able to
solve my problem in a minimal and hype-less way.

.. _blog_chroot_decontainerized_simple:

``chroot``: De-Containerization (Minimal ``busybox`` Root Filesystem)
---------------------------------------------------------------------

I'll begin with a minimal ``busybox`` root filesystem. The likelihood
that this particular approach will let me build Yocto is relatively
low again, but it lets me present the fundamentals without confusing
you with distro specific things. If you already know enough you may
well jump ahead and read the section where I :ref:`repeat the whole
thing with Fedora 41 <blog_chroot_short_fedora41>` instead of
``busybox``.

**Conventions**

I the remainder, I'll not use ``sudo`` to execute commands as root.
Rather, I'll use 

* the hash sign (``#``) as prompt when the command is run as root
* the dollar sign (``$``) when the command is run as normal user

To help you distinguish commands that I run inside the jail from those
that are run on the host system, I try to annotate code blocks
accordingly ("Inside jail", "Outside jail").

.. contents::
   :local:

.. _blog_chroot_chroot_jail:

``chroot`` Jail
...............

``chroot`` is a system call (`documentation
<https://man7.org/linux/man-pages/man2/chroot.2.html>`__) that changes
the root directory of the calling process to its single parameter
which has to be a directory. In effect, it redirects path traversal to
start from that directory. This is best explained using an example,
using a shell command ``chroot`` with the same name (`documentation
<https://man7.org/linux/man-pages/man1/chroot.1.html>`__).

Below is a functional (although rather pointless) root filesystem,
implemented using the neat ``busybox`` (`Github
<https://github.com/brgl/busybox>`__, `Wikipedia
<https://en.wikipedia.org/wiki/BusyBox>`__).

.. code-block:: console
   :caption: Outside jail

   $ tree ~/Machines/Simple-Busybox
   /home/jfasch/Machines/Simple-Busybox
   └── bin
       ├── busybox
       ├── ls -> /bin/busybox
       └── sh -> /bin/busybox

The ``chroot`` command is used to execute a command *inside* the
"jail". The root directory of that process, and all of its
descendants, is *the jail*,
``/home/jfasch/Machines/Simple-Busybox``. Here we enclose an instance
of ``/bin/sh`` (actually
``/home/jfasch/Machines/Simple-Busybox/bin/sh``) into the "container"
``/home/jfasch/Machines/Simple-Busybox``.

.. code-block:: console
   :caption: Outside jail

   # chroot ~/Machines/Simple-Busybox /bin/sh
   #            # <-- inside jail
   # pwd        # <-- actually /home/jfasch/Machines/Simple-Busybox
   /
   # ls         # <-- busybox ls
   bin
   # ls /bin
   busybox  ls       sh

.. _blog_chroot_proc:

``proc``
........

``proc`` is a virtual filesystem which implements, among other things,
a view into the kernel's process list. It is usually mounted in the
root filesystem under ``/proc``, and is used by tools like ``ps`` and
``lsof`` to retrieve the information they need. Busybox ``ps``, as an
example, fails without a populated ``/proc`` [#empty_is_not_fail]_:

.. code-block:: console
   :caption: Inside jail

   # busybox ps
   PID   USER     TIME  COMMAND

To make ``proc`` available inside the jail, we create a mountpoint
``/proc`` (inside), and mount a ``proc`` instance on it. On the host
(err: from outside the jail, as ``root``):

.. code-block:: console
   :caption: Outside jail

   # pwd
   /home/jfasch/Machines
   # mkdir Simple-Busybox/proc
   # mount -t proc proc Simple-Busybox/proc

Retry ``busybox ps`` inside, and see a the full process list.

.. code-block:: console
   :caption: Inside jail

   # busybox ps
   PID   USER     TIME  COMMAND
       1 0         0:12 /usr/lib/systemd/systemd --switched-root --system --deserialize=52 rhgb
       2 0         0:00 [kthreadd]
       3 0         0:00 [pool_workqueue_]
       4 0         0:00 [kworker/R-rcu_g]
   ...

.. note::

   ``chroot`` has nothing to do with *isolation*: from *inside the
   jail*, we see all processes that were started *outside the jail*
   too.

.. _blog_chroot_devtmpfs:

``devtmpfs`` (And ``/dev/shm``)
...............................

Another virtual filesystem, of type ``devtmpfs``, is usually mounted
at ``/dev/``. For our purposes, it provides special files like
``/dev/null`` which are used occasionally in less trivial root
filesystems. (Our simple Busybox root doesn't.) Make that available
much like we did with ``/proc``

.. code-block:: console
   :caption: Outside jail

   # mkdir Simple-Busybox/dev
   # mount -t devtmpfs dev Simple-Busybox/dev

There is another filesystem type, ``tmpfs``, which is a plain RAM
based filesystem (no persistence). An instance of it is usually
mounted at ``/dev/shm``, to hold POSIX IPC artifacts like semaphores
and shared memory. Yocto uses POSIX IPC heavily; lets create it while
we are at it.

.. code-block:: console
   :caption: Outside jail

   # mkdir Simple-Busybox/dev/shm
   # mount -t tmpfs shm Simple-Busybox/dev/shm

Bind Mounts
...........

To access files outside the jail, one would have to navigate past the
root of the jail upwards in the hierarchy. This is not possible -
which is the entire point of ``chroot``. Instead, *bind mounts* are
used to make *outside content* visible *inside*.

.. _blog_chroot_bind_home:

Home Directory (And Network, While We At Bind Mounting)
```````````````````````````````````````````````````````

To make my home directory visible inside the jail, we create a
mountpoint ``/home/jfasch`` *inside*, and mount the *outside*
``/home/jfasch`` onto it.

.. code-block:: console
   :caption: Outside jail

   # mkdir -p Simple-Busybox/home/jfasch
   # chown jfasch:jfasch Simple-Busybox/home/jfasch
   # mount --bind /home/jfasch Simple-Busybox/home/jfasch

``/etc/resolv.conf``
````````````````````

No isolation is cool - I can use the host network inside the jail
(simply because the concept "host" does not exist).

.. code-block:: console
   :caption: Inside jail

   # busybox ping 142.251.39.36
   PING 142.251.39.36 (142.251.39.36): 56 data bytes
   64 bytes from 142.251.39.36: seq=0 ttl=114 time=36.571 ms
   64 bytes from 142.251.39.36: seq=1 ttl=114 time=21.538 ms
   ...

One minor problem though that is easily solved: DNS names. When you
instead say ``ping www.google.com``, the command fails because DNS
name resolution fails.

.. code-block:: console
   :caption: Inside jail

   # busybox ping www.google.com
   ping: bad address 'www.google.com'

The so-called *resolver* is a bunch of routines inside the C library
that do DNS name resolution. The resolver is configured with a file
``/etc/resolv.conf`` on the "host". To make that file available inside
the jail, again a mountpoint needs to be created (yes, a file can also
serve as a mountpoint), and then ``/etc/resolv.conf`` can be bind
mounted into the jail.

.. code-block:: console
   :caption: Outside jail

   # touch Simple-Busybox/etc/resolv.conf
   # mount --bind /etc/resolv.conf Simple-Busybox/etc/resolv.conf 

Verify all is well,

.. code-block:: console
   :caption: Inside jail

   # busybox ping www.google.com
   PING www.google.com (142.250.180.228): 56 data bytes
   64 bytes from 142.250.180.228: seq=0 ttl=114 time=24.807 ms
   64 bytes from 142.250.180.228: seq=1 ttl=114 time=28.564 ms
   ...

Working As Non ``root`` Inside A Jail (And UID Non-Isolation)
.............................................................

Now, inside the jail, we see ``/home/jfasch`` exactly as it is there
on the outside. My outside UID/GID is 1000/1000, and this is what we
see inside.

.. note:: 

   ``chroot`` has nothing to do with *isolation*

.. code-block:: console
   :caption: Inside jail

   # ls -l /home/jfasch/
   ...
   drwxr-xr-x    1 1000     1000            68 Jul  1 19:43 Desktop
   drwxr-xr-x    1 1000     1000             0 Jun 12 13:01 Documents
   drwxr-xr-x    1 1000     1000          1130 Jul 20 17:04 Downloads
   drwxr-xr-x    1 1000     1000          1726 Jul 17 08:28 My-Projects
   ...

We'd now be prepared to

* Change into the jail
* Work on the outside home directory from *inside* (for example to
  build Yocto)

Its just that I do not want to work in my home directory as
``root``. Two options exist.

Option 1: Simply Use Numeric IDs *Inside*
`````````````````````````````````````````

Simply specify my UID/GID to ``chroot --userspec=``, and be myself *inside*, without
any further action. *Problem solved*: I am not ``root`` anymore (note
the ``$`` prompt from the inside shell), but otherwise there are no
names for me and my group - just numbers.

.. code-block:: console
   :caption: Outside jail

   # chroot --userspec=1000:1000 Simple\(Busybox\) /bin/sh
   $         # <-- now inside, note the non-root prompt "$"
   $ ls -l /home/jfasch
   ...
   drwxr-xr-x    1 1000     1000            68 Jul  1 19:43 Desktop
   drwxr-xr-x    1 1000     1000             0 Jun 12 13:01 Documents
   drwxr-xr-x    1 1000     1000          1130 Jul 20 17:04 Downloads
   drwxr-xr-x    1 1000     1000          1726 Jul 17 08:28 My-Projects
   ...

This is fine for me once I automate the entire "chroot into jail and
build Yocto there" workflow - I'd not be intersted in any names then.

.. _blog_chroot_user_group:

Option 2: Create User Record *Inside*
`````````````````````````````````````

.. note::

   Again, be aware that *there is no isolation in a chroot jail*. Any
   UID/GID that is referenced by a user record *inside* is *exactly
   the UID/GID from outside*.

*For convenience only*, lets now create names ``jfasch`` *inside*, and
define a home directory that we can easily ``chdir`` to.

Currently, at this point, we are using our simple Busybox jail to
create user and group. A jail filled with a real distro is a little
different; see below jjj "wrap-up fedora 41 jail" for the "real
distro" case.

* Prepare empty user/group files (our simple root does not have those)

  .. code-block:: console
     :caption: Outside jail

     # mkdir Simple\(Busybox\)/etc
     # touch Simple\(Busybox\)/etc/group
     # touch Simple\(Busybox\)/etc/passwd

* Use *inside* (Busybox) tools to create user and group. As I said,
  Fedora and other distros are a little different (Busybox has
  ``addgroup``, Fedora has ``groupadd``, for example).

  .. code-block:: console
     :caption: Outside jail

     # chroot Simple\(Busybox\) busybox addgroup -g 1000 jfasch
     # chroot Simple\(Busybox\) busybox adduser -s /bin/sh -G jfasch -u 1000 -D jfasch

I can now go into jail in one step, and it would feel like
freedom. It's still Busybox which is not quite usable for a Yocto
build. In the next step, let's see how a jail can be setup from a real
distro.

.. code-block:: console
   :caption: Outside jail

   # chroot Simple\(Busybox\)/ /bin/busybox su - jfasch
   ~ $           # <-- indise jail
   ~ $ cd ~/My-Projects/FH-ENDLESS/Yocto/
   ~/My-Projects/FH-ENDLESS/Yocto $ ls -l 
   total 12
   drwxr-xr-x    1 jfasch   jfasch       15972 Jul 28 21:58 DOWNLOAD
   drwxr-xr-x    1 jfasch   jfasch        1060 Jul 28 21:32 SSTATE
   drwxr-xr-x    1 jfasch   jfasch           8 Apr 10 09:46 build
   -rw-r--r--    1 jfasch   jfasch         373 Jan 20  2025 common-bblayers.conf
   -rw-r--r--    1 jfasch   jfasch         373 Jan 15  2025 common-local.conf
   drwxr-xr-x    1 jfasch   jfasch         122 Jan 20  2025 meta-endless
   drwxr-xr-x    1 jfasch   jfasch         472 Oct 22  2024 meta-raspberrypi
   drwxr-xr-x    1 jfasch   jfasch         548 Oct 22  2024 poky
   drwxr-xr-x    1 jfasch   jfasch          28 Nov 15  2024 qemuarm64
   drwxr-xr-x    1 jfasch   jfasch          92 Jul 28 21:22 qemux86-64
   drwxr-xr-x    1 jfasch   jfasch         120 Jul 29 09:09 raspberry3-build

.. _blog_chroot_short_fedora41:

Repeat, In A Real Distro Jail (Fedora 41)
-----------------------------------------

.. sidebar:: See also

   * `dnf --installroot=
     <https://dnf5.readthedocs.io/en/latest/misc/installroot.7.html>`__
   * `debootstrap <https://wiki.debian.org/Debootstrap>`__
   * `A re-introduction to mkosi -- A Tool for Generating OS Images
     <https://0pointer.net/blog/a-re-introduction-to-mkosi-a-tool-for-generating-os-images.html>`__

Busybox is small and simple, which is why I used it above to
illustrate all the pieces involved. Busybox is used in hardcore
Embedded Linux systems to achive a small footprint, but it is for sure
not capable to run a Yocto build [#busybox-not-yocto-supported]_.

What follows is an annotated shell-command-like transcript of what I
did to solve my very original problem: a Yocto build on
Yocto-unsupported Fedora 42. It has much of what I did above, only
more condensed.

Fedora 41 Jail
..............

Lets now setup a real distro's root filesystem. Like the Busybox in
:ref:`blog_chroot_chroot_jail`, but bigger. All the mountpoints, like
``/proc``, are already there, for example.

We "parameterize" the root directory, if someone wants to make all
this into a script.

.. code-block:: console

   # JAILDIR=/home/jfasch/Machines/fedora-41

Fedora package list to install. This somehow gathered by trial and
error.

.. code-block:: bash

   # minimal install
   PACKAGES="dnf fedora-release glibc glibc-langpack-en glibc-langpack-de gcc g++ cmake util-linux iputils"
   
   # for Yocto's bitbake itself
   PACKAGES="$PACKAGES python3"
   # these had to be installed on the host, as bitbake complained
   PACKAGES="$PACKAGES chrpath diffstat lz4 patch rpcgen"
   # these were discovered, on the host, as needed somewhere deep inside the build
   PACKAGES="$PACKAGES perl-FindBin perl-STD"
   # these are needed on top of the minimal chroot install, also complained about by bitbake at some point
   PACKAGES="$PACKAGES bunzip2 bzip2 cmp cpio diff file git hostname pzstd tar unzstd wget which zstd"
   # more perl crap needed
   PACKAGES="$PACKAGES perl-Thread-Queue perl-File-Compare perl-open"
   # one packaging/wic error near the end of yocto build, saying that something couldn't be converted to "codepage 850"
   PACKAGES="$PACKAGES glibc-gconv-extra"

Populate the root directory ...

.. code-block:: console

   # dnf -y --releasever=41 --best --setopt=install_weak_deps=False --installroot=$JAILDIR --use-host-config install $PACKAGES

Create Environment
..................

Let's now repeat the steps from above, one by one.

Mount ``/proc`` (see :ref:`blog_chroot_proc`):

.. code-block:: console

   # mount -t proc proc $JAILDIR/proc/

Mount ``devtmpfs`` and ``/dev/shm`` (see :ref:`blog_chroot_devtmpfs`):

.. code-block:: console

   # mount -t devtmpfs dev $JAILDIR/dev/
   # mount -t tmpfs shm $JAILDIR/dev/shm

Mount my home directory (see :ref:`blog_chroot_bind_home`):

.. code-block:: console

   # mkdir $JAILDIR/home/jfasch
   # chown jfasch:jfasch $JAILDIR/home/jfasch
   # mount --bind /home/jfasch $JAILDIR/home/jfasch

Mount resolver config (see :ref:`blog_chroot_bind_home`):

.. code-block:: console

   # touch $JAILDIR/etc/resolv.conf
   # mount --bind /etc/resolv.conf $JAILDIR/etc/resolv.conf 

Give myself a name inside the jail (see
:ref:`blog_chroot_user_group`):

.. code-block:: console

   # chroot $JAILDIR /usr/sbin/groupadd -g 1000 jfasch
   # chroot $JAILDIR /usr/sbin/useradd --home-dir /home/jfasch --gid jfasch --no-create-home --shell /bin/bash jfasch

.. code-block:: console

   # chroot $JAILDIR su - jfasch
   [jfasch@laptop ~]$ 

Et voila: Fedora 41 *inside* Fedora 42!

Finally: Build Yocto
....................

Finally we are prepared to run a Yocto build in a jail the we have set
up for that purpose.

.. code-block:: console
   :caption: Inside jail

   [jfasch@laptop ~]$ cd ~/My-Projects/FH-ENDLESS/Yocto/
   [jfasch@laptop Yocto]$ . poky/oe-init-build-env raspberry3-build/
   [jfasch@laptop raspberry3-build]$ bitbake endless-image-fulldev
   ... CPU fan getting loud ...

Conclusion
----------

Please don't consider this article a flame against any container
technologies. Containers are cool when there are problems to be solved
bigger than building Yocto using a different distro than the one you
are just running. Need isolation, need a full (well, half) OS boot and
services started inside - this is what containers are there for. 

Sure a full distro container can solve my trivial Yocto problem
too. In my opinion, though, this feels like using a sledgehammer to
crack a nut. If you feel the same, then this article is for you, and I
hope that the information was helpful. Send comments (:doc:`here
</about/myself/index>`) if you liked it and/or have suggestions!


.. rubric:: Footnotes
.. [#yocto_tried] I sure tried no matter what they say, but ran into
                  build errors over and over.
.. [#cgroups_docker] Naturally, Docker also uses cgroups to implement
                     the isolation that it provides.
.. [#empty_is_not_fail] I would have expected ``busybox ps`` to fail
                        rather than succeeding with empty output,
                        though.
.. [#busybox-not-yocto-supported] Busybox is not among Yocto's list of
                                  supported distibutions
