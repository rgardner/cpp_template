# =============================
# Preamble
# =============================
cmake_minimum_required(VERSION 3.24)
project(
  {{ cookiecutter.project_name }}
  VERSION 0.1.0
  LANGUAGES CXX)

# =============================
# Project wide setup
# =============================
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
if(PROJECT_IS_TOP_LEVEL)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED YES)
  set(CMAKE_CXX_EXTENSIONS NO)
  set(CMAKE_COMPILE_WARNING_AS_ERROR ON) # default to warnings as errors

  set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # improve Intellisense
  set_property(GLOBAL PROPERTY USE_FOLDERS ON) # use folders in IDEs
  set(CMAKE_XCODE_GENERATE_SCHEME YES)

  include(CTest)

  # Restrict valid build types for non-multi-config generators, e.g. cannot
  # accidently use build type 'Dbg' with Ninja.
  get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
  if(NOT isMultiConfig)
    set(_allowable_build_types Debug Release RelWithDebInfo)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
                                                 "${_allowable_build_types}")
    if(NOT CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE
          Debug
          CACHE STRING "" FORCE)
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST _allowable_build_types)
      message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
    endif()
  endif()

  include(Xcode)
endif()

option({{ cookiecutter.project_name|upper }}_BUILD_TESTING
       "Enable tests even when included as a subproject.")
option(ENABLE_ASAN_UBSAN
       "Enable AddressSanitizer (ASan) and UndefinedBehavior Sanitizer (UBSan)")
if(ENABLE_ASAN_UBSAN)
  add_compile_options(-fsanitize=address -fsanitize=undefined)
  add_link_options(-fsanitize=address -fsanitize=undefined)
  set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
  set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON)
  set(CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER ON)
endif()

option(ENABLE_TSAN "Enable ThreadSanitizer (TSan)")
if(ENABLE_TSAN)
  add_compile_options(-fsanitize=thread)
  add_link_options(-fsanitize=thread)
  set(CMAKE_XCODE_SCHEME_THREAD_SANITIZER ON)
endif()

include(ProjectFlags)

# =============================
# Main targets built by this project
# =============================
add_subdirectory(src)
