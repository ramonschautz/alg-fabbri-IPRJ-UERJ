// rfabbri 2024
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>

#define MAX_CARACTERES 64
#define TAMANHO_BUFFER 5

// -------- LISTA SIMPLES DINÂMICA --------
struct NoSimples {
    char name[MAX_CARACTERES];
    NoSimples *next;
};
typedef NoSimples* ListaSimples;

void inserirSimples(ListaSimples *lista, int pos, const char *nome);
void deletarSimples(ListaSimples *lista, int pos);
void imprimirSimples(ListaSimples lista);

// -------- LISTA DUPLAMENTE DINÂMICA --------
struct NoDuplo {
    char name[MAX_CARACTERES];
    NoDuplo *prev;
    NoDuplo *next;
};
typedef NoDuplo* ListaDupla;

void inserirDupla(ListaDupla *lista, int pos, const char *nome);
void deletarDupla(ListaDupla *lista, int pos);
void imprimirDupla(ListaDupla lista);

// -------- BUFFER CIRCULAR --------
struct BufferCircular {
    char buffer[TAMANHO_BUFFER][MAX_CARACTERES];
    int head;
    int tail;
    int count;
};

void inicializarCircular(BufferCircular *cb);
void inserirCircular(BufferCircular *cb, const char *nome);
void deletarCircular(BufferCircular *cb);
void imprimirCircular(const BufferCircular *cb);

#endif // LINKED_LIST_H
