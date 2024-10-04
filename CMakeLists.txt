cmake_minimum_required(VERSION 3.12)
project(Tire_Model_Codegen)


add_library(matlab_math_lib SHARED
    rt_nonfinite.cpp
    rtGetNaN.cpp
    Tire_Model_Codegen.cpp
    Tire_Model_Codegen_data.cpp
    ert_main.cpp
)

target_include_directories(matlab_math_lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

include(GNUInstallDirs)

install (TARGETS matlab_math_lib DESTINATION ${CMAKE_INTALL_BINDIR})