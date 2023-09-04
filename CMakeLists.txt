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

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME}
    BASE_NAME ${PROJECT_NAME}
    EXPORT_MACRO_NAME PUBLIC_JELLER_API
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/jeller/export_jeller_api.hpp
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIRECTORY})