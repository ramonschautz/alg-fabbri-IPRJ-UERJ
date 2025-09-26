#include "gtest/gtest.h"
#include "tree.h"

TEST(TreeTest, Sum) {
    No3* raiz = plant_tree((char*)"raiz");
    raiz->esquerda = plant_tree((char*)"esq");
    raiz->meio = plant_tree((char*)"meio");
    raiz->direita = plant_tree((char*)"dir");
    EXPECT_EQ(Sum(raiz), 4);
}
