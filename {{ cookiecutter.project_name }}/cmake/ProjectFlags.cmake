add_library({{ cookiecutter.__cmake_project_flags_target_name }} INTERFACE)
add_library({{ cookiecutter.__cmake_project_flags_target_name_ns }} ALIAS {{ cookiecutter.__cmake_project_flags_target_name }})

target_compile_options(
  {{ cookiecutter.__cmake_project_flags_target_name }}
  INTERFACE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall
    -Wextra
    -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4
    /permissive->)
