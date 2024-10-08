cmake_minimum_required(VERSION 3.12)
project(Tire_Model_Codegen)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INCLUDE_HEADERS_IN_COMPILE_COMMANDS ON)

add_library(matlab_math_lib SHARED
    src/Tire_Model_Codegen.cpp
    src/HT09_Linear_Vehicle_Model_data.cpp
    src/HT09_Linear_Vehicle_Model.cpp
    src/const_params.cpp
    src/interp1_ctBBGdhl.cpp
    src/look1_binlcapw.cpp
    src/maximum_kQ2v6WLV.cpp
    src/minimum_5X1FIofZ.cpp
    src/repelem_u5I1BzYw.cpp
    src/rt_nonfinite.cpp
    src/rtGetNaN.cpp
)

target_include_directories(matlab_math_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
install(TARGETS matlab_math_lib
  EXPORT matlab_mathTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include
)

# NAMESPACE sets the namespace that your target will live within.
# you can have multiple targets under the same namespace
install(EXPORT matlab_mathTargets
  FILE matlab_mathTargets.cmake
  NAMESPACE matlab_math::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/matlab_math
)

# this looks for your .cmake.in file that you created in step 1.
# if you set the directory differently you may need to handle this differently
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/matlab_mathConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/matlab_mathConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/matlab_math
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/matlab_mathConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/matlab_math
)

# actually install your header files
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h*"
)