# Bob Gardner's Cookiecutter C++ Project Template

[Cookiecutter](https://cookiecutter.readthedocs.io/en/2.1.1/index.html) template for C++ projects.

## Usage

```sh
cookiecutter gh:rgardner/cpp_template
```

## Tools

-   (Meta) build system: [CMake](https://cmake.org/)
-   Package manager: [vcpkg](https://vcpkg.io/en/index.html)
-   Project layout: [The Pitchfork Layout](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)
-   Formatting:
    -   C++: [Clang Format](https://clang.llvm.org/docs/ClangFormat.html)
    -   CMake: [cmakelang.format](https://github.com/cheshirekow/cmake_format)
-   Linting:
    -   C++: [Clang Tidy](https://clang.llvm.org/extra/clang-tidy/)
    -   CMake: [cmakelang.lint](https://github.com/cheshirekow/cmake_format)
-   Task runner: [just](https://github.com/casey/just)
