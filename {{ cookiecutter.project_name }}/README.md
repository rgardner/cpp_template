# {{ cookiecutter.project_name }}

## Getting Started

Prerequisites:

-   [Install just](https://github.com/casey/just)
-   [Install CMake](https://cmake.org/)
-   [Install Clang Format](https://clang.llvm.org/docs/ClangFormat.html)
-   [Install Clang Tidy](https://clang.llvm.org/extra/clang-tidy/)

```sh
$ just --list
Available recipes:
    build     # Compiles the project
    ci        # Runs CI validation
    clean     # Deletes build files
    cpp-fmt   # Formats C++ files
    fmt       # Formats C++ and CMake files
    fmt-check # Checks formatting of C++ and CMake files
    lint      # Runs static analysis
    lint-fix  # Fixes static analysis warnings
    setup     # Installs tools and prepares build environment
    test      # Runs the tests

```
