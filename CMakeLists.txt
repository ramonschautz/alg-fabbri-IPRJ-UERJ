cmake_minimum_required(VERSION 3.10)
project(alg)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

add_subdirectory(third_party)

enable_testing()

add_subdirectory(alg)

