# cardshuffler
Simple example using CMake, Conan and Google Test Framework.

## Setup Instructions

```shell
pip install --user --upgrade conan
```

## Build Instructions

```shell
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target all test
```
