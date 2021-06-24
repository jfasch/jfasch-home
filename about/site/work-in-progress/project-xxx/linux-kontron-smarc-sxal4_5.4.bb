# linux-kontron-smarc-sxal4.bb:

require recipes-kernel/linux/linux-yocto.inc

FILESEXTRAPATHS_prepend = "${THISDIR}/linux-kontron-smarc-sxal4:"

LINUX_VERSION ?= "5.4.45"
LINUX_VERSION_EXTENSION = "-sxal4"
LINUX_KERNEL_TYPE = "standard"

KBRANCH = "v5.4/standard/base"
KMETA = "kernel-meta"

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

SRCREV_machine_pn-linux-kontron-smarc-sxal4 ?= "3604bc07c035939266d78d65084c6cd54ffc6d56"
SRCREV_meta_pn-linux-kontron-smarc-sxal4 ?= "8d42b14fe517ef036dc4e7b290f16d142f4f1d39"

SRC_URI = "git://git.yoctoproject.org/linux-yocto;protocol=git;name=machine;branch=${KBRANCH};bareclone=1 \
           git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-5.4;destsuffix=${KMETA}"

SRC_URI += "file://kontron-smarc-sxal4-standard.scc \
            file://kontron-smarc-sxal4.scc \
            file://kontron-smarc-sxal4.cfg \
           "

PV = "${LINUX_VERSION}+git${SRCPV}"

INCLUDE_PATCHES := "${THISDIR}/linux-kontron-smarc-sxal4/patches-5.4"

include linux-patches.inc

COMPATIBLE_MACHINE = "kontron-smarc-sxal4"

include linux-common.inc
