cmake_minimum_required(VERSION 3.10)

project(tcp_client_4)

set(SRC  main.cpp)
set(HEADER )

add_executable(tcp_client_4 ${SRC} ${HEADER})
target_link_libraries("${PROJECT_NAME}" socket-wrapper)

if(WIN32)
  target_link_libraries("${PROJECT_NAME}" wsock32 ws2_32)
endif()

