cmake_minimum_required(VERSION 3.10)

project(Jeller)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(INSTALL_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

add_subdirectory(examples)

add_definitions(-DEXPORT_JELLER_API=1)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIRECTORY})