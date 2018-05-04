cmake_minimum_required (VERSION 2.6)
project (pydummy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "-g -O3 -march=native -Wall -Wextra")

EXECUTE_PROCESS(
    COMMAND git describe --tags --dirty
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
    RESULT_VARIABLE GIT_DESCRIBE_RESULT
    ERROR_VARIABLE GIT_DESCRIBE_ERROR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

EXECUTE_PROCESS(
    COMMAND git rev-parse --symbolic-full-name --abbrev-ref HEAD 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    RESULT_VARIABLE GIT_BRANCH_RESULT
    ERROR_VARIABLE GIT_BRANCH_ERROR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

if(GIT_DESCRIBE_VERSION)
    # Set up the version info
    message(STATUS "Version: '${GIT_DESCRIBE_VERSION}'")
else()
    message(WARNING "Error getting 'git describe'. Are you sure you have fetched the latest tags?")
    set(GIT_DESCRIBE_VERSION "0.0.${GIT_BRANCH}")
endif()

string(REPLACE "." ";" VERSION_LIST ${GIT_DESCRIBE_VERSION})
list(GET VERSION_LIST 0 MAJOR_VERSION)
list(GET VERSION_LIST 1 MINOR_VERSION)
list(GET VERSION_LIST 2 PATCH_VERSION)
set(PATCH_VERSION "${PATCH_VERSION}")

add_definitions(-DVERSION_STRING="${GIT_DESCRIBE_VERSION}" -DBRANCH_STRING="${GIT_BRANCH}")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Find Boost
find_package(Boost REQUIRED COMPONENTS unit_test_framework python filesystem)
include_directories(${Boost_INCLUDE_DIR})

# Find Python
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})

# Build pydummy library
add_library(pydummy SHARED src/boost_wrapper.cpp)
set_target_properties(pydummy PROPERTIES PREFIX "")
target_link_libraries(pydummy ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "__all__ = ['pydummy']")

# Set up installation targets
install(TARGETS pydummy DESTINATION lib/python2.7/dist-packages)

