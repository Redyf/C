#include <stdbool.h>
#include <stdio.h>

bool buscaArrayNaMatriz(int matriz[][5], int array[][2]) {
  for (int i = 0; i <= 5 - 2; i++) {
    for (int j = 0; j <= 5 - 2; j++) {
      bool encontrou = true;
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          if (matriz[i + k][j + l] != array[k][l]) {
            encontrou = false;
            break;
          }
        }
        if (!encontrou) {
          break;
        }
      }
      if (encontrou) {
        return true;
      }
    }
  }
  return false;
}

void imprimirDiagonalPrincipal(int matriz[][5]) {
  printf("Elementos da diagonal principal:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", matriz[i][i]);
  }
  printf("\n");
}

void imprimirDiagonalSecundaria(int matriz[][5]) {
  printf("Elementos da diagonal secundária:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", matriz[i][4 - i]);
  }
  printf("\n");
}

int main() {
  int matriz[][5] = {{1, 3, 4, 7, 4},
                     {1, 0, 1, 3, 9},
                     {9, 3, 2, 1, 0},
                     {10, 11, 14, 3, 1},
                     {0, 0, 1, 1, 0}};

  int array[][2] = {{2, 1}, {14, 3}};

  if (buscaArrayNaMatriz(matriz, array)) {
    printf("Array encontrada na matriz\n");
  } else {
    printf("Array não encontrada na matriz\n");
  }

  imprimirDiagonalPrincipal(matriz);
  imprimirDiagonalSecundaria(matriz);

  return 0;
}
