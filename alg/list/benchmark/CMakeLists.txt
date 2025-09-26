add_executable(bm-linked_list-cmd bm_linked_list.cpp)
target_link_libraries(bm-linked_list-cmd PRIVATE list benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-linked_list-cmd)
