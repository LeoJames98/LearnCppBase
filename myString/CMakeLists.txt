cmake_minimum_required(VERSION 3.16)

project(myString LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myString main.cpp
    mystring.h mystring.cpp)

include(GNUInstallDirs)
install(TARGETS myString
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
