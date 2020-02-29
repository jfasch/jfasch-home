.. post:: 2020-02-27
   :category: kernel
   :author: Jörg Faschingbauer
   :location: Hart bei Graz, Austria
   :language: en


Patching and Building the Fedora Kernel
=======================================

.. contents::
   :local:

Why?
----

Tracking down a bug on my new USB-C/Thunderbolt-only laptop where an
external HDMI monitor is plugged via an adapter.

* Plug external monitor
* Unplug external monitor
* Wait a few seconds
* Watch kernel go up in flames

.. code-block::
   :caption: The Oops

   Feb 26 13:58:08 zen kernel: BUG: kernel NULL pointer dereference, address: 0000000000000080
   Feb 26 13:58:08 zen kernel: #PF: supervisor read access in kernel mode
   Feb 26 13:58:08 zen kernel: #PF: error_code(0x0000) - not-present page
   Feb 26 13:58:08 zen kernel: PGD 0 P4D 0 
   Feb 26 13:58:08 zen kernel: Oops: 0000 [#1] SMP PTI
   Feb 26 13:58:08 zen kernel: CPU: 0 PID: 281 Comm: kworker/0:2 Not tainted 5.4.13-201.fc31.x86_64 #1
   Feb 26 13:58:08 zen kernel: Hardware name: ASUSTeK COMPUTER INC. ZenBook S UX391UA/UX391UA, BIOS UX391UA.204 05/18/2018
   Feb 26 13:58:08 zen kernel: Workqueue: events ucsi_connector_change [typec_ucsi]
   Feb 26 13:58:08 zen kernel: RIP: 0010:ucsi_displayport_remove_partner+0xa/0x20 [typec_ucsi]
   Feb 26 13:58:08 zen kernel: Code: 38 00 c7 43 28 00 00 00 00 48 83 c7 10 5b e9 6d f3 3d fb 66 66 2e 0f 1f 84 00 00 00 00 00 66 90 0f 1f 44 00 00 48 85 ff 74 0f <48> 8b 47 78 48 c7 00 00 00 00 00 c6 40 3d 00 c3 66 0f 1f 44 00 00
   Feb 26 13:58:08 zen kernel: RSP: 0018:ffff9daa002d3df8 EFLAGS: 00010202
   Feb 26 13:58:08 zen kernel: RAX: 0000000000000008 RBX: ffff901f4ce35710 RCX: 0000000000003c7d
   Feb 26 13:58:08 zen kernel: RDX: 0000000000003c7c RSI: 0000000000000001 RDI: 0000000000000008
   Feb 26 13:58:08 zen kernel: RBP: 0000000000000000 R08: ffffffffbc7dbe60 R09: ffff9daa002d3cf0
   Feb 26 13:58:08 zen kernel: R10: ffff901f54951a18 R11: ffff901f56a68a78 R12: ffff901f4ce35710
   Feb 26 13:58:08 zen kernel: R13: 0000000000000001 R14: ffff901f4ce35860 R15: ffff901f4ce355d8
   Feb 26 13:58:08 zen kernel: FS:  0000000000000000(0000) GS:ffff901f56a00000(0000) knlGS:0000000000000000
   Feb 26 13:58:08 zen kernel: CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
   Feb 26 13:58:08 zen kernel: CR2: 0000000000000080 CR3: 000000028fbbc003 CR4: 00000000003606f0
   Feb 26 13:58:08 zen kernel: Call Trace:
   Feb 26 13:58:08 zen kernel:  ucsi_unregister_altmodes+0x77/0x90 [typec_ucsi]
   Feb 26 13:58:08 zen kernel:  ucsi_unregister_partner.part.0+0x13/0x30 [typec_ucsi]
   Feb 26 13:58:08 zen kernel:  ucsi_connector_change+0x247/0x340 [typec_ucsi]
   Feb 26 13:58:08 zen kernel:  process_one_work+0x1b5/0x360
   Feb 26 13:58:08 zen kernel:  worker_thread+0x50/0x3c0
   Feb 26 13:58:08 zen kernel:  kthread+0xf9/0x130
   Feb 26 13:58:08 zen kernel:  ? process_one_work+0x360/0x360
   Feb 26 13:58:08 zen kernel:  ? kthread_park+0x90/0x90
   Feb 26 13:58:08 zen kernel:  ret_from_fork+0x35/0x40
   Feb 26 13:58:08 zen kernel: Modules linked in: cdc_ether usbnet r8152 mii rc_cec typec_displayport thunderbolt uinput rfcomm ccm xt_CHECKSUM xt_MASQUERADE nf_nat_tftp nf_conntrack_tftp tun bridge stp llc nf_conntrack_netbios_ns nf_conntrack_broadcast xt_CT ip6t_REJECT nf_reject_ipv6 ip6t_rpfilter ipt_REJECT nf_reject_ipv4 xt_conntrack ebtable_nat ebtable_broute ip6table_nat ip6table_mangle ip6table_raw ip6table_security iptable_nat nf_nat iptable_mangle iptable_raw iptable_security nf_conntrack nf_defrag_ipv6 nf_defrag_ipv4 libcrc32c ip_set nfnetlink ebtable_filter ebtables ip6table_filter ip6_tables iptable_filter cmac bnep sunrpc vfat fat snd_hda_codec_hdmi snd_soc_skl snd_soc_sst_ipc snd_soc_sst_dsp snd_hda_ext_core x86_pkg_temp_thermal intel_powerclamp snd_soc_acpi_intel_match coretemp snd_soc_acpi kvm_intel snd_soc_core snd_hda_codec_realtek snd_hda_codec_generic snd_compress ledtrig_audio ac97_bus kvm snd_pcm_dmaengine iwlmvm snd_hda_intel snd_intel_dspcfg irqbypass snd_hda_codec uvcvideo mac80211
   Feb 26 13:58:08 zen kernel:  btusb iTCO_wdt btrtl crct10dif_pclmul videobuf2_vmalloc iTCO_vendor_support videobuf2_memops mei_hdcp btbcm btintel crc32_pclmul intel_rapl_msr snd_hda_core videobuf2_v4l2 libarc4 ghash_clmulni_intel videobuf2_common snd_hwdep intel_cstate bluetooth snd_seq asus_nb_wmi iwlwifi videodev snd_seq_device intel_uncore asus_wmi snd_pcm intel_rapl_perf mc cdc_acm sparse_keymap wmi_bmof ecdh_generic cfg80211 intel_wmi_thunderbolt ecc pcspkr snd_timer snd i2c_i801 soundcore joydev idma64 intel_xhci_usb_role_switch mei_me ucsi_acpi processor_thermal_device typec_ucsi intel_rapl_common mei roles intel_soc_dts_iosf intel_pch_thermal typec int3403_thermal int340x_thermal_zone int3400_thermal acpi_thermal_rel acpi_pad binfmt_misc ip_tables rfkill i915 i2c_algo_bit drm_kms_helper hid_multitouch drm nvme crc32c_intel nvme_core serio_raw wmi i2c_hid video fuse
   Feb 26 13:58:08 zen kernel: CR2: 0000000000000080
   Feb 26 13:58:08 zen kernel: ---[ end trace 76d248e576fee192 ]---
   Feb 26 13:58:08 zen kernel: RIP: 0010:ucsi_displayport_remove_partner+0xa/0x20 [typec_ucsi]
   Feb 26 13:58:08 zen kernel: Code: 38 00 c7 43 28 00 00 00 00 48 83 c7 10 5b e9 6d f3 3d fb 66 66 2e 0f 1f 84 00 00 00 00 00 66 90 0f 1f 44 00 00 48 85 ff 74 0f <48> 8b 47 78 48 c7 00 00 00 00 00 c6 40 3d 00 c3 66 0f 1f 44 00 00
   Feb 26 13:58:08 zen kernel: RSP: 0018:ffff9daa002d3df8 EFLAGS: 00010202
   Feb 26 13:58:08 zen kernel: RAX: 0000000000000008 RBX: ffff901f4ce35710 RCX: 0000000000003c7d
   Feb 26 13:58:08 zen kernel: RDX: 0000000000003c7c RSI: 0000000000000001 RDI: 0000000000000008
   Feb 26 13:58:08 zen kernel: RBP: 0000000000000000 R08: ffffffffbc7dbe60 R09: ffff9daa002d3cf0
   Feb 26 13:58:08 zen kernel: R10: ffff901f54951a18 R11: ffff901f56a68a78 R12: ffff901f4ce35710
   Feb 26 13:58:08 zen kernel: R13: 0000000000000001 R14: ffff901f4ce35860 R15: ffff901f4ce355d8
   Feb 26 13:58:08 zen kernel: FS:  0000000000000000(0000) GS:ffff901f56a00000(0000) knlGS:0000000000000000
   Feb 26 13:58:08 zen kernel: CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
   Feb 26 13:58:08 zen kernel: CR2: 0000000000000080 CR3: 000000028fbbc003 CR4: 00000000003606f0
   
Looking at the cause, we see that the crash is a NULL pointer that is
deferenced in ``ucsi_displayport_remove_partner()``,

.. code-block::

   Feb 26 13:58:08 zen kernel: BUG: kernel NULL pointer dereference, address: 0000000000000080
   ... (blah) ...
   Feb 26 13:58:08 zen kernel: RIP: 0010:ucsi_displayport_remove_partner+0xa/0x20 [typec_ucsi]

A look at the offending source code shows that the fix must be
easy. The only pointer that is being accessed is ``dp``, and that
pointer is not checked for NULL-ness.

.. code-block:: c
   :caption: drivers/usb/typec/ucsi/displayport.c (taken from Linus
             ``master``)
   :linenos:
   :emphasize-lines: 8,9

   void ucsi_displayport_remove_partner(struct typec_altmode *alt)
   {
   	struct ucsi_dp *dp;
   
   	if (!alt)
   		return;
   
   	dp = typec_altmode_get_drvdata(alt);
   	dp->data.conf = 0;
   	dp->data.status = 0;
   	dp->initialized = false;
   }

The fix is really easy,

.. literalinclude:: displayport.c
   :language: c
   :diff: displayport.c.orig

The bug is tracked as `Red Hat Bugzilla – Bug 1785972
<https://bugzilla.redhat.com/show_bug.cgi?id=1785972>`__, and upstream
is already involved. John Stebbins and I provided testing, but
roundtrips are rather long. What makes things worse is that there
appear to be multiple issues, not just one.

I'll focus on mine: patch, build, report, and help with
testing. First, see how kernels are built in Fedora.

Building a Fedora Kernel
------------------------

* (https://fedoraproject.org/wiki/Building_a_custom_kernel)
* better this one?
  https://docs.fedoraproject.org/en-US/quick-docs/kernel/build-custom-kernel/


Try 42
------

or better yet, this one? (Laura Abbott)
  https://fedoramagazine.org/building-fedora-kernel/

$ fedpkg clone -a kernel

fatal: the remote end hung up unexpectedly27 MiB | 1.09 MiB/s  

retried, worked

being at 31,

$ cd kernel/
$ git checkout origin/f31

fedpkg local

coffee

done -> pollution ...


$ ls -l ./kernel-5.5.fc33/
total 305616
-rw-r--r--.  1 jfasch jfasch        31 Feb 27 08:00 debugfiles.list
-rw-r--r--.  1 jfasch jfasch    174194 Feb 27 08:00 debugfiles.list.dirs.sed
-rw-r--r--.  1 jfasch jfasch         0 Feb 27 08:00 debuginfodebug.list
-rw-r--r--.  1 jfasch jfasch    449975 Feb 27 08:00 debuginfo.list
-rw-r--r--.  1 jfasch jfasch         0 Feb 27 07:55 debuglinks.list
-rw-r--r--.  1 jfasch jfasch 311626830 Feb 27 07:59 debugsources.list
-rw-r--r--.  1 jfasch jfasch    307123 Feb 27 07:59 elfbins.list
-rw-r--r--.  1 jfasch jfasch         0 Feb 27 08:00 ignored-debuginfo.list
-rw-r--r--.  1 jfasch jfasch    208992 Feb 27 07:55 kernel-core.list
-rw-r--r--.  1 jfasch jfasch        16 Feb 27 07:51 kernel-ldsoconf.list
-rw-r--r--.  1 jfasch jfasch    154089 Feb 27 07:55 kernel-modules.list
drwxr-xr-x. 26 jfasch jfasch      4096 Feb 27 07:51 linux-5.6.0-0.rc3.git1.1.fc33.x86_64
drwxr-xr-x. 24 jfasch jfasch      4096 Jan 27 01:23 vanilla-5.5
drwxr-xr-x. 25 jfasch jfasch      4096 Feb 27 05:58 vanilla-5.6-rc3-git1

$ ls -l ./kernel-5.5.fc33/linux-5.6.0-0.rc3.git1.1.fc33.x86_64/

looks even more polluted, guess that is where kernel build took place
(in-source). copy away, to produce patch/diff.

cp -r ./kernel-5.5.fc33/linux-5.6.0-0.rc3.git1.1.fc33.x86_64/ /somewhere/else/

fix as above (jjj local ref):

emacs /somewhere/else/linux-5.6.0-0.rc3.git1.1.fc33.x86_64/drivers/usb/typec/ucsi/displayport.c

patch ...

https://fedoraproject.org/wiki/Kernel/Spec#Individual_patches

jjjj

diff -ur ./kernel-5.5.fc33/linux-5.6.0-0.rc3.git1.1.fc33.x86_64 /somewhere/else/linux-5.6.0-0.rc3.git1.1.fc33.x86_64/ > ./RIP-ucsi_displayport_remove_partner.patch

add to patch list in kernel.spec

rebuild:

fedpkg local

-> error failed apply patch

Try 43
------

It's not easy to get up to date information on how to create a custom
kernel on Fedora. There's plenty of information out there, but most of
it is outdated and only halfway true.

Here's what I was able to find out by combining non-outdated
information into a working procedure. It goes as follows.

.. contents::
   :local:

Find Kernel Source (Git), Fix It, and Create Patch
--------------------------------------------------

.. sidebar:: Link

   `Fedora Wiki: "Exploded Git Trees"
   <https://fedoraproject.org/wiki/Building_a_custom_kernel#Building_a_kernel_from_the_exploded_git_trees>`__

Fedora has a Git repository at ``kernel.org`` where they apply their
own patches on top of the vanilla kernel. Clone that, and create a
development branch.

.. code-block:: shell

   $ git clone git://git.kernel.org/pub/scm/linux/kernel/git/jwboyer/fedora.git
   $ git checkout -b jfasch-fix remotes/origin/f31

Fix ``drivers/usb/typec/ucsi/displayport.c`` as sketched above, and
commit.

.. code-block:: shell

   $ git commit -am 'fix RIP:ucsi_displayport_remove_partner()'

The remainder of the procedure will build the kernel RPM. A kernel RPM
build works by applying a set of patches on top of the base vanilla
kernel [#exploded_tree]_, so we create a patch for later use.

I made only one commit for which I want to create a patch. Find out
the revision that this patch is based upon; it is one revision before
the ``HEAD``.

.. code-block:: shell

   $ git show --quiet HEAD~1
   commit 4382f76bc8ef9fce5e7e96d4cdb0c073564ad249 (tag: kernel-5.5.6-201.fc31, origin/f31)
   Author: Josh Boyer <jwboyer@fedoraproject.org>
   Date:   Mon Feb 24 23:09:20 2020 +0000

       kernel-5.5.6-201.fc31 configs

Create the patch,

.. code-block:: shell

   $ git format-patch -o /tmp 4382f76bc8ef9fce5e7e96d4cdb0c073564ad249
   /tmp/0001-fix-RIP-ucsi_displayport_remove_partner.patch

$ rpmdev-setuptree

effect: empty structure

$ tree ~/rpmbuild/
/home/jfasch/rpmbuild/
├── BUILD
├── RPMS
├── SOURCES
├── SPECS
└── SRPMS

kernel rpm/spec
...............

which? -> ls -l /boot -> vmlinuz-5.4.13-201.fc31.x86_64 -> 5.4.13-201.fc31

$ koji download-build --arch=src kernel-5.4.13-201.fc31

-> kernel-5.4.13-201.fc31.src.rpm

$ rpm -Uvh kernel-5.4.13-201.fc31.src.rpm 

effect: source rpm placed into ~/rpmbuild

$ tree ~/rpmbuild/
/home/jfasch/rpmbuild/
├── BUILD
├── RPMS
├── SOURCES
│   ├── 0001-crypto-ccp-Release-all-allocated-memory-if-sha-type-.patch
│   ├── 0001-Drop-that-for-now.patch
... (blah) ...
├── SPECS
│   └── kernel.spec
└── SRPMS

apply patch
...........

$ cp /tmp/0001-fix-RIP-ucsi_displayport_remove_partner.patch ~/rpmbuild/SOURCES/RIP-ucsi_displayport_remove_partner.patch

$ cd ~/rpmbuild/SPECS/

* uncomment buildid
* add patch

literalinclude spec diff

build
.....

$ rpmbuild -bb --target=x86_64 kernel.spec

install
.......

rpm -ivh --oldpackage \
   ~/rpmbuild/RPMS/x86_64/kernel-core-5.4.13-201.local.fc31.x86_64.rpm \
   ~/rpmbuild/RPMS/x86_64/kernel-modules-5.4.13-201.local.fc31.x86_64.rpm

disable secure boot

Links
-----

https://fedoraproject.org/wiki/Building_a_custom_kernel/Source_RPM

.. rubric:: Footnotes

.. [#exploded_tree] Yes, the patches are created from the Git
                    repository we are working with.
