cmake_minimum_required(VERSION 3.10)


option(BUILD_SHARED_LIBS "Build using shared libraries" ON)


project(ref)

add_library(ref "include/SimX/simx.h" "src/ref.c")

target_include_directories(ref PUBLIC "include/SimX/")

if (BUILD_SHARED_LIBS)
	target_compile_definitions(ref PUBLIC SIMX_BUILD_DYNAMIC)
endif()
