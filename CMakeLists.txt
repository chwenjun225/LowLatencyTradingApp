﻿cmake_minimum_required(VERSION 3.0)

project(LowLatencyTradingApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -Werror -Wpedantic")
set(CMAKE_VERBOSE_MAKEFILE on)

add_subdirectory(common)
add_subdirectory(exchange)

list(APPEND LIBS libcommon)
list(APPEND LIBS libexchange)
list(APPEND LIBS pthread)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/exchange)
include_directories(${PROJECT_SOURCE_DIR}/common)

add_executable(exchange_main exchange/exchange_main.cpp)
target_link_libraries(exchange_main PUBLIC ${LIBS})