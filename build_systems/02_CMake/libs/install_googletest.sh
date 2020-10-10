#!/usr/bin/env bash

# delete anything already downloaded
rm -r googletest

mkdir googletest
pushd googletest

# download the lib to googletest.tar.gz
wget https://github.com/google/googletest/archive/release-1.10.0.tar.gz \
     -O googletest.tar.gz

# extract the file into this directory,
# skipping past the top-level directory in the archive
# (from https://unix.stackexchange.com/a/11019)
tar xf googletest.tar.gz -C . --strip-components 1

mkdir build
pushd build
cmake ..

make

# copy the files we built to the appropriate locations
cp lib/* ../../lib

# also copy headers
popd # back to googletest
cp -r googletest/include/* ../include

popd # back to libs
