#include "benchmark/benchmark.h"
#include "tree.h"

static void BM_Sum(benchmark::State& state) {
  No3* raiz = plant_tree((char*)"raiz");
  raiz->esquerda = plant_tree((char*)"esq");
  raiz->meio = plant_tree((char*)"meio");
  raiz->direita = plant_tree((char*)"dir");
  for (auto _ : state) {
    Sum(raiz);
  }
}
BENCHMARK(BM_Sum);

BENCHMARK_MAIN();
