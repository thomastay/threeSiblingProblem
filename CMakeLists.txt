cmake_minimum_required (VERSION 3.0)
project (threeSiblingProblem)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -O3")

# add the executable
add_executable(${PROJECT_NAME} driver.cpp threePersonSolver.cpp)

add_custom_target(
    run 
    COMMAND ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    COMMENT "Running the Binary"
    )

#Time the binary
add_custom_target(
    time 
    COMMAND time ${CMAKE_BINARY_DIR}/${PROJECT_NAME} > /dev/null
    COMMENT "Timing the Binary"
    )
