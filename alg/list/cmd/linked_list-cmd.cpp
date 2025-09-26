#include "../linked_list.h"
#include <iostream>
#include <limits>

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
