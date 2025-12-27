#cmake_minimum_required(VERSION 3.16)

#project(irtxt
  #VERSION 0.1.0
    #LANGUAGES CXX
    #)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

#add_executable(irtxt
  #src/main.cpp
    #src/ted_buffer/gap_buffer.cpp
    #)

    #target_include_directories(irtxt PRIVATE ${PROJECT_SOURCE_DIR}/include)

# -------- File IO test --------
#add_executable(file_io_test
#   tests/io_test.cpp
#   src/ted_utils/file_io.cpp
#   src/ted_utils/editor.cpp
#   src/ted_buffer/gap_buffer.cpp
#)

#target_include_directories(file_io_test PRIVATE include)


#
#install(TARGETS irtxt
#       RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.16)

project(irtxt
    VERSION 0.1.0
    LANGUAGES CXX
)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Include directory ----
include_directories(${PROJECT_SOURCE_DIR}/include)

# ============================================================
# Core library (editor engine)
# ============================================================
add_library(irtxt_core
    src/ted_buffer/gap_buffer.cpp
    src/ted_utils/editor.cpp
    src/ted_utils/file_io.cpp
)

target_include_directories(irtxt_core
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# ============================================================
# Main executable (temporary CLI / test driver)
# ============================================================
add_executable(irtxt
    src/main.cpp
)

target_link_libraries(irtxt
    PRIVATE irtxt_core
)

# ============================================================
# Tests
# ============================================================
enable_testing()

add_executable(buffer_test_gap
    tests/buffer_test_gap.cpp
)
target_link_libraries(buffer_test_gap PRIVATE irtxt_core)
add_test(NAME buffer_test_gap COMMAND buffer_test_gap)

add_executable(editor_utils_test
    tests/ed_utils_test.cpp
)
target_link_libraries(editor_utils_test PRIVATE irtxt_core)
add_test(NAME editor_utils_test COMMAND editor_utils_test)

add_executable(io_test
    tests/io_test.cpp
)
target_link_libraries(io_test PRIVATE irtxt_core)
add_test(NAME io_test COMMAND io_test)

# ============================================================
# Install (optional, future use)
# ============================================================
install(TARGETS irtxt
    RUNTIME DESTINATION bin
)

