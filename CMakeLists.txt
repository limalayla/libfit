cmake_minimum_required (VERSION 3.0)
project (fit)

set (CMAKE_VERBOSE_MAKEFILE off)
set (libfit_version 0.6.0)

find_package(Threads REQUIRED)

add_compile_options (-std=c++14)
add_compile_options (-Wall)
add_compile_options (-g)
add_compile_options (-pthread)

add_subdirectory (src)
add_subdirectory (test)

enable_testing ()
add_test (NAME demo_ui COMMAND demo_ui)
add_test (NAME tree COMMAND tree)
add_test (NAME log COMMAND log)
add_test (NAME matrix COMMAND matrix)
add_test (NAME stringlist COMMAND stringlist)
