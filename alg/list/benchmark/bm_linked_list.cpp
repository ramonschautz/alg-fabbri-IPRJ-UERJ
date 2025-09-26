#include <benchmark/benchmark.h>
#include "../linked_list.h"
#include <vector>
#include <string>

// --- Benchmark for Singly Linked List ---
static void BM_InserirSimples_Inicio(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    ListaSimples lista = NULL;
    state.ResumeTiming();
    for (int i = 0; i < state.range(0); ++i) {
      inserirSimples(&lista, 0, "test");
    }
    // Cleanup
    state.PauseTiming();
    while (lista != NULL) {
      NoSimples* temp = lista;
      lista = lista->next;
      free(temp);
    }
    state.ResumeTiming();
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InserirSimples_Inicio)->Range(8, 8<<10)->Complexity(benchmark::o1);

static void BM_InserirSimples_Fim(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    ListaSimples lista = NULL;
    int count = 0;
    state.ResumeTiming();
    for (int i = 0; i < state.range(0); ++i) {
      inserirSimples(&lista, count++, "test");
    }
    // Cleanup
    state.PauseTiming();
    while (lista != NULL) {
      NoSimples* temp = lista;
      lista = lista->next;
      free(temp);
    }
    state.ResumeTiming();
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InserirSimples_Fim)->Range(8, 8<<10)->Complexity(benchmark::oN);


// --- Benchmark for Doubly Linked List ---
static void BM_InserirDupla_Inicio(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    ListaDupla lista = NULL;
    state.ResumeTiming();
    for (int i = 0; i < state.range(0); ++i) {
      inserirDupla(&lista, 0, "test");
    }
    // Cleanup
    state.PauseTiming();
    while (lista != NULL) {
      NoDuplo* temp = lista;
      lista = lista->next;
      free(temp);
    }
    state.ResumeTiming();
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InserirDupla_Inicio)->Range(8, 8<<10)->Complexity(benchmark::o1);

static void BM_InserirDupla_Fim(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    ListaDupla lista = NULL;
    int count = 0;
    state.ResumeTiming();
    for (int i = 0; i < state.range(0); ++i) {
      inserirDupla(&lista, count++, "test");
    }
    // Cleanup
    state.PauseTiming();
    while (lista != NULL) {
      NoDuplo* temp = lista;
      lista = lista->next;
      free(temp);
    }
    state.ResumeTiming();
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InserirDupla_Fim)->Range(8, 8<<10)->Complexity(benchmark::oN);


// --- Benchmark for Circular Buffer ---
static void BM_InserirCircular(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    BufferCircular cb;
    inicializarCircular(&cb);
    state.ResumeTiming();
    for (int i = 0; i < state.range(0); ++i) {
      inserirCircular(&cb, "test");
    }
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InserirCircular)->Range(8, 8<<10)->Complexity(benchmark::o1);


BENCHMARK_MAIN();
