cmake_minimum_required(VERSION 3.10)

set(TARGET simplest_use_case)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/component_one.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/component_two.cpp
)

target_link_libraries(${TARGET} PRIVATE
    Jeller
)

install(TARGETS ${TARGET} DESTINATION ${INSTALL_DIRECTORY})