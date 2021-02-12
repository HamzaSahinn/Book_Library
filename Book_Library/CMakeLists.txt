cmake_minimum_required(VERSION 3.17)
project(Book_Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Book_Library main.cpp User.cpp User.h book.cpp book.h Utils.cpp Utils.h User_Menu.cpp User_Menu.h Menu.cpp Menu.h Admin_Menu.cpp Admin_Menu.h Admin.cpp Admin.h)