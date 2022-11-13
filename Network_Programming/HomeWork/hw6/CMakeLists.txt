cmake_minimum_required(VERSION 3.10)

project(home_work_6 C CXX)



if (UNIX)
    add_subdirectory(HTTP_server)
endif()

