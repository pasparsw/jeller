#!/bin/bash

set -e

BUILD_TYPE=$1

if [ -z "$BUILD_TYPE" ]
then
    BUILD_TYPE=Debug
fi

SCRIPTS_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_DIR=$SCRIPTS_DIR/..
JELLER_BUILD_DIR=$REPO_DIR/build
EXAMPLE_DIR=$REPO_DIR/examples
EXAMPLE_BUILD_DIR=$EXAMPLE_DIR/build

echo ----- Build type: $BUILD_TYPE -----

echo "----- Configuring CMake for Jeller for sources in $REPO_DIR and build in $JELLER_BUILD_DIR -----"
cmake -S $REPO_DIR -B $JELLER_BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_EXAMPLES=1
echo "----- Jeller CMake configuration done -----"

echo "----- Building Jeller in $JELLER_BUILD_DIR -----"
cmake --build $JELLER_BUILD_DIR --config $BUILD_TYPE
echo "----- Jeller build done -----"

echo "----- Installing Jeller in $JELLER_BUILD_DIR -----"
cmake --install $JELLER_BUILD_DIR --config $BUILD_TYPE
echo "----- Jeller installation done -----"