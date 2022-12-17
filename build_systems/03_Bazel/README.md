# Bazel

## Install Bazel
Install Bazel using [bazelisk](https://github.com/bazelbuild/bazelisk):
- download bazelisk from the [bazelisk Releases page](https://github.com/bazelbuild/bazelisk/releases)
- make it executable and run it. This will setup Bazel
- copy the executable as `bazel` to `/usr/local/bin/`

For formatting BUILD files, also install buildifier:
- downloaded from the [Bazel buildtools Releases page](https://github.com/bazelbuild/buildtools/releases)
- make it executable
- copy the executable as `buildifier` to `/usr/local/bin/`


## Official Tutorials
- [Getting started with building C++ projects with Bazel](https://bazel.build/start/cpp)
- [Common C++ build use cases](https://bazel.build/tutorials/cpp-use-cases)
- [C++ Toolchain Configuration Tutorial](https://bazel.build/tutorials/ccp-toolchain-config) and [Reference](https://bazel.build/docs/cc-toolchain-config-reference)
- [How to visualize the dependency graph](https://blog.bazel.build/2015/06/17/visualize-your-build.html)
- [Working with external dependencies](https://bazel.build/docs/external)
- [How to pass flags to the C++ compiler](https://bazel.build/docs/user-manual#cxxopt) and [linker](https://bazel.build/docs/user-manual#linkopt)

To run bazel from a docker container to ensure consistent builds across different machines/developers, consider using [dazel](https://github.com/nadirizr/dazel)


# Examples in this repo

Run a python script from bazel: `bazel run //:hello_world`
