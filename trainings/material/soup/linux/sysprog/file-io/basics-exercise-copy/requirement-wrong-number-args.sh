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

set +e

$BUILD/cp-for-the-poor only-one-arg

status=$?
if [ $status -ne 1 ]; then
    error "NOT FAILED with exit status 1 (was: $status): $BUILD/cp-for-the-poor only-one-arg"
fi
