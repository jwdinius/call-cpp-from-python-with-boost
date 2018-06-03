cmake_minimum_required (VERSION 2.6)
project (pyExponentiate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Find Boost
find_package(Boost REQUIRED COMPONENTS unit_test_framework python filesystem)
include_directories(${Boost_INCLUDE_DIR})

# Find Python (you can change the version if you use 3.x)
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})

# Build Python Library (this creates the python interface)
add_library(pyRTP SHARED src/boost_wrapper.cpp)
set_target_properties(pyRTP PROPERTIES PREFIX "")
target_link_libraries(pyRTP ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "__all__ = ['pyRTP']")

# Build test executable (used for output comparison)
add_executable(test_cpp_rtp test/main.cpp)

# make install will install pyRTP as a python package, like you'd do with pip etc...
install(TARGETS pyRTP DESTINATION lib/python2.7/dist-packages)

