cmake_minimum_required(VERSION 3.10)

project(udp_server)

set(SRC userver.cpp main.cpp)
set(HEADER userver.h)

add_executable(udp_server ${SRC} ${HEADER})
target_link_libraries("${PROJECT_NAME}" socket-wrapper)

if(WIN32)
  target_link_libraries("${PROJECT_NAME}" wsock32 ws2_32)
endif()

