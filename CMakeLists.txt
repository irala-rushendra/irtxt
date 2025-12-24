cmake_minimum_required(VERSION 3.16)

project(irtxt
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(irtxt
    src/main.cpp
)

install(TARGETS irtxt
        RUNTIME DESTINATION bin)

