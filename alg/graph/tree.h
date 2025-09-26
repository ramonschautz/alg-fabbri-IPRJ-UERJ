#ifndef TREE_H
#define TREE_H

struct No3{
	char *str;

	No3 *esquerda;
	No3 *meio;
	No3 *direita;
};

No3* plant_tree (char *str);
int Sum(No3 *p);

#endif // TREE_H
