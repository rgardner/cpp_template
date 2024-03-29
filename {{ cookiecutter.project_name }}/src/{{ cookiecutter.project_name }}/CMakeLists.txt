# =============================
# Define targets
# =============================
add_library({{ cookiecutter.__cmake_lib_target_name }} {{ "${" }}{{ cookiecutter.project_name }}_SOURCE_DIR{{ "}" }}/include/{{ cookiecutter.project_name }}/lib.hpp  lib.cpp)
add_library({{ cookiecutter.__cmake_lib_target_name_ns }} ALIAS {{ cookiecutter.__cmake_lib_target_name }})
target_include_directories({{ cookiecutter.__cmake_lib_target_name }} PUBLIC {{ "${" }}{{ cookiecutter.project_name }}_SOURCE_DIR{{ "}" }}/include)
target_link_libraries({{ cookiecutter.__cmake_lib_target_name }} PRIVATE {{ cookiecutter.__cmake_project_flags_target_name_ns }})

find_package(GTest CONFIG REQUIRED)
add_executable({{ cookiecutter.__cmake_test_target_name }} lib.test.cpp)
add_executable({{ cookiecutter.__cmake_test_target_name_ns }} ALIAS {{ cookiecutter.__cmake_test_target_name }})
target_link_libraries({{ cookiecutter.__cmake_test_target_name }} PRIVATE {{ cookiecutter.__cmake_project_flags_target_name_ns }} {{ cookiecutter.__cmake_lib_target_name_ns }} GTest::gtest_main)

# =============================
# Testing
# =============================
if(TEST_{{ cookiecutter.project_name|upper }} OR CMAKE_SOURCE_DIR STREQUAL {{ cookiecutter.project_name }}_SOURCE_DIR)
  # gtest_discover_tests doesn't work with Xcode 14
  add_test(NAME {{ cookiecutter.project_name }} COMMAND {{ cookiecutter.__cmake_test_target_name }})
endif()
