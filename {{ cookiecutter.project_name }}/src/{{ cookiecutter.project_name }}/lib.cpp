#include "{{ cookiecutter.project_name }}/lib.hpp"

namespace {{ cookiecutter.project_name }} {

auto add(int left, int right) -> int {
  return left + right;
}

} // namespace {{ cookiecutter.project_name }}
