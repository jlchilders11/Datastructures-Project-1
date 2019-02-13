# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Data Structures Project 1")

# Include sub-projects.
add_subdirectory ("Data Structures Project 1")

set_target_properties(
    CMakeTarget PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")