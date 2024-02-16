cmake_minimum_required(VERSION 3.27)
project(DBO_Lab1)

set(CMAKE_CXX_STANDARD 17)

include_directories(Headers)

add_executable(DBO_Lab1 main.cpp
        Headers/Publisher.h
        Sources/Publisher.cpp
        Headers/Constants.h
        Headers/Book.h
        Sources/Book.cpp)
