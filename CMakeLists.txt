cmake_minimum_required(VERSION 4.1)
project(ProiectInfo)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ProiectInfo main.cpp
        gui.cpp
        gui.h
        manager.cpp
        manager.h
        console.cpp
        console.h
)

target_link_libraries(ProiectInfo PRIVATE Qt6::Widgets)