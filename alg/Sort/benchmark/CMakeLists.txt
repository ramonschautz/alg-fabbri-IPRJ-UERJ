add_executable(bm-sort-cmd bm_sort.cpp)
target_link_libraries(bm-sort-cmd PRIVATE sort benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-sort-cmd)
