// Copyright 2023 Bob Gardner

#include <memory>               // for allocator

#include "gtest/gtest.h"        // for Test, EXPECT_EQ, Message, TEST, TestP...

#include "{{ cookiecutter.project_name }}/lib.hpp" // for add

namespace {{ cookiecutter.project_name }} {
namespace {

TEST(LibTest, AddTest) { EXPECT_EQ({{ cookiecutter.project_name }}::Add(1, 1), 2); }

} // namespace
}
