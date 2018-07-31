cmake_minimum_required (VERSION 3.0)
project (threePersonProblem)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the executable
add_executable(${PROJECT_NAME} main.c bruteForcer.c)

#Run the binary
add_custom_command(
    OUTPUT run.log
    COMMAND ${CMAKE_BINARY_DIR}/threePersonProblem
    COMMENT "Running the Binary"
    VERBATIM
    )
add_custom_target(
    RUNMYPROJ ALL
    DEPENDS run.log
    )

