#include <stdio.h>

#define MAX_LINHAS 3
#define MAX_COLUNAS 3

void somaMatrizes(int matrizA[][MAX_COLUNAS], int matrizB[][MAX_COLUNAS],
                  int matrizSoma[][MAX_COLUNAS]) {
  int i, j;

  for (i = 0; i < MAX_LINHAS; i++) {
    for (j = 0; j < MAX_COLUNAS; j++) {
      matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }
}

void imprimirMatriz(int matriz[][MAX_COLUNAS]) {
  int i, j;

  for (i = 0; i < MAX_LINHAS; i++) {
    for (j = 0; j < MAX_COLUNAS; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int matrizA[MAX_LINHAS][MAX_COLUNAS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrizB[MAX_LINHAS][MAX_COLUNAS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int matrizSoma[MAX_LINHAS][MAX_COLUNAS];

  somaMatrizes(matrizA, matrizB, matrizSoma);

  printf("Matriz A:\n");
  imprimirMatriz(matrizA);

  printf("Matriz B:\n");
  imprimirMatriz(matrizB);

  printf("Matriz Soma:\n");
  imprimirMatriz(matrizSoma);

  return 0;
}
