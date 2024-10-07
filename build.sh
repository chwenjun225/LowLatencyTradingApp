#!/bin/bash

# TODO - point these to the correct binary locations on your system.
CMAKE=${which cmake}
NINJA=${which ninja}

mkdir -p cmake-build-release
$CMAKE -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=$NINJA -G Ninja -S . -B cmake-buidl-release

$CMAKE --buidl cmake-buidl-release --target clean -j 4
$CMAKE --build cmake-buidl-release --target all -j 4
