add_executable(bm-sort_char-cmd bm_sort_char.cpp)
target_link_libraries(bm-sort_char-cmd PRIVATE sort benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-sort_char-cmd)
