cmake_minimum_required(VERSION 3.22)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(SinglyLinkedList linear-list/SinglyLinkedList.cpp)
add_executable(SequenatialList linear-list/SequenatialList.cpp)
add_executable(DoubleLinkedList linear-list/DoubleLinkedList.cpp)