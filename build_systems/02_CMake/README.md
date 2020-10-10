# CMake example

Shows how to use CMake to compile a C++ project with external dependencies.

Debug executables are built in the `build-debug` folder;
Release executables in the `build-release` folder.

Run `make help` to see the available commands:

    $ make help
    usage: make [target] (option=value)

    Debug:
      debug-cmake             Use CMake to generate Makefiles for the DEBUG build
      debug                   Build the Debug version
      debug-test              Run the debug testbench
      debug-clean             Clean all debug build files

    Other:
      help                    Show this help
      install-libs            Install needed libraries under ./libs

    Release:
      release-cmake           Use CMake to generate Makefiles for the release build
      release                 Build the release version
      release-test            Run the release testbench
      release-clean           Clean all debug build files


To get started with compiling everything, you might want to run something like

    make install-libs
    make debug-cmake
    make debug

Uses [GoogleTest](https://github.com/google/googletest) for unit tests.
To run them (for the debug build), run

    make debug-test

All external libs are under `/libs`.
For this demo, it's just GoogleTest and
[easyloggingpp](https://github.com/zuhd-org/easyloggingpp)
