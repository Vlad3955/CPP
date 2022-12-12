cmake_minimum_required(VERSION 3.10)

project(cpp-network-lesson-8)

if (UNIX)
    add_subdirectory("libtorrent")
endif()
