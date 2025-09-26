// rfabbri 2025-09-25
#include <benchmark/benchmark.h>
#include "../sort_char.h"
#include <vector>
#include <algorithm>
#include <random>

// Function to generate a random string of a given length
static std::vector<char> GenerateRandomChars(int size) {
    std::vector<char> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < size; ++i) {
        data[i] = static_cast<char>(dis(gen));
    }
    return data;
}

static void BM_SortChar(benchmark::State& state) {
  auto n = state.range(0);
  auto data = GenerateRandomChars(n);
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<char> buffer = data;
    state.ResumeTiming();

    sort_char(buffer.data(), buffer.size());
    benchmark::ClobberMemory();
  }
  state.SetComplexityN(n);
}

BENCHMARK(BM_SortChar)->RangeMultiplier(8)->Range(8, 8<<10)->Complexity();

BENCHMARK_MAIN();
