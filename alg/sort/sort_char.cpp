// rfabbri 2025-09-25
#include "sort_char.h"
#include <string.h> // For memset

#define NUM_CHARS 256

/*
  Para ordenar caracteres, o algoritmo mais rápido não é baseado em comparações
  como o Quicksort. Um algoritmo de ordenação por contagem (Counting Sort)
  é muito mais eficiente para este caso.

  A complexidade é O(n + k) onde n é o número de elementos e k é o número
  de valores possíveis (256 para char). Isso é mais rápido que o Quicksort,
  que tem complexidade média de O(n log n).

  Esta implementação é "in-place" (não usa um buffer auxiliar significativo)
  e é otimizada para a ordenação de caracteres.
*/
void
sort_char(char *v, int n)
{
  if (n <= 1)
    return;

  // Array para contar a ocorrência de cada caracter.
  int count[NUM_CHARS];
  memset(count, 0, sizeof(count));

  // Conta a frequência de cada caracter no vetor de entrada.
  // É importante fazer o cast para 'unsigned char' para garantir que o valor
  // seja um índice válido (0-255), independentemente se 'char' é signed ou unsigned.
  for (int i = 0; i < n; i++) {
    count[(unsigned char)v[i]]++;
  }

  // Reescreve o vetor original 'v' com os caracteres ordenados.
  int current_pos = 0;
  for (int i = 0; i < NUM_CHARS; i++) {
    for (int j = 0; j < count[i]; j++) {
      v[current_pos++] = (char)i;
    }
  }
}
