/* R. Fabbri, 2024 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

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


// -------- MAIN --------
int main() {
    ListaSimples listaSimples = NULL;
    ListaDupla listaDupla = NULL;
    BufferCircular bufferCircular;
    inicializarCircular(&bufferCircular);

    int tipo, opcao, pos;
    char nome[MAX_CARACTERES];

    while (true) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1 - Lista Simples\n";
        std::cout << "2 - Lista Dupla\n";
        std::cout << "3 - Buffer Circular\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> tipo;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Por favor, insira um número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (tipo == 0) break;

        if (tipo < 1 || tipo > 3) {
            std::cout << "Opção inválida!\n";
            continue;
        }

        std::cout << "\n--- MENU OPERACOES ---\n";
        std::cout << "1 - Inserir\n";
        std::cout << "2 - Deletar\n";
        std::cout << "3 - Imprimir\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Por favor, insira um número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (opcao == 0) continue;

        switch (tipo) {
            case 1: // Lista simples
                if (opcao == 1) {
                    std::cout << "Digite o nome: ";
                    std::cin >> nome;
                    std::cout << "Digite a posição: ";
                    std::cin >> pos;
                    inserirSimples(&listaSimples, pos, nome);
                } else if (opcao == 2) {
                    std::cout << "Digite a posição: ";
                    std::cin >> pos;
                    deletarSimples(&listaSimples, pos);
                } else if (opcao == 3) {
                    imprimirSimples(listaSimples);
                }
                break;

            case 2: // Lista dupla
                if (opcao == 1) {
                    std::cout << "Digite o nome: ";
                    std::cin >> nome;
                    std::cout << "Digite a posição: ";
                    std::cin >> pos;
                    inserirDupla(&listaDupla, pos, nome);
                } else if (opcao == 2) {
                    std::cout << "Digite a posição: ";
                    std::cin >> pos;
                    deletarDupla(&listaDupla, pos);
                } else if (opcao == 3) {
                    imprimirDupla(listaDupla);
                }
                break;
            
            case 3: // Buffer Circular
                if (opcao == 1) {
                    std::cout << "Digite o nome: ";
                    std::cin >> nome;
                    inserirCircular(&bufferCircular, nome);
                } else if (opcao == 2) {
                    deletarCircular(&bufferCircular);
                } else if (opcao == 3) {
                    imprimirCircular(&bufferCircular);
                }
                break;

            default:
                std::cout << "Opção inválida!\n";
        }
    }

    return 0;
}


// -------- IMPLEMENTAÇÕES --------

// ---- LISTA SIMPLES ----
void inserirSimples(ListaSimples *lista, int pos, const char *nome) {
    NoSimples *novo = (NoSimples*) malloc(sizeof(NoSimples));
    strncpy(novo->name, nome, MAX_CARACTERES);
    novo->name[MAX_CARACTERES - 1] = '\0';
    novo->next = NULL;

    if (pos == 0 || *lista == NULL) {
        novo->next = *lista;
        *lista = novo;
        return;
    }

    NoSimples *atual = *lista;
    for (int i = 0; i < pos - 1 && atual->next != NULL; i++) {
        atual = atual->next;
    }
    novo->next = atual->next;
    atual->next = novo;
}

void deletarSimples(ListaSimples *lista, int pos) {
    if (*lista == NULL) {
        std::cout << "Lista vazia!\n";
        return;
    }

    NoSimples *remover;
    if (pos == 0) {
        remover = *lista;
        *lista = (*lista)->next;
        free(remover);
        return;
    }

    NoSimples *atual = *lista;
    for (int i = 0; i < pos - 1 && atual->next != NULL; i++) {
        atual = atual->next;
    }

    if (atual->next == NULL) {
        std::cout << "Posição inválida!\n";
        return;
    }

    remover = atual->next;
    atual->next = remover->next;
    free(remover);
}

void imprimirSimples(ListaSimples lista) {
    std::cout << "Lista simples: ";
    while (lista != NULL) {
        std::cout << lista->name << " ";
        lista = lista->next;
    }
    std::cout << "\n";
}

// ---- LISTA DUPLA ----
void inserirDupla(ListaDupla *lista, int pos, const char *nome) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    strncpy(novo->name, nome, MAX_CARACTERES);
    novo->name[MAX_CARACTERES - 1] = '\0';
    novo->next = NULL;
    novo->prev = NULL;

    if (pos == 0 || *lista == NULL) {
        novo->next = *lista;
        if (*lista != NULL) (*lista)->prev = novo;
        *lista = novo;
        return;
    }

    NoDuplo *atual = *lista;
    for (int i = 0; i < pos - 1 && atual->next != NULL; i++) {
        atual = atual->next;
    }

    novo->next = atual->next;
    novo->prev = atual;
    if (atual->next != NULL) {
        atual->next->prev = novo;
    }
    atual->next = novo;
}

void deletarDupla(ListaDupla *lista, int pos) {
    if (*lista == NULL) {
        std::cout << "Lista vazia!\n";
        return;
    }

    NoDuplo *remover = *lista;
    if (pos == 0) {
        *lista = remover->next;
        if (*lista != NULL) (*lista)->prev = NULL;
        free(remover);
        return;
    }

    for (int i = 0; i < pos && remover != NULL; i++) {
        remover = remover->next;
    }

    if (remover == NULL) {
        std::cout << "Posição inválida!\n";
        return;
    }

    if (remover->prev != NULL) remover->prev->next = remover->next;
    if (remover->next != NULL) remover->next->prev = remover->prev;

    free(remover);
}

void imprimirDupla(ListaDupla lista) {
    std::cout << "Lista dupla: ";
    while (lista != NULL) {
        std::cout << lista->name << " ";
        lista = lista->next;
    }
    std::cout << "\n";
}

// ---- BUFFER CIRCULAR ----
void inicializarCircular(BufferCircular *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

void inserirCircular(BufferCircular *cb, const char *nome) {
    if (cb->count == TAMANHO_BUFFER) {
        std::cout << "Buffer cheio! Sobrescrevendo o elemento mais antigo.\n";
        cb->head = (cb->head + 1) % TAMANHO_BUFFER; // Move head, effectively removing the oldest element
    } else {
        cb->count++;
    }
    strncpy(cb->buffer[cb->tail], nome, MAX_CARACTERES);
    cb->buffer[cb->tail][MAX_CARACTERES - 1] = '\0';
    cb->tail = (cb->tail + 1) % TAMANHO_BUFFER;
}

void deletarCircular(BufferCircular *cb) {
    if (cb->count == 0) {
        std::cout << "Buffer vazio!\n";
        return;
    }
    std::cout << "Elemento removido: " << cb->buffer[cb->head] << "\n";
    cb->head = (cb->head + 1) % TAMANHO_BUFFER;
    cb->count--;
}

void imprimirCircular(const BufferCircular *cb) {
    if (cb->count == 0) {
        std::cout << "Buffer vazio!\n";
        return;
    }
    std::cout << "Buffer circular: ";
    int current = cb->head;
    for (int i = 0; i < cb->count; i++) {
        std::cout << cb->buffer[current] << " ";
        current = (current + 1) % TAMANHO_BUFFER;
    }
    std::cout << "\n";
}
