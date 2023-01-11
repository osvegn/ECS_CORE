#!/bin/bash
cmake -B build -DTESTING=ON
cmake --build build
ctest --output-on-failure