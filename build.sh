#!/usr/bin/env bash

rm -r build

mkdir build

cd build

cmake -DCMAKE_PREFIX_PATH="${CONDA_PREFIX}"\
      -DCMAKE_BUILD_TYPE=Release \
      ..
      
cmake --build . 
