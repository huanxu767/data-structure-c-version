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
        SqList/SingleLinkList.h
        SqList/DoubleLinkedList.cpp
        SqList/DoubleLinkedList.h

        算法题/链表/T1.cpp
        算法题/链表/T1.h
        算法题/链表/T2.cpp
        算法题/链表/T2.h
        算法题/链表/T3.cpp
        算法题/链表/T3.h 算法题/链表/T4.cpp
        算法题/链表/T4.h 算法题/链表/T5.cpp
        算法题/链表/T5.h 算法题/链表/T6.cpp
        算法题/链表/T6.h
        tree/BinaryTree.cpp tree/BinaryTree.h
        base/stackDemo.cpp base/stackDemo.h)