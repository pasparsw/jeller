#!/bin/bash

set -e

BUILD_TYPE=$1

if [ -z "$BUILD_TYPE" ]
then
    BUILD_TYPE=Debug
fi

SCRIPTS_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_DIR=$SCRIPTS_DIR/..
EXAMPLE_APP_BIN_DIR=$REPO_DIR/build/$BUILD_TYPE

echo "----- Running simplest_use_case example -----"
LD_LIBRARY_PATH=$EXAMPLE_APP_BIN_DIR $EXAMPLE_APP_BIN_DIR/simplest_use_case
echo "----- Running simplest_use_case example done -----"

echo "----- Running custom_default_logging_callback example -----"
LD_LIBRARY_PATH=$EXAMPLE_APP_BIN_DIR $EXAMPLE_APP_BIN_DIR/custom_default_logging_callback
echo "----- Running custom_default_logging_callback example done -----"

echo "----- Running multiple_logging_callbacks example -----"
LD_LIBRARY_PATH=$EXAMPLE_APP_BIN_DIR $EXAMPLE_APP_BIN_DIR/multiple_logging_callbacks
echo "----- Running multiple_logging_callbacks example done -----"