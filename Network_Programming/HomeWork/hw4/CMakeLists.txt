cmake_minimum_required(VERSION 3.10)

project(home_work_4 C CXX)

add_subdirectory(tcp_client)
add_subdirectory(tcp_server)

if (UNIX)
    add_subdirectory(asio_server)
endif()

