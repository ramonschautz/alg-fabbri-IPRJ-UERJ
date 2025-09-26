#include "tree.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

No3* plant_tree(char *str) {
	No3* novo = (No3*) std::malloc(sizeof(No3));
	if (!novo) return nullptr;

	novo->str =strdup(str);
	
	novo->esquerda = nullptr;
	novo->meio = nullptr;
	novo->direita = nullptr;

	return novo;
}

int Sum(No3 *p){
	if(p == nullptr) return 0;
	return 1 + Sum(p->esquerda) + Sum(p->meio) + Sum(p->direita);
}

