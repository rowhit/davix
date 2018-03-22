#!/usr/bin/env bash
set -e

#-------------------------------------------------------------------------------
# Generate a release tarball - run this from the root of the git repository.
#-------------------------------------------------------------------------------

git submodule update --recursive --init
mkdir -p build
./genversion.py --template include/davix/features.hpp.in --out include/davix/features.hpp
./genversion.py --template packaging/davix.spec.in --out packaging/davix.spec
./genversion.py --template version.cmake.in --out version.cmake

#-------------------------------------------------------------------------------
# Patch debian changelog for current version, if needed.
#-------------------------------------------------------------------------------
packaging/patch-deb-changelog.sh "$(git log -1 --pretty=format:'%an')" "$(git log -1 --pretty=format:'%ae')"

#-------------------------------------------------------------------------------
# Extract version number, we need this for the archive name
#-------------------------------------------------------------------------------
VERSION_FULL=$(./genversion.py --template-string "@VERSION_FULL@")
printf "Version: ${VERSION_FULL}\n"
FILENAME="davix-${VERSION_FULL}"

#-------------------------------------------------------------------------------
# Make the archive
#-------------------------------------------------------------------------------
TARGET_PATH=$(basename $PWD)

pushd $PWD/..
tar --exclude '*/.git' --exclude "${TARGET_PATH}/build" --exclude "${TARGET_PATH}/credentials" --exclude "${TARGET_PATH}/_book" -pcvzf ${TARGET_PATH}/build/${FILENAME}.tar.gz ${TARGET_PATH} --transform "s!^${TARGET_PATH}!${FILENAME}!" --show-transformed-names
popd
