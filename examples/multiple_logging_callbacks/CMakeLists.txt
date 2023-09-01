cmake_minimum_required(VERSION 3.10)

set(TARGET multiple_logging_callbacks)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${TARGET} PRIVATE
    Jeller
)

install(TARGETS ${TARGET} DESTINATION ${INSTALL_DIRECTORY})