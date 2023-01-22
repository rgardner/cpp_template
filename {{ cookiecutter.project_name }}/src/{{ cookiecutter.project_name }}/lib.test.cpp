#include <memory>               // for allocator

#include "gtest/gtest.h"        // for Test, EXPECT_EQ, Message, TEST, TestP...

#include "{{ cookiecutter.project_name }}/lib.hpp" // for add

namespace {{ cookiecutter.project_name }} {
namespace {

TEST(LibTest, AddTest) { EXPECT_EQ({{ cookiecutter.project_name }}::add(1, 1), 2); }

} // namespace
}
