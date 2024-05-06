#!/bin/sh

set -e

error() {
    echo ERROR: $* 1>&2
    exit 1
}

if [ $# -ne 1 ]; then
    error "Usage: $0 <builddir>"
fi

BUILD=$1

REQDIR=$BUILD/requirement-sunny
if [ -e $REQDIR ]; then
    rm -rf $REQDIR
fi
mkdir -p $REQDIR

cp /etc/passwd $REQDIR/sourcefile

set +e

$BUILD/cp-for-the-poor $REQDIR/sourcefile $REQDIR/dstfile

status=$?
if [ $status -ne 0 ]; then
    error "FAILED with exit status $status: $BUILD/cp-for-the-poor $REQDIR/sourcefile $REQDIR/dstfile"
fi

if ! cmp $REQDIR/sourcefile $REQDIR/dstfile; then
    diff -u $REQDIR/sourcefile $REQDIR/dstfile 1>&2
    error $REQDIR/sourcefile $REQDIR/dstfile are not equal
fi
