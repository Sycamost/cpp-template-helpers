# CMakeList.txt : CMake project for cpp-template-helpers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.19)

project ("cpp-template-helpers")

# Add source to this project's executable.
add_executable (cpp-template-helpers "tester.cpp" "template_helpers.h" "is_comparison.h" "is_equatable.h" "is_member_of.h" "template_helpers.h" "is_streamable.h" "convert_string.h")
set_property(TARGET cpp-template-helpers PROPERTY CXX_STANDARD 17)

# TODO: Add tests and install targets if needed.
