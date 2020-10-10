#!/usr/bin/env bash

# delete anything already downloaded
rm -r easyloggingpp

mkdir easyloggingpp
pushd easyloggingpp

wget https://github.com/amrayn/easyloggingpp/archive/v9.96.7.tar.gz \
     -O easyloggingpp.tar.gz

# extract the file into this directory,
# skipping past the top-level directory in the archive
# (from https://unix.stackexchange.com/a/11019)
tar xf easyloggingpp.tar.gz -C . --strip-components 1

# copy headers
cp src/*.h ../include

# copy source
cp src/*.cc ../src
