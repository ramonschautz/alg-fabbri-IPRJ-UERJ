/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdlib>
#include <cstring>
#include <iostream>


#define MAX_CARACTERES 64
struct No{
	char name[MAX_CARACTERES];
	No *next;
};

typedef No *Lista;

void playground_lista()
{
	Lista l;
	l = (No * ) malloc(sizeof(No));
	l->name[0] = '\0';
	std::cout << std::string(l->name) << std::endl;
	std::cout << "teste \n" << std::endl;
	printf("%s",l->name);
	strncpy(l->name, "joao \n", MAX_CARACTERES);
	printf("%s",l->name);
	
}
struct No2{
	char *name;
	No2 *next;
};

typedef No2 *Lista2;

void playground_lista2()
{
	Lista2 l;
	l = (No2 * ) malloc(sizeof(No2));
	l->name = "";
	printf("%s",l->name);
	l->name = "ramon. \n";
	printf("%s",l->name);
}
