cmake_minimum_required(VERSION 3.10)

set(TARGET custom_default_logging_callback)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${TARGET} PRIVATE
    Jeller
)

install(TARGETS ${TARGET} DESTINATION ${INSTALL_DIRECTORY})