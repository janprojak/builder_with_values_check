# Improved Builder

This repository contains a working approach to create a `Builder` class that automates the verification the presense of all required values before object build.

# Repository overview
Repository contains a `Car` class that is a pretty simplified abstraction over the real car placed in the `car.hpp` file.

A `CarBuilder` class is responsible for a proper `Car` object creation placed in the `car_Builder.hpp` file.

There are a bunch of tests that verify correct work placed in the `test.hpp`.

# Build
To build follow the next instructions:
```bash
mkdir build/ && cd build/
cmake -DCMAKE_BUILD_TYPE=Debug ../
make
```

# Run
To run follow the next instructions:
```bash
cd build 
./improved_builder
```
If everything is okay, the execution will end-up in the following message:
```bash
ALL TESTS PASSED
```