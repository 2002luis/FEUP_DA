# By: Gonçalo Leão

cmake_minimum_required(VERSION 3.17)
project(DA_TP_Classes)
set(CMAKE_CXX_STANDARD 11)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

# Add the source files of each TP class
file(GLOB DATA_STRUCTURES_FILES CONFIGURE_DEPENDS "data_structures/*.cpp")
file(GLOB CLOSEST_POINT_PAIR_FILES CONFIGURE_DEPENDS "running_examples/closest_point_pair/*.cpp")
file(GLOB TP1_FILES CONFIGURE_DEPENDS "TP1/*.cpp")
file(GLOB TP2_FILES CONFIGURE_DEPENDS "TP2/*.cpp")
file(GLOB TP3_FILES CONFIGURE_DEPENDS "TP3/*.cpp")
file(GLOB TP4_FILES CONFIGURE_DEPENDS "TP4/*.cpp")
file(GLOB TP5_FILES CONFIGURE_DEPENDS "TP5/*.cpp")
file(GLOB TP7_FILES CONFIGURE_DEPENDS "TP7/*.cpp")
#...

# Create a library for the support data structures
add_library(DATA_STRUCTURES ${DATA_STRUCTURES_FILES})
add_library(CLOSEST_POINT_PAIR ${CLOSEST_POINT_PAIR_FILES})

# Create an executable for each TP class
add_executable(TP1 main.cpp ${TP1_FILES} TP1/TestAux.cpp)
add_executable(TP2 main.cpp ${TP2_FILES})
add_executable(TP3 main.cpp ${TP3_FILES})
add_executable(TP4 main.cpp ${TP4_FILES})
add_executable(TP5 main.cpp ${TP5_FILES})
add_executable(TP7 main.cpp ${TP7_FILES})
#...

# Link the libraries for each TP class executable
target_link_libraries(CLOSEST_POINT_PAIR gtest_main gmock_main)
target_link_libraries(TP1 DATA_STRUCTURES gtest_main gmock_main)
target_link_libraries(TP2 DATA_STRUCTURES CLOSEST_POINT_PAIR gtest_main gmock_main)
target_link_libraries(TP3 DATA_STRUCTURES CLOSEST_POINT_PAIR gtest_main gmock_main)
target_link_libraries(TP4 DATA_STRUCTURES CLOSEST_POINT_PAIR gtest_main gmock_main)
target_link_libraries(TP5 DATA_STRUCTURES gtest_main gmock_main)
target_link_libraries(TP7 DATA_STRUCTURES gtest_main gmock_main)
#...