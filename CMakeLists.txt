cmake_minimum_required(VERSION 4.1)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp
        Book.cpp
        Book.h
        Magazine.cpp
        Magazine.h
        Library.cpp
        Library.h
        Accounts.cpp
        Accounts.h
        FileHandler.cpp
        FileHandler.h
        AccountTypeEnum.cpp
        AccountTypeEnum.h)
