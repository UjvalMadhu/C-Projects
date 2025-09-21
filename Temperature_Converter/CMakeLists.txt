cmake_minimum_required(VERSION 3.6.2)
project(TemperatureConverter)


#Set C++ Standard
set(CMAKE_CXX_STDANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#Add Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


#Add Executable
add_executable(temp_converter
    main.cpp
    temperature_converter.cpp
)


# Custom target to run the program
add_custom_target(run
    COMMAND temp_converter
    DEPENDS temp_converter
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)