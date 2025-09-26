#include "tree.h"
#include <iostream>

int main() {
    No3* raiz = plant_tree((char*)"raiz");
    raiz->esquerda = plant_tree((char*)"esq");
    raiz->meio = plant_tree((char*)"meio");
    raiz->direita = plant_tree((char*)"dir");

    std::cout << "Total de nós: " << Sum(raiz) << std::endl;

    return 0;
}
