#include "gtest/gtest.h"
#include "../linked_list.h"
#include <string.h>

// --- Tests for Singly Linked List ---
TEST(ListaSimplesTest, InserirInicio) {
    ListaSimples lista = NULL;
    inserirSimples(&lista, 0, "a");
    inserirSimples(&lista, 0, "b");
    ASSERT_STREQ(lista->name, "b");
    ASSERT_STREQ(lista->next->name, "a");
    // Cleanup
    deletarSimples(&lista, 0);
    deletarSimples(&lista, 0);
}

TEST(ListaSimplesTest, DeletarInicio) {
    ListaSimples lista = NULL;
    inserirSimples(&lista, 0, "a");
    inserirSimples(&lista, 0, "b");
    deletarSimples(&lista, 0);
    ASSERT_STREQ(lista->name, "a");
    // Cleanup
    deletarSimples(&lista, 0);
}

// --- Tests for Doubly Linked List ---
TEST(ListaDuplaTest, InserirInicio) {
    ListaDupla lista = NULL;
    inserirDupla(&lista, 0, "a");
    inserirDupla(&lista, 0, "b");
    ASSERT_STREQ(lista->name, "b");
    ASSERT_STREQ(lista->next->name, "a");
    ASSERT_EQ(lista->prev, nullptr);
    ASSERT_EQ(lista->next->prev, lista);
    // Cleanup
    deletarDupla(&lista, 0);
    deletarDupla(&lista, 0);
}

TEST(ListaDuplaTest, DeletarInicio) {
    ListaDupla lista = NULL;
    inserirDupla(&lista, 0, "a");
    inserirDupla(&lista, 0, "b");
    deletarDupla(&lista, 0);
    ASSERT_STREQ(lista->name, "a");
    ASSERT_EQ(lista->prev, nullptr);
    // Cleanup
    deletarDupla(&lista, 0);
}

// --- Tests for Circular Buffer ---
TEST(BufferCircularTest, InserirECheio) {
    BufferCircular cb;
    inicializarCircular(&cb);
    for (int i = 0; i < TAMANHO_BUFFER; ++i) {
        inserirCircular(&cb, "test");
    }
    ASSERT_EQ(cb.count, TAMANHO_BUFFER);
    // Insert one more to cause overwrite
    inserirCircular(&cb, "overwrite");
    ASSERT_EQ(cb.count, TAMANHO_BUFFER);
    ASSERT_EQ(cb.head, 1); // Head should have moved
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
