add_subdirectory({{ cookiecutter.project_name }})

add_executable({{ cookiecutter.__cmake_main_target_name }} main.cpp)
add_executable({{ cookiecutter.__cmake_main_target_name_ns }} ALIAS {{ cookiecutter.__cmake_main_target_name }})

target_link_libraries(
  {{ cookiecutter.__cmake_main_target_name}} PRIVATE {{ cookiecutter.__cmake_project_flags_target_name_ns }}
  {{ cookiecutter.__cmake_lib_target_name_ns }})

add_custom_target(
  {{ cookiecutter.__cmake_main_target_name }}_run
  COMMAND {{ cookiecutter.__cmake_main_target_name_ns }}
  DEPENDS {{ cookiecutter.__cmake_main_target_name_ns }}
  COMMENT "Run the main app")
