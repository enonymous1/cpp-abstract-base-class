cmake_minimum_required(VERSION 3.27)
project(cpp_abstract_base_class)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_abstract_base_class
        AbstractBaseClass.cpp
        Base.cpp
        Base.h
        Employee.cpp
        Employee.h
        Header.h
        Student.cpp
        Student.h)
