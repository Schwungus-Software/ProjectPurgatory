cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

add_subdirectory(external/raylib)

project(ProjectPurgatory CXX)

file(COPY "${CMAKE_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")

if(EMSCRIPTEN)
    set(WEB_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/assets@assets/ -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${WEB_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WEB_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

set(SOURCES
    "src/main.cpp"
    "src/camera.hpp"
    "src/camera.cpp"
    "src/runner.hpp"
    "src/runner.cpp"
    "src/scene.hpp"
    "src/scene.cpp"
    "src/title.hpp"
    "src/title.cpp"
    "src/utils.tpp")

add_executable(ProjectPurgatory ${SOURCES})

set_target_properties(ProjectPurgatory PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON)

target_include_directories(ProjectPurgatory PRIVATE src)

target_link_libraries(ProjectPurgatory raylib)
