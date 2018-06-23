cmake_minimum_required(VERSION 3.6)

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

set(LST_TITLE LogSpot)
project(${LST_TITLE} C CXX)

# Version number
set(LST_VERSION_MAJOR 0)
set(LST_VERSION_MINOR 2)
set(LST_NAME logspot)

# Settings
if(${LST_LOGGING})
	add_definitions(-DLST_LOGGING)
endif()

# Includes and Libs
set(LST_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(LST_LIBRARIES ${LST_NAME})
if(${CMAKE_SYSTEM_NAME} MATCHES "Android")
	set(LST_INCLUDE_DIRS ${LST_INCLUDE_DIRS} ${CMAKE_ANDROID_NDK}/sysroot/usr/include)
	set(LST_LIBRARIES ${LST_LIBRARIES} log)
endif()

# Sources
set(LST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(SOURCES ${LST_SOURCE_DIR}/Logger.cpp)
source_group(Source FILES ${SOURCES})

# Library
add_library(${LST_NAME} ${SOURCES})
target_include_directories(${LST_NAME} PUBLIC ${LST_INCLUDE_DIRS})

# Test
set(LST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
include(${LST_TEST_DIR}/Tests.cmake)
include(CTest)
