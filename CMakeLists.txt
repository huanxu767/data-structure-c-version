cmake_minimum_required(VERSION 3.16)
project(clearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(clearn main.cpp
        SqList/LinearTable.cpp
        SqList/LinearTable.h

        base/vector_demo.cpp
        base/vector_demo.h
        base/C_demo.c
        base/C_demo.h

        sorting_algorithm/sort.cpp
        sorting_algorithm/sort.h

        SqList/SingleLinkList.cpp
        SqList/SingleLinkList.h)