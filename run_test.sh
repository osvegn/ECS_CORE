#!/bin/bash
mkdir -p build
cd build
cmake -DTESTING=ON ..
cmake --build . -j
ctest --output-on-failure