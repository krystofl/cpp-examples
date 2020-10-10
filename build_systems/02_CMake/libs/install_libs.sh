#!/usr/bin/env bash

# (re-)installs all libs

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")
cd $SCRIPTPATH

# delete any already-installed files
rm -r ./lib/* ./include/* ./src/*

# calling the individual scripts to install the libs
echo "Installing easyloggingpp..."
./install_easyloggingpp.sh
echo
echo

echo "Installing GoogleTest..."
./install_googletest.sh
echo
echo
