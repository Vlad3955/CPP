cmake_minimum_required(VERSION 3.10)

project(udp_client)

set(SRC uclient.cpp main.cpp)
set(HEADER uclient.h)

add_executable(udp_client ${SRC} ${HEADER})
target_link_libraries("${PROJECT_NAME}" socket-wrapper)

if(WIN32)
  target_link_libraries("${PROJECT_NAME}" wsock32 ws2_32)
endif()

