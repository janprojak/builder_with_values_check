#-------------------------------------------------------------------#
# cmake version

cmake_minimum_required(VERSION 3.22)

#-------------------------------------------------------------------#
# project flags config

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

#-------------------------------------------------------------------#
# project config

project(improved_builder)

#-------------------------------------------------------------------#
# project sources

set(SOURCES
    car_builder.hpp
    car.hpp
    test.hpp
    main.cpp
)

#-------------------------------------------------------------------#
# project type

add_executable(${PROJECT_NAME} ${SOURCES})

#-------------------------------------------------------------------#
# include directories

target_include_directories(${PROJECT_NAME}
    PRIVATE .
)

#-------------------------------------------------------------------#