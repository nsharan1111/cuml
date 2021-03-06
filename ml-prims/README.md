	# Introduction
This repo contains some of the common infrastructural components as well as
computational primitives, that will be useful while building a ML algo repo from
scratch.

ML Primitives is implemented as header only C++/CUDA libraries for the developers who 
would like to call these APIs from their projects. You can build and run the Google 
tests if you are interested in helping us to improve these libraries.

# Setup
## Dependencies
1. git
2. zlib
3. cmake (>= 3.8)
4. CUDA SDK (>= 9.2)

<<<<<<< HEAD

## Repo
```bash
$ git clone --recursive git@github.com:rapidsai/cuml.git
=======
4. CUDA SDK (>= 8.0)

## Repo
```bash
$ git clone --recursive git@gitlab.com:nvdevtech/ml-common.git
>>>>>>> Refactor DBSCAN to use ml-prims.
=======

## Repo
```bash
$ git clone --recursive git@github.com:rapidsai/cuml.git
>>>>>>> Updating ml-prims README
$ git submodule init
$ git submodule update
```

## In case you prefer working inside docker
```bash
$ git clone https://github.com/teju85/dockerfiles
$ cd dockerfiles/ubuntu1604
$ make ml-dev
$ cd ../..
$ ./dockerfiles/scripts/launch -runas user ml:dev /bin/bash
container$ cd /work/ml-common
```

# Running tests
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j
$ ./mlcommon_test
```

# Users
## scripts
Contains some useful scripts. Refer to [scripts](scripts/README.md).

## external
Contains submodules that this project, in-turn, depends on. Appropriate location flags
will be automatically populated in the main CMakeLists.txt file, for these.

Description of these submodules:
1. Nvidia Cutlass - Abstractions for high-performance matrix multipliciation on GPUs
2. Nvidia Cub - Primitives for high-performance, maintainable CUDA kernel code
3. Google Test - C++ test framework
