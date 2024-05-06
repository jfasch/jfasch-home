#!/bin/sh

set -e

error() {
    echo ERROR: $* 1>&2
    exit 1
}

if [ $# -ne 2 ]; then
    error "Usage: $0 <sourcedir> <builddir>"
fi

SOURCE=$1
BUILD=$2

cmake -S $SOURCE -B $BUILD
cd $BUILD && make
