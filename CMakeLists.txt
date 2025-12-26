cmake_minimum_required(VERSION 3.16)

project(irtxt
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_executable(irtxt
  #src/main.cpp
    #src/ted_buffer/gap_buffer.cpp
    #)

    #target_include_directories(irtxt PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_executable(gapbuffer_test
    tests/buffer_test_gap.cpp
    src/ted_buffer/gap_buffer.cpp
)
target_include_directories(gapbuffer_test PRIVATE include)
#
#install(TARGETS irtxt
#       RUNTIME DESTINATION bin)


