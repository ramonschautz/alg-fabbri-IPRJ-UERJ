cmake_minimum_required(VERSION 3.10)
project(alg)

# Set C standard and flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

# Set C++ standard and flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

# Add googletest
add_subdirectory(third_party/googletest)

# Add benchmark
add_subdirectory(third_party/benchmark)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(hw1)

# Custom target to run benchmarks
add_custom_target(eval
  COMMAND bm-jl-cmd
  DEPENDS bm-jl-cmd
  COMMENT "Running junta_listas benchmark"
)
