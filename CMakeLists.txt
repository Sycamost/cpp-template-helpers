# CMakeList.txt : CMake project for cpp-template-helpers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("cpp-template-helpers")

# Add source to this project's executable.
add_executable (cpp-template-helpers "tester.cpp" "template_helpers.h" "is_comparison.h" "is_equatable.h" "is_member_of.h" "template_helpers.h")

# TODO: Add tests and install targets if needed.
