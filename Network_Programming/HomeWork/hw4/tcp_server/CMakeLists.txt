cmake_minimum_required(VERSION 3.10)

project(tcp_server_4)

set(SRC tcp_server.cpp main.cpp)
set(HEADER tcp_server.h)

add_executable(tcp_server_4 ${SRC} ${HEADER})
target_link_libraries("${PROJECT_NAME}" socket-wrapper)

if(WIN32)
  target_link_libraries("${PROJECT_NAME}" wsock32 ws2_32)
endif()

