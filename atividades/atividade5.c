#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

// Função para ordenar os elementos em ordem crescente
void ordenarMatriz(int matriz[LINHAS][COLUNAS], int totalElementos) {
  int vetor[totalElementos];
  int k = 0;

  // Copia todos os elementos da matriz para o vetor
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      vetor[k] = matriz[i][j];
      k++;
    }
  }

  // Ordena o vetor em ordem crescente
  for (int i = 0; i < totalElementos - 1; i++) {
    for (int j = 0; j < totalElementos - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }

  // Imprime os elementos ordenados
  printf("\nElementos em ordem crescente:\n");
  for (int i = 0; i < totalElementos; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int matriz[LINHAS][COLUNAS];

  // Lê os elementos da matriz
  printf("Digite os elementos da matriz %d x %d:\n", LINHAS, COLUNAS);
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Imprime a matriz
  printf("\nMatriz digitada:\n");
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // Chama a função para ordenar e imprimir os elementos em ordem crescente
  ordenarMatriz(matriz, LINHAS * COLUNAS);

  return 0;
}
