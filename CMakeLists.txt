cmake_minimum_required(VERSION 3.6)
set(LST_TITLE LogSpoT)
project(${LST_TITLE})

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

# Version number
set(LST_VERSION_MAJOR 0)
set(LST_VERSION_MINOR 1)
set(LST_NAME logspot)

# Settings
if(${LST_LOGGING})
	add_definitions(-DLST_LOGGING)
endif()

# Includes
set(LST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${LST_INCLUDE_DIR})

# Sources
set(LST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(SOURCES ${LST_SOURCE_DIR}/Logger.cpp)
source_group(Source FILES ${SOURCES})

# Library
add_library(${LST_NAME} ${SOURCES})
set_target_properties(${LST_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Test
set(LST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
include(${LST_TEST_DIR}/Tests.cmake)
include(CTest)
