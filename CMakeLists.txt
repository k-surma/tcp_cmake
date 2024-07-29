cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0167 NEW)

project(tcp_asio)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    tcp_asio.cpp
    tcp_connect.cpp
)

set(HEADERS
    tcp_connect.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Sprawdü, czy istnieje plik local_config.cmake i wczytaj go
if(EXISTS "${CMAKE_SOURCE_DIR}/local_config.cmake")
    include("${CMAKE_SOURCE_DIR}/local_config.cmake")
endif()

# Znalezienie Boost
find_package(Boost 1.70 REQUIRED COMPONENTS system)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
else ()
    message(FATAL_ERROR "Could not find Boost")
endif ()
