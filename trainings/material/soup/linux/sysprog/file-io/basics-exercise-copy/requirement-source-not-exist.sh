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

REQDIR=$BUILD/requirement-source-not-exist
if [ -e $REQDIR ]; then
    rm -rf $REQDIR
fi
mkdir -p $REQDIR

set +e

$BUILD/cp-for-the-poor $REQDIR/notexist $REQDIR/shouldnotexist
status=$?

if [ $status -ne 2 ]; then
    error "NOT FAILED with exit status 2 (was: $status): $BUILD/cp-for-the-poor $REQDIR/notexist $REQDIR/shouldnotexist"
fi
