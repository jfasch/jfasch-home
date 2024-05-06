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

REQDIR=$BUILD/requirement-dest-dir-not-writeable
if [ -e $REQDIR ]; then
    rm -rf $REQDIR
fi
mkdir -p $REQDIR

chmod u-w $REQDIR

set +e

$BUILD/cp-for-the-poor /etc/passwd $REQDIR/dstfile

status=$?
if [ $status -ne 4 ]; then
    error "NOT FAILED with exit status 4 (was: $status): $BUILD/cp-for-the-poor /etc/passwd $REQDIR/dstfile"
fi
